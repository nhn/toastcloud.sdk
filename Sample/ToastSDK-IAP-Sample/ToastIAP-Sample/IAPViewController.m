//
//  ViewController.m
//  ToastIAP-Sample
//
//  Created by NHN on 2018. 11. 9..
//  Copyright © 2018년 NHN. All rights reserved.
//

#import "IAPViewController.h"
#import <ToastCore/ToastCore.h>
#import <ToastIAP/ToastIAP.h>

#define TOAST_IAP_APP_KEY @"Input your App Key"
#define TOAST_IAP_DEFAULT_USER_ID @"ToastIAP-Test-User"

typedef NS_ENUM(NSUInteger, ToastIAPProductListType) {
    ListType_Products,
    ListType_Purchases,
};

@interface IAPViewController () <ToastInAppPurchaseDelegate, UITableViewDelegate, UITableViewDataSource>

@end

@implementation IAPViewController {
    BOOL isLogined;
    NSArray<ToastProduct *> *products;
    NSArray<ToastPurchaseResult *> *purchaseResults;
}

- (void) touchesBegan:(NSSet *)touches withEvent:(UIEvent *)event {
    [[self view] endEditing:YES];
}

- (void)viewDidLoad {
    [super viewDidLoad];
    
    isLogined = false;
    
    self.tableView.delegate = self;
    self.tableView.dataSource = self;
    self.tableView.rowHeight = UITableViewAutomaticDimension;
    
    [ToastSDK setDebugMode:true];
}

#pragma mark - button actions

- (IBAction)initOrLogoutDidTap:(id)sender {
    
    if (isLogined) {
        [self logoutDidTap];
    } else {
        [self loginDidTap];
    }
}

/// 구매 복원
/// AppStore 자동갱신형 구독 상품의 Transaction을 복원하고 활성화되어 있는 구독 상품의 목록을 반환합니다.
- (IBAction)restoreDidTap:(id)sender {
    
    if (isLogined == false) {
        [self alertMessage:@"초기화 후 사용해주세요."];
        return;
    }
    [self showActivityIndicator];
    
    [ToastIAP restoreWithCompletionHandler:^(NSArray<ToastPurchaseResult *> * _Nullable purchases, NSError * _Nullable error) {
        if (error == nil) {
            NSLog(@" - restore Success -");
            NSLog(@"purchases : %@", purchases);
            NSLog(@" - ----------------------- -\n ");
            
            NSMutableString *message = [@"" mutableCopy];
            
            for (ToastPurchaseResult *purchase in purchases) {
                [message appendString:@"---------------------------------\n"];
                [message appendString: [purchase description]];
                [message appendString:@"\n---------------------------------\n"];
            }
            
            if (purchases.count != 0) {
                [self alertMessage: [NSString stringWithFormat:@"복원이 성공적으로 성공하였습니다.\n%@", message]];
            } else {
                [self alertMessage:@"복원할 아이템이 없습니다."];
            }
            
            
        } else {
            NSLog(@" - restore Error : %@", error);
            
            [self alertMessage: @"복원이 실패하였습니다. 다시 시도해주세요."];
        }
        
        [self hideActivityIndicator];
    }];
}

- (IBAction)listSegmentDidChange:(id)sender {
    if (isLogined == false) {
        [self alertMessage:@"초기화 후 사용해주세요."];
        return;
    }
    
    if (self.listSegmentedControl.selectedSegmentIndex == ListType_Products) { // 아이템 목록
        [self requestProducts];
    } else {
        [self requestConsumablePurchases];
    }
}

- (void)loginDidTap {
    
    UIAlertController *alert= [UIAlertController
                               alertControllerWithTitle:@"로그인"
                               message:nil
                               preferredStyle:UIAlertControllerStyleAlert];
    
    UIAlertAction* okAction = [UIAlertAction actionWithTitle:@"확인" style:UIAlertActionStyleDefault
                                               handler:^(UIAlertAction * action){
                                                   
                                                   UITextField *textField = alert.textFields[0];
                                                   if (textField.text == nil || textField.text.length == 0) {
                                                       [self alertMessage:@"아이디를 입력해주세요."];
                                                   } else {
                                                       [self loginDidSuccess:textField.text];
                                                   }
                                               }];
    
    UIAlertAction* cancelAction = [UIAlertAction actionWithTitle:@"취소" style:UIAlertActionStyleDefault
                                                   handler:^(UIAlertAction * action) {
                                                       [alert dismissViewControllerAnimated:YES completion:nil];
                                                       [self loginDidCancel];
                                                   }];
    
    [alert addAction:okAction];
    [alert addAction:cancelAction];
    
    [alert addTextFieldWithConfigurationHandler:^(UITextField *textField) {
        textField.placeholder = @"User ID";
        
#ifdef TOAST_IAP_DEFAULT_USER_ID
        [textField setText:TOAST_IAP_DEFAULT_USER_ID];
#endif
        textField.keyboardType = UIKeyboardTypeDefault;
    }];
    
    [self presentViewController:alert animated:YES completion:nil];
}

- (void)logoutDidTap {
    UIAlertController *alert= [UIAlertController
                               alertControllerWithTitle:@"로그아웃"
                               message:nil
                               preferredStyle:UIAlertControllerStyleAlert];
    
    UIAlertAction* okAction = [UIAlertAction actionWithTitle:@"확인" style:UIAlertActionStyleDefault
                                               handler:^(UIAlertAction * action){
                                                   
                                                   [self logoutDidSuccess];
                                               }];
    UIAlertAction* cancelAction = [UIAlertAction actionWithTitle:@"취소" style:UIAlertActionStyleDefault
                                                   handler:^(UIAlertAction * action) {
                                                       [alert dismissViewControllerAnimated:YES completion:nil];
                                                       [self logoutDidCancel];
                                                       
                                                   }];
    
    [alert addAction:okAction];
    [alert addAction:cancelAction];
    dispatch_async(dispatch_get_main_queue(), ^{
        [self presentViewController:alert animated:YES completion:nil];
    });
    
}


#pragma mark - Callbacks about login & logout

- (void)loginDidSuccess:(NSString *)userID {
    
    [ToastSDK setUserID:userID];
    
    ToastIAPConfiguration *config = [ToastIAPConfiguration configurationWithAppKey:TOAST_IAP_APP_KEY];
    [ToastIAP setDelegate:self];
    [ToastIAP initWithConfiguration:config];
    
    [self requestActivePurchases];
    
    if (self.listSegmentedControl.selectedSegmentIndex == ListType_Products) { // 아이템 목록
        [self requestProducts];
    } else {
        [self requestConsumablePurchases];
    }
    
    [self.userIDField setText:userID];
    
    isLogined = true;
    [self.initializeButton setTitle:@"로그아웃" forState:UIControlStateNormal];
}

- (void)loginDidCancel {
    NSLog(@"사용자가 로그인을 취소하였습니다.");
}

- (void)logoutDidSuccess {
    
    [ToastSDK setUserID:nil];
    [ToastSDK setDebugMode:false];
    
    dispatch_async(dispatch_get_main_queue(), ^{
        [self.activePurchasesTextArea setText:@"nil"];
        [self.userIDField setText:@"nil"];
        
        self->products = nil;
        self->purchaseResults = nil;
        [self.tableView reloadData];
    });

    isLogined = false;
    [self.initializeButton setTitle:@"초기화" forState:UIControlStateNormal];
}

- (void)logoutDidCancel {
    NSLog(@"사용자가 로그아웃을 취소하였습니다.");
}

# pragma mark - IAP Methods

/// 아이템 목록 조회
/// IAP Console에 등록된 상품 목록을 조회합니다.
- (void)requestProducts {
    
    [self showActivityIndicator];
    
    [ToastIAP requestProductsWithCompletionHandler:^(ToastProductsResponse * _Nullable response,
                                                     NSError * _Nullable error)
     {
         if(error == nil) {
             NSLog(@" - requestProducts Success -");
             NSLog(@"response : %@", response);
             NSLog(@" - ----------------------- -\n ");
             
             self->products = [[response products] copy];
             
             dispatch_async(dispatch_get_main_queue(), ^{
                 [self->_tableView reloadData];
             });
         }else {
             NSLog(@" - reqeusetProducts Error : %@", error);
         }
         
         [self hideActivityIndicator];
     }];
}

/// 소모성 상품 결제완료 목록 조회
/// 구입한 소모성 상품 중 지급되지 않은 상품의 목록을 조회
- (void)requestConsumablePurchases {
    
    [self showActivityIndicator];
    
    [ToastIAP requestConsumablePurchasesWithCompletionHandler:^(NSArray<ToastPurchaseResult *> * _Nullable results, NSError * _Nullable error) {
        dispatch_async(dispatch_get_main_queue(), ^{
            if(error == nil) {
                self->purchaseResults = [results copy];
                [self->_tableView reloadData];
            }else {
                NSLog(@" - requestConsumablePurchases Error : %@", error);
            }
            
            [self hideActivityIndicator];
        });
    }];
    
}

/// 구독중인 상품 목록
/// UserID 기준의 유효한 구독 상품의 목록을 반환합니다.(iOS, Android의 Store구분 없이)
- (void)requestActivePurchases {
    
    [ToastIAP requestActivePurchasesWithCompletionHandler:^(NSArray<ToastPurchaseResult *> * _Nullable purchases, NSError * _Nullable error) {
        
        if (error == nil) {
            NSLog(@" - requestActivePurchases Success -");
            NSLog(@"purchases : %@", purchases);
            NSLog(@" - ----------------------- -\n ");
            
            dispatch_async(dispatch_get_main_queue(), ^{
                if (purchases.count == 0) {
                    self.activePurchasesTextArea.text = @"nil";
                } else {
                    NSMutableString *desc = [NSMutableString string];
                    for (ToastPurchaseResult * purchase in purchases) {
                        [desc appendString:@"-----------------------------------------------------\n"];
                        [desc appendString: [NSString stringWithFormat:@"%@\n", purchase.productIdentifier]];
                        [desc appendString: [NSString stringWithFormat:@"[price] %@\n[transactionID] %@\n[paymentSeq] %@\n[purchaseTime] %@\n", purchase.price, purchase.transactionIdentifier, purchase.paymentSeq, [NSDate dateWithTimeIntervalSince1970:purchase.purchaseTime / 1000] ]];
                        [desc appendString:@"-----------------------------------------------------\n"];
                    }
                    
                    self.activePurchasesTextArea.text = desc;
                }
            });
        } else {
            NSLog(@" - requestActivePurchases Error : %@", error);
        }
    }];
}

#pragma mark - IAP Delegates

// 결제 성공
- (void)didReceivePurchaseResult:(ToastPurchaseResult *)purchase {
    [self requestActivePurchases];
}
// 결제 실패
- (void)didFailPurchaseProduct:(NSString *)productIdentifier withError:(NSError *)error {
    NSLog(@"결제 실패 - error : %@", error.description);
}

#pragma mark - TableView DataSources

- (NSInteger)numberOfSectionsInTableView:(UITableView *)tableView {
    return 1;
}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {
    
    if (self.listSegmentedControl.selectedSegmentIndex == ListType_Products) { // 아이템 목록
        return products.count;
    } else { // 소모성 상품 결제완료 목록
        return purchaseResults.count;
    }
}

#pragma mark - Tableview Delegates

- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath
{

    NSString *message = @"";
    UIAlertAction* okAction = nil;
    
    if (self.listSegmentedControl.selectedSegmentIndex == ListType_Products) { // 아이템 목록
        
        message = [[products objectAtIndex:indexPath.row] description];
        okAction = [UIAlertAction actionWithTitle:@"구매" style:UIAlertActionStyleDefault
                                                   handler:^(UIAlertAction * action){
                                                       [ToastIAP purchaseWithProduct:[self->products objectAtIndex:indexPath.row]];
                                                   }];
    } else { // 소모성 상품 결제완료 목록
        
        message = [[purchaseResults objectAtIndex:indexPath.row] description];
        okAction = [UIAlertAction actionWithTitle:@"소비" style:UIAlertActionStyleDefault
                                                   handler:^(UIAlertAction * action){
                                                       [ToastIAP consumeWithPurchaseResult:[self->purchaseResults objectAtIndex:indexPath.row]
                                                                         completionHandler:^(NSError * _Nonnull error) {
                                                                             if (error == nil) {
                                                                                 NSLog(@"- Consume Success -");
                                                                                 NSLog(@"%@", message);
                                                                                 
                                                                                 [self alertMessage:@"소비가 정상적으로 완료되었습니다." withOKHandler:^(void) {
                                                                                     [self requestConsumablePurchases];
                                                                                 }];
                                                                             } else {
                                                                                 NSLog(@" - Consume Fail : %@", error.localizedDescription);
                                                                                 
                                                                                 [self alertMessage:@"소비가 실패하였습니다. 다시 시도해주세요."];
                                                                             }
                                                                         }];
                                                   }];
    }
    
    UIAlertController *alert= [UIAlertController
                               alertControllerWithTitle:@"아이템정보"
                               message:message
                               preferredStyle:UIAlertControllerStyleAlert];
    
    UIAlertAction* cancelAction = [UIAlertAction actionWithTitle:@"취소" style:UIAlertActionStyleDefault
                                                   handler:^(UIAlertAction * action) {
                                                       [alert dismissViewControllerAnimated:YES completion:nil];
                                                   }];
    
    [alert addAction:okAction];
    [alert addAction:cancelAction];
    dispatch_async(dispatch_get_main_queue(), ^{
        [self presentViewController:alert animated:YES completion:nil];
    });
    
}


- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath {
    
    UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:@"myCell" forIndexPath:indexPath];
    
    static NSString *(^getProductNameWithType)(NSInteger productType) = ^(NSInteger productType) {
        switch (productType) {
            case ToastProductTypeUnknown:
                return @"...";
            case ToastProductTypeConsumable:
                return @"소모성";
            case ToastProductTypeAutoRenewableSubscription:
                return @"구독";
            default:
                return @"...";
        }
    };
    
    if (self.listSegmentedControl.selectedSegmentIndex == ListType_Products) { // 아이템 목록
        ToastProduct *product = products[indexPath.row];
        cell.textLabel.text = [NSString stringWithFormat:@"[%@] %@", getProductNameWithType(product.productType), product.productName];
        cell.detailTextLabel.text = [NSString stringWithFormat:@"%@\n%@", product.productIdentifier, product.localizedPrice];
        
    } else { // 소모성 상품 결제완료 목록
        ToastPurchaseResult *purchase = purchaseResults[indexPath.row];
        cell.textLabel.text = [NSString stringWithFormat:@"%@", purchase.productIdentifier];
        cell.detailTextLabel.text = [NSString stringWithFormat:@"[price] %@\n[transactionID] %@\n[paymentSeq] %@\n[purchaseTime] %@", purchase.price, purchase.transactionIdentifier, purchase.paymentSeq, [NSDate dateWithTimeIntervalSince1970:purchase.purchaseTime / 1000] ];
    }

    return  cell;
}



#pragma mark - Utils

- (void)alertMessage:(NSString *)message {
    UIAlertController *alert= [UIAlertController
                               alertControllerWithTitle:@"알림"
                               message:message
                               preferredStyle:UIAlertControllerStyleAlert];
    
    UIAlertAction* okAction = [UIAlertAction actionWithTitle:@"확인" style:UIAlertActionStyleDefault
                                               handler:^(UIAlertAction * action){
                                                   
                                               }];
    [alert addAction:okAction];
    
    dispatch_async(dispatch_get_main_queue(), ^{
        [self presentViewController:alert animated:YES completion:nil];
    });
}

- (void)alertMessage:(NSString *)message withOKHandler:(void(^)(void))handler{
    UIAlertController *alert= [UIAlertController
                               alertControllerWithTitle:@"알림"
                               message:message
                               preferredStyle:UIAlertControllerStyleAlert];
    
    UIAlertAction* okAction = [UIAlertAction actionWithTitle:@"확인" style:UIAlertActionStyleDefault
                                               handler:^(UIAlertAction * action){
                                                   if (handler) {
                                                       handler();
                                                   }
                                               }];

    [alert addAction:okAction];
    dispatch_async(dispatch_get_main_queue(), ^{
        [self presentViewController:alert animated:YES completion:nil];
    });
    
}

- (void)showActivityIndicator {
    
    dispatch_async(dispatch_get_main_queue(), ^{
        self.activityIndicator = [[UIActivityIndicatorView alloc] initWithFrame:CGRectMake(0, 0, self.view.frame.size.width, self.view.frame.size.height)];
        [self.activityIndicator setCenter:self.view.center];
        [self.activityIndicator setActivityIndicatorViewStyle:UIActivityIndicatorViewStyleGray];
        [self.view addSubview : self.activityIndicator];
        self.activityIndicator.hidden = FALSE;
        [self.activityIndicator startAnimating];
    });
}

- (void)hideActivityIndicator {
    
    dispatch_async(dispatch_get_main_queue(), ^{
        [self.activityIndicator stopAnimating];
        self.activityIndicator.hidden = TRUE;
        [self.view willRemoveSubview:self.activityIndicator];
    });
}

@end
