//
//  ViewController.m
//  ToastCrashSample
//
//  Created by Hyup on 2018. 3. 13..
//  Copyright © 2018년 NHN Entertainment Corp. All rights reserved.
//

#import "ViewController.h"

#define APPKEY @"INPUT YOUT APP KEY"

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
    
    [self initToastCrash];
    [self setCrashUserInfo];
    [self setToastCrashDelegate];
}


- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (void)initToastCrash {
    
    NSString *appVersion = [[[NSBundle mainBundle] infoDictionary] objectForKey:@"CFBundleShortVersionString"];
        
    [TCISLogger setConfiguration:[TCISLoggerConfiguration configurationWithProjectKey:APPKEY projectVersion:appVersion]];

    [TCISCrash setConfigurationLogger:[TCISLogger instanceLogger]];
    
    
}

- (void)setCrashUserInfo {
    [TCISCrash setUserFieldIntoTCISCrashBlock:^{
        
        NSMutableDictionary *baseUserInfoDictionary = [[NSMutableDictionary alloc]init];
        
        [baseUserInfoDictionary setObject:@"baseValue"
                                   forKey:@"baseKey"];
        
        [TCISCrash setUserField:baseUserInfoDictionary];
        
        
        [TCISCrash  setUserFieldWithValue:self.userIDTextField.text
                                   forKey:@"TexxtField userIDTextField"];
        
        [TCISCrash  setUserFieldWithValue:self.userInfoKey1TextField.text
                                   forKey:@"TexxtField userInfoKey1TextField"];
        [TCISCrash  setUserFieldWithValue:self.userInfoValue1TextField.text
                                   forKey:@"TexxtField userInfoValue1TextField"];
        
        [TCISCrash  setUserFieldWithValue:self.userInfoKey2TextField.text
                                   forKey:@"TexxtField userInfoKey2TextField"];
        [TCISCrash  setUserFieldWithValue:self.userInfoValue2TextField.text
                                   forKey:@"TexxtField userInfoValue2TextField"];
        
        [TCISCrash  setUserFieldWithValue:self.userInfoKey3TextField.text
                                   forKey:@"TexxtField userInfoKey3TextField"];
        [TCISCrash  setUserFieldWithValue:self.userInfoValue3TextField.text
                                   forKey:@"TexxtField userInfoValue3TextField"];
        
        [TCISCrash  setUserFieldWithValue:self.delegateTextView.text
                                   forKey:@"TexxtField delegateTextView"];

    }];
}



- (IBAction)crashButton:(id)sender {
    //Crash
    int *a = 1;
    a[2] = 1;
}

#pragma mark - ToastCrash Delegate
- (void)setToastCrashDelegate {
    [TCISCrash enableCrashDelegate:self];
}

- (void)crashLoggerInstance:(TCISInstanceLogger *)instanceLogger
   didSendSuccessedCrashLog:(TCISLog *)crashLog {
    
    dispatch_async(dispatch_get_main_queue(), ^{
        self.delegateTextView.text = [NSString stringWithFormat:@"[ToastCrash][SUCCESS] - %@", crashLog.logMessage];
    });
}

- (void)crashLoggerInstance:(TCISInstanceLogger *)instanceLogger
      didSendFailedCrashLog:(TCISLog *)crashLog
                      error:(NSError *)error {
    
    dispatch_async(dispatch_get_main_queue(), ^{
        self.delegateTextView.text = [NSString stringWithFormat:@"[ToastCrash][FAIL] - %@\n%@", crashLog.logMessage, [error description] ];
    });
}

- (void)crashLoggerInstance:(TCISInstanceLogger *)instanceLogger
           didSavedCrashLog:(TCISLog *)crashLog {
    
    dispatch_async(dispatch_get_main_queue(), ^{
        self.delegateTextView.text = [NSString stringWithFormat:@"[ToastCrash][SAVE] - %@", crashLog.logMessage];
    });
}

- (void)crashLoggerInstance:(TCISInstanceLogger *)instanceLogger
        didFilteredCrashLog:(TCISLog *)crashLog
                  logFilter:(TCISLogFilter *)logFilter {
    
    dispatch_async(dispatch_get_main_queue(), ^{
        self.delegateTextView.text = [NSString stringWithFormat:@"[ToastCrash][FILTER] [%@] - %@", logFilter.name, crashLog.logMessage];
    });
    
}

@end
