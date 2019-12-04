//
//  ViewController.m
//  ToastSDK-Push-Sample
//
//  Created by NHN on 2018. 12. 28..
//  Copyright © 2018년 NHN. All rights reserved.
//

/**
 샘플앱 빌드 시 수정해야 하는 항목
 
 ## Required
 - 25line : ToastPushAppKey
 - Sample앱의 plist에서 ToastSDK > ToastPush > AppKey
 - ServiceExtension의 plist에서 ToastSDK > ToastPush > AppKey
 
 ## Optional
 - 26line : ToastUserID
 **/

#import "PushViewController.h"
#import <ToastCore/ToastCore.h>
#import <ToastPush/ToastPush.h>

static NSString *const ToastPushAppKey  = @"Please input your app key here.";
static NSString *const ToastUserID      = @"sample-app-test-user";


@interface PushViewController () <ToastPushDelegate>

// ToastPush에 등록할 푸시 타입(viewDidLoad:에서 정의)
@property (nonatomic, strong) NSSet<ToastPushType> *pushTypes;

@property (nonatomic, assign) BOOL isLogined;

@end

@implementation PushViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    // 앱을 릴리스할 경우, 반드시 디버그 모드를 비활성화해야합니다.
    [ToastSDK setDebugMode:YES];
    
    self.isLogined  = NO;
    
    // 원하는 등록 타입으로 변경 후 사용
    self.pushTypes  = [NSSet setWithArray:@[ToastPushTypeAPNS, ToastPushTypeVoIP]];
    self.userIdTextField.text = ToastUserID;
    
    [self loadNotificationAgreement];
    [self makeBorderedButton];
}

- (void)makeBorderedButton {
    self.registrationButton.layer.borderColor = [UIColor blueColor].CGColor;
    self.registrationButton.layer.borderWidth = 1;
    self.registrationButton.layer.cornerRadius = 10;
    
    self.queryButton.layer.borderColor = [UIColor blueColor].CGColor;
    self.queryButton.layer.borderWidth = 1;
    self.queryButton.layer.cornerRadius = 10;
}


#pragma mark - Buttons & Segment Event

- (IBAction)mainViewDidTap:(id)sender {
    [self.view endEditing:YES];
}

- (IBAction)loginOrLogoutButtonDidTap:(id)sender {
    
    if (self.isLogined) {
        [self logoutedAction];

    } else {
        NSString *userId = self.userIdTextField.text;
        if (userId == nil || [@"" isEqualToString:userId]) {
            [self showAlertWithTitle:@"알림" message:@"아이디를 입력해주세요."];
            return;
        }
        
        [self loginedAction];
    }
    
    self.isLogined = !self.isLogined;
}

- (void)loginedAction {
    // 서비스 로그인 완료 후 사용자 ID 설정
    [ToastSDK setUserID:self.userIdTextField.text];
    
    ToastPushConfiguration *configuration = [[ToastPushConfiguration alloc] initWithAppKey:ToastPushAppKey];
    // 개발환경(Debug)에서는 꼭 아래 sandbox 프로퍼티를 YES로 설정해야만 개발 인증서로 등록됩니다.
#if DEBUG
    configuration.sandbox = YES;
#endif
    
    // ToastPush 초기화 및 delegate를 설정합니다.
    // AppDelegate의 application:didFinishLaunchingWithOptions: 에서 초기화하는 것이 좋습니다.
    [ToastPush initWithConfiguration:configuration delegate:self];
    [self.loginOrLogoutButton setTitle:@"Logout" forState:UIControlStateNormal];
}

- (void)logoutedAction {
    // 서비스 로그아웃 완료 후 사용자 ID를 nil로 설정
    [ToastSDK setUserID:nil];
    [self.loginOrLogoutButton setTitle:@"Login" forState:UIControlStateNormal];
}

- (IBAction)registrationButtonDidTap:(id)sender {
    ToastPushAgreement *agreement = [[ToastPushAgreement alloc] init];
    // 알림 표시 동의 여부
    agreement.allowNotifications = self.pushSwitch.isOn;
    // 광고성 알림 표시 동의 여부
    agreement.allowAdvertisements = self.adSwitch.isOn;
    // 야간 광고성 알림 동의 여부
    agreement.allowNightAdvertisements = self.nightAdSwitch.isOn;
    // 토큰 등록
    [ToastPush registerWithAgreement:agreement
                   completionHandler:^(ToastPushTokenInfo *tokenInfo, NSError *error) {
        
        if (error == nil) {
            NSLog(@"[ToastPush] Succesully registered : %@", tokenInfo.deviceToken);
            [self showAlertWithTitle:@"Success Registration" message:[NSString stringWithFormat:@"(APNS) token: %@", tokenInfo.deviceToken]];
            
        } else {
            NSLog(@"[ToastPush] Failed to register : %@", error);
            [self showAlertWithTitle:@"Failed Registration" message:[NSString stringWithFormat:@"(APNS) error: %@", error]];
        }
    }];
}

- (IBAction)queryButtonDidTap:(id)sender {
    // 토큰 조회
    [ToastPush queryTokenInfoWithCompletionHandler:^(ToastPushTokenInfo *tokenInfo, NSError *error) {
        if (error == nil) {
            NSLog(@"[ToastPush] Successfully get token info : %@", tokenInfo);
            [self showAlertWithTitle:@"Success query"
                             message:[NSString stringWithFormat:@"tokenInfo : %@", tokenInfo]];
            
            
        } else {
            NSLog(@"[ToastPush] Failed to get token info : %@", error);
            [self showAlertWithTitle:@"Failed query"
                             message:[NSString stringWithFormat:@"error : %@", error]];
        }
    }];
}

- (IBAction)togglePushSwitch:(id)sender {
    if (self.pushSwitch.on == true) {
        self.adSwitch.enabled       = true;
        self.nightAdSwitch.enabled  = true;
        self.adSwitch.on            = true;
        self.nightAdSwitch.on       = true;
        
    } else {
        self.adSwitch.enabled       = false;
        self.nightAdSwitch.enabled  = false;
        self.adSwitch.on            = false;
        self.nightAdSwitch.on       = false;
    }
    
    [self saveNotificationAgreement];
}

- (IBAction)toggleAdSwitch:(id)sender {
    [self saveNotificationAgreement];
}

- (IBAction)toggleNightAdSwitch:(id)sender {
    [self saveNotificationAgreement];
}


#pragma mark - Utils

- (void)showAlertWithTitle:(NSString *)title
                   message:(NSString *)message {
    
    dispatch_async(dispatch_get_main_queue(), ^{
        UIAlertView *alert = [[UIAlertView alloc] initWithTitle:title
                                                        message:message
                                                       delegate:nil
                                              cancelButtonTitle:@"OK"
                                              otherButtonTitles:nil];
        [alert show];
    });
}

- (void)requestLocalNotificationWithTitle:(NSString *)title
                                  message:(NSString *)message {
    
    dispatch_async(dispatch_get_main_queue(), ^{
        if (@available(iOS 10.0, *)) {
            UNMutableNotificationContent *local = [[UNMutableNotificationContent alloc] init];
            local.title = title;
            local.body = message;
            
            UNNotificationRequest *request = [UNNotificationRequest requestWithIdentifier:[[NSUUID UUID] UUIDString]
                                                                                  content:local
                                                                                  trigger:nil];
            
            UNUserNotificationCenter *center = [UNUserNotificationCenter currentNotificationCenter];
            [center addNotificationRequest:request withCompletionHandler:nil];
            
        } else {
            UILocalNotification *local = [[UILocalNotification alloc] init];
            
            if (@available(iOS 8.2, *)) {
                local.alertTitle = title;
            }
            
            local.alertBody = message;
            
            [[UIApplication sharedApplication] presentLocalNotificationNow:local];
        }
    });
}


#pragma mark - UserDefaults

- (void)saveNotificationAgreement {
    NSUserDefaults *userDefaults = [NSUserDefaults standardUserDefaults];
    
    [userDefaults setBool:self.pushSwitch.isOn forKey:@"ToastPushSamplePushSwitch"];
    [userDefaults setBool:self.adSwitch.isOn forKey:@"ToastPushSampleAdSwitch"];
    [userDefaults setBool:self.nightAdSwitch.isOn forKey:@"ToastPushSampleNightAdSwitch"];
    
    [userDefaults synchronize];
    
}

- (void)loadNotificationAgreement {
    NSUserDefaults *userDefaults = [NSUserDefaults standardUserDefaults];

    [self.pushSwitch    setOn:[userDefaults boolForKey:@"ToastPushSamplePushSwitch"]];
    [self.adSwitch      setOn:[userDefaults boolForKey:@"ToastPushSampleAdSwitch"]];
    [self.nightAdSwitch setOn:[userDefaults boolForKey:@"ToastPushSampleNightAdSwitch"]];
    
}

#pragma mark - ToastPushDelegate
// 메세지 수신
- (void)didReceiveNotificationWithMessage:(ToastPushMessage *)message {
    NSLog(@"[ToastPush] didReceiveNotificationWithMessage:%@", message);
    
    [self showAlertWithTitle:@"Received Notification Message"
                     message:[NSString stringWithFormat:@"%@", message.payload]];
}

- (void)didReceiveNotificationResponseWithMessage:(ToastPushMessage *)message {
    NSLog(@"[ToastPush] didReceiveNotificationResponseWithMessage:%@", message);
    
    [self showAlertWithTitle:@"Received Notification Response"
                     message:[NSString stringWithFormat:@"%@", message.payload]];
}

// 알림 액션(버튼) 수신
- (void)didReceiveNotificationAction:(ToastPushNotificationAction *)action {
    NSLog(@"[ToastPush] didReceiveNotificationAction:%@", action);
    
    [self showAlertWithTitle:@"Received Notification Action"
                     message:[NSString stringWithFormat:@"action: %@\ncategory: %@\npayload: %@\nuserText: %@\n", action.actionIdentifier, action.categoryIdentifier, action.message.payload, action.userText]];
    
    if (action.userText != nil) {
        [self requestLocalNotificationWithTitle:@"Received Text Action"
                                        message:[NSString stringWithFormat:@"Input : %@", action.userText]];
    }
}

@end

