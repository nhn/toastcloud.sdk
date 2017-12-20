//
//  TCISInfoUtil.h
//  ToastCommon
//
//  Created by Hyup on 2017. 8. 25..
//  Copyright © 2017년 NHNEnt. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface TCISInfoUtil : NSObject

#pragma mark - DeviceInfo
+ (NSString *)deviceModel;
+ (NSString *)carrier;
+ (NSString *)countryCodeLocale;
+ (NSString *)countryCodeUSIM;
+ (NSString *)localeDisplayName;
+ (NSString *)languageCode;
+ (NSString *)OS;
+ (NSString *)osVersion;
+ (NSString *)resolutionScreen;
+ (NSString *)timeZone;
+ (NSString *)freeMemory;
+ (NSString *)freeSpace;
+ (BOOL)isSimulator;

#pragma mark - Network
+ (NSString *)networkType;
+ (NSString *)IP;

#pragma mark - Identifier
+ (NSString *)uuid;
+ (NSString *)idfv;
+ (NSString *)idfa;
+ (NSString *)savedUUID;

#pragma mark - Application
+ (NSString *)bundleID;
+ (NSString *)displayName;
+ (NSString *)shortVersionString;

#pragma mark - Library
+ (NSString *)version;
@end
