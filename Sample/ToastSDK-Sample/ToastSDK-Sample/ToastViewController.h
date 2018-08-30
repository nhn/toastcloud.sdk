//
//  ViewController.h
//  ToastSDK-Sample
//
//  Created by Hyup on 2018. 8. 29..
//  Copyright © 2018년 NHN Entertainment Corp. All rights reserved.
//

#import <UIKit/UIKit.h>

#import <ToastLogger/ToastLogger.h>
#import <ToastCore/ToastCore.h>

@interface ToastViewController : UIViewController <ToastLoggerDelegate>

@property (weak, nonatomic) IBOutlet UITextField *userIDTextField;

@property (weak, nonatomic) IBOutlet UITextField *appKeyTextField;

@property (weak, nonatomic) IBOutlet UISegmentedControl *logLevelSegment;

@property (weak, nonatomic) IBOutlet UITextField *logMessageTextField;

@property (weak, nonatomic) IBOutlet UITextView *sendLogDelegateTextView;

@property (weak, nonatomic) IBOutlet UITextField *globalUserFieldKeyTextField;

@property (weak, nonatomic) IBOutlet UITextField *globalUserFieldValueTextField;

@property (weak, nonatomic) IBOutlet UITextField *personalUserFieldKeyTextField;

@property (weak, nonatomic) IBOutlet UITextField *personalUserFieldValueTextField;

@property (weak, nonatomic) IBOutlet UIButton *sendLogButton;

@property (weak, nonatomic) IBOutlet UIButton *sendCrashButton;

@end
