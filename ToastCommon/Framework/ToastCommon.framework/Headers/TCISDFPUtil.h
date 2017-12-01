//
//  TCISDFPUtil.h
//  ToastCommon
//
//  Created by Hyup on 2017. 9. 7..
//  Copyright © 2017년 NHNEnt. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface TCISDFPUtil : NSObject

#pragma mark - 연동된 앱 정보
+ (NSString *)windowRootView;
+ (NSString *)uid;
+ (NSString *)packageName;
+ (NSString *)appVersion;

#pragma mark - 계정정보
+ (NSString *)userID;
+ (NSString *)name; //icloud

#pragma mark - 위치정보
+ (void)enableLocationData : (BOOL) enable;
+ (NSDictionary*)locationData;

#pragma mark - 기기 정보
+ (NSString *)deviceName;
+ (NSString *)deviceModel;
+ (NSString *)devicelocalizedModel;
+ (NSString *)deviceSystemName;
+ (NSString *)deviceSystemVersion;
+ (NSString *)deviceIfa;
+ (NSString *)deviceIfv;
+ (NSNumber *)deviceScreenWidth;
+ (NSNumber *)deviceScreenHeight;
+ (NSString *)hardwareeMachine;
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
+ (NSString *)deviceOrientation;

#pragma mark - jailbreak 정보
+ (NSArray *)detectionJailbreakFilePath;
+ (NSArray *)detectionJailbreakDyld;

#pragma mark - Network 정보
+ (NSString *)IP;
+ (NSString *)cellIP;
+ (NSString *)wifiIP;
/*
+ (NSString *)wifiMac;
+ (NSString *)dhcpIP;
+ (NSString *)wifiRssi;
+ (NSString *)configurationSSID;
*/

#pragma mark - 전화기 정보
+ (NSString *)carrierName;
+ (NSString *)isoCountryCode;
+ (NSString *)mobileCountryCode;
+ (NSString *)mobileNetworkCode;
@end
