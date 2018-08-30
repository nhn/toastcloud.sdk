//
//  ViewController.m
//  ToastSDK-Sample
//
//  Created by Hyup on 2018. 8. 29..
//  Copyright © 2018년 NHN Entertainment Corp. All rights reserved.
//

#import "ToastViewController.h"

#define APP_KEY @"Please input your app key here."
#define USER_ID @"Please input your user ID here."

@interface ToastViewController ()

@end

@implementation ToastViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    _userIDTextField.text = USER_ID;
    _appKeyTextField.text = APP_KEY;
    
    [ToastSDK setDebugMode:YES];
}

#pragma mark - button Actions

- (IBAction)initializeButtonDidTap:(id)sender {
    
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        self->_sendLogButton.enabled = YES;
        self->_sendCrashButton.enabled = YES;
    });
    
    [ToastSDK setUserID:_userIDTextField.text];
    [ToastSDK sharedInstance];
    
    NSString *projectKey = _appKeyTextField.text;

    ToastLoggerConfiguration *loggerConfig = [ToastLoggerConfiguration configurationWithProjectKey:projectKey];
    
    //CrashReporter Set Configuration
    //ToastLoggerConfiguration *loggerConfig = [ToastLoggerConfiguration configurationWithProjectKey:projectKey enableCrashReporter:YES];
    
    [ToastLogger initWithConfiguration:loggerConfig];
    
    [ToastLogger setDelegate:self];
}

- (IBAction)sendLogButtonDidTap:(id)sender {
    
    NSString *message = _logMessageTextField.text;
    
    if ([@"" isEqualToString:message]) {
        message = [NSString stringWithFormat:@"[SampleApp] Current unixEpochTime : %llu", [ToastUtil unixEpochTime]];
    }
    
    [self setValidGlobalUserField];
    
    int index = (int)_logLevelSegment.selectedSegmentIndex;
    
    switch (index) {
        case 0: // Debug
            [ToastLogger debug:message userFields:[self validUserField]];
            break;
            
        case 1: // Info
            [ToastLogger info:message userFields:[self validUserField]];
            break;
            
        case 2: // Warn
            [ToastLogger warn:message userFields:[self validUserField]];
            break;
            
        case 3: // Error
            [ToastLogger error:message userFields:[self validUserField]];
            break;
            
        case 4: // Fatal
            [ToastLogger fatal:message userFields:[self validUserField]];
            break;
            
        default:
            break;
    }
}

- (IBAction)sendCrashButtonDidTap:(id)sender {
    [self performSelector:@selector(die_die)];
}

#pragma mark - utils

- (NSDictionary *)validUserField {
    NSMutableDictionary *userFields = [NSMutableDictionary dictionary];
    
    if (![@"" isEqualToString:_personalUserFieldKeyTextField.text]) {
        [userFields setObject:_personalUserFieldValueTextField.text forKey:_personalUserFieldKeyTextField.text];
    }
    
    return userFields;
}

- (void)setValidGlobalUserField {
    if (![@"" isEqualToString:_globalUserFieldKeyTextField.text]) {
        [ToastLogger setUserFieldWithValue:_globalUserFieldValueTextField.text forKey:_globalUserFieldKeyTextField.text];
    }
}

- (void)touchesBegan:(NSSet<UITouch *> *)touches withEvent:(UIEvent *)event {
    [super touchesBegan:touches withEvent:event];
    [self.view endEditing:YES];
}

#pragma mark - Toast Logger Delegates

- (void)toastLogDidSuccess:(ToastLog *)log {
    dispatch_async(dispatch_get_main_queue(), ^{
        self->_sendLogDelegateTextView.text = [NSString stringWithFormat:@"[toastLogDidSuccess]log = %@", log];
    });
}

- (void)toastLogDidFail:(ToastLog *)log error:(NSError *)error {
    dispatch_async(dispatch_get_main_queue(), ^{
        self->_sendLogDelegateTextView.text = [NSString stringWithFormat:@"[toastLogDidFail]log = %@\nerror = %@", log, error];
    });
}

- (void)toastLogDidSave:(ToastLog *)log {
    dispatch_async(dispatch_get_main_queue(), ^{
        self->_sendLogDelegateTextView.text = [NSString stringWithFormat:@"[toastLogDidSave]log = %@", log];
    });
}

- (void)toastLogDidFilter:(ToastLog *)log logFilter:(ToastLogFilter *)logFilter {
    dispatch_async(dispatch_get_main_queue(), ^{
      self->_sendLogDelegateTextView.text = [NSString stringWithFormat:@"[toastLogDidFilter]log = %@\nlogFilter = %@", log, logFilter];
    });
}

@end
