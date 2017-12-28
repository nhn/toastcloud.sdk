//
//  TCISNetworkMonitor.h
//  ToastCommon
//
//  Created by Hyup on 2017. 8. 25..
//  Copyright © 2017년 NHNEnt. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <SystemConfiguration/SystemConfiguration.h>

typedef NS_ENUM(NSInteger, TCISNetworkStatus) {
    TCISNotReachable = -1,
    TCISReachableViaWWAN,
    TCISReachableViaWifi,
};


extern NSString* const kTCISNetworkReachabilityChangedNotification;
extern NSString* const kTCISNetworkReachabilityTargetHostname;

typedef NS_ENUM(NSUInteger, TCISMonitorState) {
    NotInitialized = 0,
    Initialized,
    Stopped,
    Started,
};

typedef void(^TCISNetworkChangedHandler)(TCISNetworkStatus status, NSString* handlerID);

@interface TCISNetworkMonitor : NSObject{
    SCNetworkReachabilityRef                                    _reachability;
    NSMutableDictionary<NSString*, TCISNetworkChangedHandler>*      _observerHandlers;
}

@property (nonatomic, assign) TCISMonitorState                      currentMonitorState;

+ (TCISNetworkMonitor *)networkMonitorWithHostName:(NSString *)hostname;
+ (TCISNetworkMonitor *)sharedNetworkMonitor;
- (BOOL)startMonitoring;
- (void)stopMonitoring;
- (BOOL)isConnectionRequired;
- (TCISNetworkStatus)currentNetworkReachableStatus;
- (NSString *)stringWithNetworkStatus:(TCISNetworkStatus)status;
- (NSString *)addObserverOnChangedNetworkStatusWithHandler:(TCISNetworkChangedHandler)handler;
- (TCISNetworkChangedHandler)handlerForOnChangedNetworkStatusHandlerWithHandlerID:(NSString *)handlerID;
- (void)removeObserverOnChangedNetworkStatus:(NSString *)handlerID;


// @private
- (void)invokeObserversOnChangedNetworkStatusWithMonitor:(TCISNetworkMonitor *)monitor;



@end
