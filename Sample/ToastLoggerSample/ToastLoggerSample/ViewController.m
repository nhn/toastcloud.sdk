//
//  ViewController.m
//  ToastLoggerSample
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
        
    [self initToastLogger];
    [self setToastLoggerDelegate];
}


- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}


#pragma mark - ToastLogger
- (void)initToastLogger {
    
    NSString *appVersion = [[[NSBundle mainBundle] infoDictionary] objectForKey:@"CFBundleShortVersionString"];
    
    [TCISLogger setConfiguration:[TCISLoggerConfiguration configurationWithProjectKey:APPKEY projectVersion:appVersion]];
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
    
    if( ([self.logUserInfoKey1TextField.text isEqualToString:@""]) &&
        ([self.logUserInfoKey1TextField.text isEqualToString:@""]) &&
        ([self.logUserInfoKey1TextField.text isEqualToString:@""]) ) {
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
        self.delegateTextView.text = [NSString stringWithFormat:@"[ToastLogger][SUCCESS] - %@", log.logMessage];
    });
    
}

- (void)instanceLogger:(TCISInstanceLogger *)instanceLogger
      didSendFailedLog:(TCISLog *)log
                 error:(NSError *)error {
    
    dispatch_async(dispatch_get_main_queue(), ^{
        self.delegateTextView.text = [NSString stringWithFormat:@"[ToastLogger][FAIL] - %@\n%@", log.logMessage, [error description] ];
    });
}

- (void)instanceLogger:(TCISInstanceLogger *)instanceLogger
           didSavedLog:(TCISLog *)log {
    
    dispatch_async(dispatch_get_main_queue(), ^{
        self.delegateTextView.text = [NSString stringWithFormat:@"[ToastLogger][SAVE] - %@", log.logMessage];
    });
}

- (void)instanceLogger:(TCISInstanceLogger *)instanceLogger
        didFilteredLog:(TCISLog *)log
             logFilter:(TCISLogFilter *)logFilter {
    
    dispatch_async(dispatch_get_main_queue(), ^{
        self.delegateTextView.text = [NSString stringWithFormat:@"[ToastLogger][FILTER] [%@] - %@", logFilter.name, log.logMessage];
    });
}



@end
