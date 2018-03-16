//
//  ViewController.m
//  ToastSDKSample
//
//  Created by Hyup on 2018. 3. 13..
//  Copyright © 2018년 NHN Entertainment Corp. All rights reserved.
//

#import "ViewController.h"

#define APPKEY @"bUNrwOkUyn7HS1Ij"

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
    
    [self initToastLogger];
    [self setToastLoggerDelegate];
    
    [self initToastCrash];
    [self setToastCrashDelegate];
    [self setCrashUserInfo];
}


- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

#pragma mark - ToastLogger
- (void)initToastLogger {
    
    NSString *appVersion = [[[NSBundle mainBundle] infoDictionary] objectForKey:@"CFBundleShortVersionString"];
    
    [TCISLogger loggerConfiguration:[TCISLoggerConfiguration configurationWithProjectKey:APPKEY projectVersion:appVersion]];
}



- (void)setUserInfo {
    
    NSMutableDictionary *baseUserInfoDictionary = [[NSMutableDictionary alloc]init];
    [baseUserInfoDictionary setObject:@"baseUserInfoValue_1" forKey:@"baseUserInfoKey_1"];
    
    [TCISLogger setUserLogField:baseUserInfoDictionary];
    
    if(![self.userInfoKey1TextField.text isEqualToString:@""]) {
        [TCISLogger setUserLogFieldWithValue:self.userInfoValue1TextField.text
                                      forKey:self.userInfoKey1TextField.text];
    }
    if(![self.userInfoKey2TextField.text isEqualToString:@""]) {
        [TCISLogger setUserLogFieldWithValue:self.userInfoValue2TextField.text
                                      forKey:self.userInfoKey2TextField.text];
    }
    if(![self.userInfoKey3TextField.text isEqualToString:@""]) {
        [TCISLogger setUserLogFieldWithValue:self.userInfoValue3TextField.text
                                      forKey:self.userInfoKey3TextField.text];
    }
}

- (NSDictionary *)getLogUserInfo {
    
    if( (![self.logUserInfoKey1TextField.text isEqualToString:@""]) &&
        (![self.logUserInfoKey1TextField.text isEqualToString:@""]) &&
        (![self.logUserInfoKey1TextField.text isEqualToString:@""]) ) {
        return nil;
    }
    
    NSMutableDictionary *userInfo = [[NSMutableDictionary alloc]init];
    
    if(![self.logUserInfoKey1TextField.text isEqualToString:@""]) {
        [userInfo setObject:self.logUserInfoValue1TextField.text
                     forKey:self.logUserInfoKey1TextField.text];
    }
    if(![self.logUserInfoKey2TextField.text isEqualToString:@""]) {
        [userInfo setObject:self.logUserInfoValue2TextField.text
                     forKey:self.logUserInfoKey2TextField.text];
    }
    if(![self.logUserInfoKey3TextField.text isEqualToString:@""]) {
        [userInfo setObject:self.logUserInfoValue3TextField.text
                     forKey:self.logUserInfoKey3TextField.text];
    }
    
    return userInfo;
}

- (void)sendDebugLog {
    
    if([self getLogUserInfo] == nil) {
        [TCISLogger debugWithLogTag:self.tagTextField.text message:self.messageTextField.text];
        [TCISLogger debugWithLogTag:self.tagTextField.text messageFormat:[NSString stringWithFormat:@"Message : [%@]", self.messageTextField.text ]];
    }else {
        [TCISLogger debugWithLogTag:self.tagTextField.text message:self.messageTextField.text userLogField:[self getLogUserInfo]];
    }
}

- (void)sendInfoLog {
    
    if([self getLogUserInfo] == nil) {
        [TCISLogger infoWithLogTag:self.tagTextField.text message:self.messageTextField.text];
        [TCISLogger infoWithLogTag:self.tagTextField.text messageFormat:[NSString stringWithFormat:@"Message : [%@]", self.messageTextField.text ]];
    }else {
        [TCISLogger infoWithLogTag:self.tagTextField.text message:self.messageTextField.text userLogField:[self getLogUserInfo]];
    }
}

- (void)sendWarnLog {
    
    if([self getLogUserInfo] == nil) {
        [TCISLogger warnWithLogTag:self.tagTextField.text message:self.messageTextField.text];
        [TCISLogger warnWithLogTag:self.tagTextField.text messageFormat:[NSString stringWithFormat:@"Message : [%@]", self.messageTextField.text ]];
    }else {
        [TCISLogger warnWithLogTag:self.tagTextField.text message:self.messageTextField.text userLogField:[self getLogUserInfo]];
    }
}

- (void)sendErrorLog {
    
    if([self getLogUserInfo] == nil) {
        [TCISLogger errorWithLogTag:self.tagTextField.text message:self.messageTextField.text];
        [TCISLogger errorWithLogTag:self.tagTextField.text messageFormat:[NSString stringWithFormat:@"Message : [%@]", self.messageTextField.text ]];
    }else {
        [TCISLogger errorWithLogTag:self.tagTextField.text message:self.messageTextField.text userLogField:[self getLogUserInfo]];
    }
}

- (void)sendFatalLog {
    
    if([self getLogUserInfo] == nil) {
        [TCISLogger fatalWithLogTag:self.tagTextField.text message:self.messageTextField.text];
        [TCISLogger fatalWithLogTag:self.tagTextField.text messageFormat:[NSString stringWithFormat:@"Message : [%@]", self.messageTextField.text ]];
    }else {
        [TCISLogger fatalWithLogTag:self.tagTextField.text message:self.messageTextField.text userLogField:[self getLogUserInfo]];
    }
}



- (IBAction)sendLogButton:(id)sender {
    
    [TCISLogger setUserID:self.userIDTextField.text];
    [self setUserInfo];
    
    if(self.logLevelSegment.selectedSegmentIndex == 0) {
        [self sendDebugLog];
    }else if(self.logLevelSegment.selectedSegmentIndex == 1) {
        [self sendInfoLog];
    }else if(self.logLevelSegment.selectedSegmentIndex == 2) {
        [self sendWarnLog];
    }else if(self.logLevelSegment.selectedSegmentIndex == 3) {
        [self sendErrorLog];
    }else if(self.logLevelSegment.selectedSegmentIndex == 4) {
        [self sendFatalLog];
    }
}

#pragma mark - ToastLogger Delegate

- (void)setToastLoggerDelegate {
    [TCISLogger setDelegate:self];
}

- (void)instanceLogger:(TCISInstanceLogger *)instanceLogger
   didSendSuccessedLog:(TCISLog *)log {
    
    dispatch_async(dispatch_get_main_queue(), ^{
        self.delegateTextView.text = [NSString stringWithFormat:@"[SUCCESS] - %@", log.logMessage];
    });
    
}

- (void)instanceLogger:(TCISInstanceLogger *)instanceLogger
      didSendFailedLog:(TCISLog *)log
                 error:(NSError *)error {
    
    dispatch_async(dispatch_get_main_queue(), ^{
        self.delegateTextView.text = [NSString stringWithFormat:@"[FAIL] - %@\n%@", log.logMessage, [error description] ];
    });
}

- (void)instanceLogger:(TCISInstanceLogger *)instanceLogger
           didSavedLog:(TCISLog *)log {
    
    dispatch_async(dispatch_get_main_queue(), ^{
        self.delegateTextView.text = [NSString stringWithFormat:@"[SAVE] - %@", log.logMessage];
    });
}

- (void)instanceLogger:(TCISInstanceLogger *)instanceLogger
        didFilteredLog:(TCISLog *)log
             logFilter:(TCISLogFilter *)logFilter {
    
    dispatch_async(dispatch_get_main_queue(), ^{
        self.delegateTextView.text = [NSString stringWithFormat:@"[FILTER] [%@] - %@", logFilter.name, log.logMessage];
    });
}


#pragma mark - ToastCrash

- (void)initToastCrash {
    [TCISCrash setConfigurationLogger:[TCISLogger instanceLogger]];
}

- (void)setCrashUserInfo {
    [TCISCrash setUserFieldIntoTCISCrashBlock:^{
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
        
        [TCISCrash  setUserFieldWithValue:[NSString stringWithFormat:@"%ld", (long)self.logLevelSegment.selectedSegmentIndex]
                                   forKey:@"TexxtField logLevelSegment"];
        
        [TCISCrash  setUserFieldWithValue:self.tagTextField.text
                                   forKey:@"TexxtField tagTextField"];
        
        [TCISCrash  setUserFieldWithValue:self.messageTextField.text
                                   forKey:@"TexxtField messageTextField"];
        
        [TCISCrash  setUserFieldWithValue:self.logUserInfoKey1TextField.text
                                   forKey:@"TexxtField logUserInfoKey1TextField"];
        [TCISCrash  setUserFieldWithValue:self.logUserInfoValue1TextField.text
                                   forKey:@"TexxtField logUserInfoValue1TextField"];
        
        [TCISCrash  setUserFieldWithValue:self.logUserInfoKey2TextField.text
                                   forKey:@"TexxtField logUserInfoKey2TextField"];
        [TCISCrash  setUserFieldWithValue:self.logUserInfoValue2TextField.text
                                   forKey:@"TexxtField logUserInfoValue2TextField"];
        
        [TCISCrash  setUserFieldWithValue:self.logUserInfoKey3TextField.text
                                   forKey:@"TexxtField logUserInfoKey3TextField"];
        [TCISCrash  setUserFieldWithValue:self.logUserInfoValue3TextField.text
                                   forKey:@"TexxtField logUserInfoValue3TextField"];
        
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
        self.delegateTextView.text = [NSString stringWithFormat:@"[SUCCESS] - %@", crashLog.logMessage];
    });
}

- (void)crashLoggerInstance:(TCISInstanceLogger *)instanceLogger
      didSendFailedCrashLog:(TCISLog *)crashLog
                      error:(NSError *)error {
    
    dispatch_async(dispatch_get_main_queue(), ^{
        self.delegateTextView.text = [NSString stringWithFormat:@"[FAIL] - %@\n%@", crashLog.logMessage, [error description] ];
    });
}

- (void)crashLoggerInstance:(TCISInstanceLogger *)instanceLogger
           didSavedCrashLog:(TCISLog *)crashLog {
    
    dispatch_async(dispatch_get_main_queue(), ^{
        self.delegateTextView.text = [NSString stringWithFormat:@"[SAVE] - %@", crashLog.logMessage];
    });
}

- (void)crashLoggerInstance:(TCISInstanceLogger *)instanceLogger
        didFilteredCrashLog:(TCISLog *)crashLog
                  logFilter:(TCISLogFilter *)logFilter {
    
    dispatch_async(dispatch_get_main_queue(), ^{
        self.delegateTextView.text = [NSString stringWithFormat:@"[FILTER] [%@] - %@", logFilter.name, crashLog.logMessage];
    });
    
}

@end
