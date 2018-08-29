//
//  ToastSDK.h
//  ToastCore
//
//  Created by Hyup on 2017. 9. 13..
//  Copyright © 2017년 NHNEnt. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface ToastSDK : NSObject

#pragma mark - init
+ (ToastSDK *)sharedInstance;

#pragma mark - Optional Setting
+ (void)setOptionalPolicyWithArray:(NSArray<NSString *>*)array;

+ (void)setUserID:(NSString *)userID;
+ (NSString *)userID;

#pragma mark - DebugMode Setting
+ (void)setDebugMode:(BOOL)debugMode;
+ (BOOL)isDebugMode;

#pragma mark - Version
+ (NSString *)version;

@end
