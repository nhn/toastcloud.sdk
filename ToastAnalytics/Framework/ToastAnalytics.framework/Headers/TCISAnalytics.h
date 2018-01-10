//
//  TCISAnalytics.h
//  ToastAnalytics
//
//  Created by JooHyun Lee on 2017. 12. 21..
//  Copyright © 2017년 NHNEnt. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <ToastCommon/ToastCommon.h>
#import "TCISAnalyticsConfiguration.h"

@interface TCISAnalytics : NSObject

+ (NSString *)version;

+ (void)setConfiguration: (TCISAnalyticsConfiguration *)configuration;
+ (void)setDebugMode: (BOOL)isDebugMode;
+ (void)setUserId: (NSString *)userId;

@end
