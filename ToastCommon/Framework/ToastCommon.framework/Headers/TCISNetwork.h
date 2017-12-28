//
//  TCISNetwork.h
//  ToastCommon
//
//  Created by Hyup on 2017. 8. 25..
//  Copyright © 2017년 NHNEnt. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TCISNetworkMonitor.h"

#import <Foundation/Foundation.h>
#import <SystemConfiguration/SystemConfiguration.h>

typedef void(^TCISNetworkChangedHandler)(TCISNetworkStatus status, NSString* handlerID);

@interface TCISNetwork : NSObject

+ (TCISNetworkStatus)type;
+ (NSString *)typeName;
+ (BOOL)isConnected;

+ (NSString *)addObserverOnChangedNetworkStatusWithHandler:(TCISNetworkChangedHandler)handler;

+ (void)removeObserverOnChangedNetworkStatusHandler:(NSString *)handlerID;

+ (NSString *)networkType;
+ (NSString*)IP;

#pragma mark - ToastDFP

+ (NSString *)cellIP;
+ (NSString *)wifiIP;
+ (NSString *)netmask;
+ (NSString *)ssid;
+ (NSString *)bssid;
+ (NSString *)proxy;

@end
