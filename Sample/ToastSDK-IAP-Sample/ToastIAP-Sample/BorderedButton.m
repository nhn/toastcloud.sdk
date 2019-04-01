//
//  BorderedButton.m
//  ToastIAP-Sample
//
//  Created by NHN on 2018. 11. 12..
//  Copyright © 2018년 NHN. All rights reserved.
//

#import "BorderedButton.h"

@implementation BorderedButton

- (instancetype)init
{
    self = [super init];
    if (self) {
        [self setBorder];
    }
    return self;
}

- (instancetype)initWithCoder:(NSCoder *)coder
{
    self = [super initWithCoder:coder];
    if (self) {
        [self setBorder];
    }
    return self;
}

- (void)setBorder {
    self.layer.borderColor = [UIColor blueColor].CGColor;
    self.layer.borderWidth = 1;
    self.layer.cornerRadius = 10;
}


/*
// Only override drawRect: if you perform custom drawing.
// An empty implementation adversely affects performance during animation.
- (void)drawRect:(CGRect)rect {
    // Drawing code
}
*/

@end
