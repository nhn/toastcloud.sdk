//
//  ViewController.h
//  ToastSDK-Push-Sample
//
//  Created by NHN on 2018. 12. 28..
//  Copyright © 2018년 NHN. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface PushViewController : UIViewController

@property (weak, nonatomic) IBOutlet UITextField *userIdTextField;
@property (weak, nonatomic) IBOutlet UIButton *loginOrLogoutButton;
@property (weak, nonatomic) IBOutlet UISwitch *pushSwitch;
@property (weak, nonatomic) IBOutlet UISwitch *adSwitch;
@property (weak, nonatomic) IBOutlet UISwitch *nightAdSwitch;
@property (weak, nonatomic) IBOutlet UIButton *registrationButton;
@property (weak, nonatomic) IBOutlet UIButton *queryButton;

@end

