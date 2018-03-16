//
//  ViewController.h
//  ToastCrashSample
//
//  Created by Hyup on 2018. 3. 13..
//  Copyright © 2018년 NHN Entertainment Corp. All rights reserved.
//

#import <UIKit/UIKit.h>

#import <ToastLogger/ToastLogger.h>
#import <ToastCrash/ToastCrash.h>

@interface ViewController : UIViewController <TCISCrashDelegate>

@property (weak, nonatomic) IBOutlet UITextField *userIDTextField;

@property (weak, nonatomic) IBOutlet UITextField *userInfoKey1TextField;
@property (weak, nonatomic) IBOutlet UITextField *userInfoKey2TextField;
@property (weak, nonatomic) IBOutlet UITextField *userInfoKey3TextField;

@property (weak, nonatomic) IBOutlet UITextField *userInfoValue1TextField;
@property (weak, nonatomic) IBOutlet UITextField *userInfoValue2TextField;
@property (weak, nonatomic) IBOutlet UITextField *userInfoValue3TextField;

@property (weak, nonatomic) IBOutlet UITextView *delegateTextView;

- (IBAction)crashButton:(id)sender;

@end

