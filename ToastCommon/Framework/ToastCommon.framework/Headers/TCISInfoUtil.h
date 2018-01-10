//
//  TCISInfoUtil.h
//  ToastCommon
//
//  Created by Hyup on 2017. 8. 25..
//  Copyright © 2017년 NHNEnt. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface TCISInfoUtil : NSObject

#pragma mark - Application
+ (NSString *)bundleID;
+ (NSString *)displayName;
+ (NSString *)shortVersion;
+ (NSString *)rootViewControllerTitle;
+ (NSString *)packageName;
+ (NSString *)appVersion;
+ (NSString *)appState;

#pragma mark - Account
+ (NSString *)iCloudToken;

#pragma mark - Device
+ (NSString *)carrier;
+ (NSString *)deviceName;
+ (NSString *)deviceModel;
+ (NSString *)deviceLocalizedModel;
+ (NSString *)deviceSystemName;
+ (NSString *)deviceSystemVersion;
+ (NSNumber *)deviceScreenWidth;
+ (NSNumber *)deviceScreenHeight;
+ (NSString *)deviceScreenResolution;
+ (NSString *)deviceOrientation;
+ (NSString *)countryCode;
+ (NSString *)countryCodeFromLocale;
+ (NSString *)countryCodeFromUsim;
+ (NSString *)localeDisplayName;
+ (NSString *)languageCode;
+ (NSString *)os;
+ (NSString *)osVersion;
+ (NSString *)timezone;
+ (NSString *)freeMemory;
+ (NSString *)freeSpace;
+ (NSString *)hardwareMachine;
+ (NSString *)hardwareModel;
+ (NSString *)kernelUUID;
+ (NSString *)kernelVersion;
+ (NSString *)kernelBootSessionUUID;
+ (NSString *)kernelBootSignature;
+ (NSNumber *)kernelHostID;
+ (NSString *)kernelHostName;
+ (NSString *)kernelOSType;
+ (NSString *)kernelOSRelease;
+ (NSNumber *)kernelOSRevision;
+ (NSString *)mobileCountryCode;
+ (NSString *)mobileNetworkCode;
+ (BOOL)isSimulator;
+ (NSString *)cpuArchitecture;

#pragma mark - Identifier
+ (NSString *)idfa;
+ (NSString *)idfv;
+ (NSString *)deviceUUID;
+ (NSString *)keychainUUID;

#pragma mark - JailbreakInfo
+ (NSArray *)jailbreakFilePath;
+ (NSArray *)jailbreakDyld;
+ (NSArray *)jailbreakSymlinked;
+ (NSArray *)jailbreakWritable;
+ (NSArray *)jailbreakUrlSchemesOpenable;
+ (NSArray *)jailbreakSystemCall;

#pragma mark - Network
+ (NSString *)networkType;
+ (NSString *)ip;
+ (NSString *)cellIP;
+ (NSString *)wifiIP;
+ (NSString *)netmask;
+ (NSString *)ssid;
+ (NSString *)bssid;
+ (NSString *)proxy;

#pragma mark - Common
+ (NSString *)userAgent;
+ (NSString *)userAgentWithSDKName:(NSString *)aName currentVersion:(NSString *)aVersion;

#pragma mark - Version
+ (NSString *)version;
@end
