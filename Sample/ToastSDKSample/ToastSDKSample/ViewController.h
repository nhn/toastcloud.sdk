//
//  ViewController.h
//  ToastSDKSample
//
//  Created by Hyup on 2018. 3. 13..
//  Copyright © 2018년 NHN Entertainment Corp. All rights reserved.
//

#import <UIKit/UIKit.h>

#import <ToastLogger/ToastLogger.h>
#import <ToastCrash/ToastCrash.h>


@interface ViewController : UIViewController <TCISLoggerDelegate, TCISCrashDelegate>

@property (weak, nonatomic) IBOutlet UITextField *userIDTextField;

@property (weak, nonatomic) IBOutlet UITextField *userInfoKey1TextField;
@property (weak, nonatomic) IBOutlet UITextField *userInfoKey2TextField;
@property (weak, nonatomic) IBOutlet UITextField *userInfoKey3TextField;

@property (weak, nonatomic) IBOutlet UITextField *userInfoValue1TextField;
@property (weak, nonatomic) IBOutlet UITextField *userInfoValue2TextField;
@property (weak, nonatomic) IBOutlet UITextField *userInfoValue3TextField;

@property (weak, nonatomic) IBOutlet UISegmentedControl *logLevelSegment;

@property (weak, nonatomic) IBOutlet UITextField *tagTextField;

@property (weak, nonatomic) IBOutlet UITextField *messageTextField;

@property (weak, nonatomic) IBOutlet UITextField *logUserInfoKey1TextField;
@property (weak, nonatomic) IBOutlet UITextField *logUserInfoKey2TextField;
@property (weak, nonatomic) IBOutlet UITextField *logUserInfoKey3TextField;

@property (weak, nonatomic) IBOutlet UITextField *logUserInfoValue1TextField;
@property (weak, nonatomic) IBOutlet UITextField *logUserInfoValue2TextField;
@property (weak, nonatomic) IBOutlet UITextField *logUserInfoValue3TextField;

@property (weak, nonatomic) IBOutlet UITextView *delegateTextView;

- (IBAction)sendLogButton:(id)sender;
- (IBAction)crashButton:(id)sender;

@end

