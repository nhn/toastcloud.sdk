//
//  ViewController.h
//  ToastIAP-Sample
//
//  Created by NHNEnt on 2018. 11. 9..
//  Copyright © 2018년 NHNEnt. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "BorderedButton.h"

@interface IAPViewController : UIViewController

@property (weak, nonatomic) IBOutlet UILabel *userIDField;
@property (weak, nonatomic) IBOutlet BorderedButton *initializeButton;
@property (weak, nonatomic) IBOutlet BorderedButton *restoreButton;
@property (weak, nonatomic) IBOutlet UITextView *activePurchasesTextArea;
@property (weak, nonatomic) IBOutlet UISegmentedControl *listSegmentedControl;
@property (weak, nonatomic) IBOutlet UITableView *tableView;
@property (strong, nonatomic) UIActivityIndicatorView *activityIndicator;

@end

