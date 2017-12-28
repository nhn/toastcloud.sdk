//
//  TCISApplicationInfo.h
//  ToastCommon
//
//  Created by Hyup on 2017. 8. 25..
//  Copyright © 2017년 NHNEnt. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface TCISApplicationInfo : NSObject

+ (NSString *)bundleID;

+ (NSString *)displayName;
+ (NSString *)shortVersionString;

#pragma mark - ToastDFP - Priority 1
+ (NSString *)windowRootView;
+ (NSString *)uid;
+ (NSString *)packageName;
+ (NSString *)appVersion;
+ (NSString *)applicationState;

@end
