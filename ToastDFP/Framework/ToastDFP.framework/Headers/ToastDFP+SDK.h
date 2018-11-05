//
//  ToastDFP+SDK.h
//  ToastDFP
//
//  Created by Hyup on 2017. 11. 27..
//  Copyright © 2017년 NHNEnt. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <ToastCore/ToastCore.h>
#import "ToastDFPUserEvent.h"
#import "ToastDFPConfiguration.h"

@class ToastDFPConfiguration;

@interface ToastDFP : NSObject

+ (void)initWithConfiguration:(ToastDFPConfiguration *)configuration;

+ (BOOL)startService;
+ (void)stopService;

+ (void)startUpdatingLocation;
+ (void)stopUpdatingLocation;

+ (void)setPriority:(ToastDFPPriority)priority;

+ (void)setUserFieldWithValue:(NSString *)value forKey:(NSString *)key;
+ (void)removeAllUserFields;
+ (BOOL)sendUserEvent:(ToastDFPUserEvent *)event;

+ (NSString *)version;

@end
