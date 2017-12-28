//
//  TCISSystemInfo.h
//  ToastCommon
//
//  Created by Hyup on 2017. 8. 25..
//  Copyright © 2017년 NHNEnt. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface TCISDeviceInfo : NSObject

+ (NSString *)carrier;

+ (NSString *)countryCode;
+ (NSString *)usimCountryCode;
+ (NSString *)deviceCountryCode;
+ (NSString *)localeDisplayName;

+ (NSString *)languageCode;


+ (NSString *)os;

+ (NSString*)osVersion;
+ (NSArray *)osVersionSeperatedByDot;
+ (int)iOSMajorVersion;
+ (int)iOSMinorVersion;
+ (BOOL)isiOSVersion : (int)majorVersion orLater : (BOOL)later;

+ (NSString *)resolutionScreen;

+ (NSString*)timeZone;

+ (BOOL) checkSimulator;

#pragma mark - ToastDFP
+ (NSString *)deviceName;
+ (NSString *)deviceModel;
+ (NSString *)deviceLocalizedModel;
+ (NSString *)deviceSystemName;
+ (NSString *)deviceSystemVersion;
+ (NSNumber *)deviceScreenWidth;
+ (NSNumber *)deviceScreenHeight;
+ (NSString *)hardwareMachine;
+ (NSString *)hardwareModel;
+ (NSString *)kernelUuid;
+ (NSString *)kernelVersion;
+ (NSString *)kernelBootSessionUUID;
+ (NSString *)kernelBootSignature;
+ (NSNumber *)kernelHostID;
+ (NSString *)kernelHostName;
+ (NSString *)kernelOSType;
+ (NSString *)kernelOSRelease;
+ (NSNumber *)kernelOSRevision;
+ (NSString *)deviceOrientation;

+ (NSString *)mobileCountryCode;
+ (NSString *)mobileNetworkCode;

+ (NSString *)freeMemory;
+ (NSString *)freeSpace;

@end
