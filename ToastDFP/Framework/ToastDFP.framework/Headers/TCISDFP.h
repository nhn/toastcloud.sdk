//
//  TCISDFP.h
//  ToastDFP
//
//  Created by Hyup on 2017. 11. 27..
//  Copyright © 2017년 NHNEnt. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <ToastCommon/ToastCommon.h>
#import <ToastCore/ToastCore.h>
#import <ToastLogger/ToastLogger.h>
#import "TCISDFPUserEvent.h"
#import "TCISDFPConfiguration.h"

@class TCISDFP;
@class TCISDFPConfiguration;

@interface TCISDFP : NSObject

+ (void)initWithConfiguration:(TCISDFPConfiguration *)configuration;

+ (BOOL)startService;
+ (void)stopService;

+ (void)startUpdatingLocation;
+ (void)stopUpdatingLocation;
+ (void)setUserIdentifier:(NSString *)identifier;
+ (void)setPriority:(TCISDFPPriority)priority;

+ (void)setUserField:(NSString *)value forKey:(NSString *)key;
+ (NSString *)userFieldForKey:(NSString *)key;
+ (void)removeUserFieldForKey:(NSString *)key;
+ (void)removeAllUserFields;

+ (void)sendUserEvent:(TCISDFPUserEvent *)event;

+ (NSString *)version;
@end
