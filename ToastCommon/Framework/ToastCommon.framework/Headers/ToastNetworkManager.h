//
//  ToastNetworkManager.h
//  ToastCommon
//
//  Created by Hyup on 2017. 8. 25..
//  Copyright © 2017년 NHNEnt. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <SystemConfiguration/SystemConfiguration.h>
#import "ToastNetworkStatus.h"

@protocol ToastNetworkStatusObserver;

/**
 # Network manager
 
 Monitoring whether the network is connected or not.
 
 */
@interface ToastNetworkManager : NSObject

@property (class, readonly, strong) ToastNetworkManager *defaultManager;
@property (nonatomic, readonly, strong) ToastNetworkStatus *currentNetworkStatus;

/**
 Start monitoring to see if the state of the network changes.

 @return If 'YES', success. If 'NO', failure.
 */
- (BOOL)startMonitoringNetworkStatusChanges;

/**
 Stop monitoring to see if the state of the network changes.
 */
- (void)stopMonitoringNetworkStatusChanges;


/**
 Add observer(ToastNetworkStatusObserver)

 @param observer observer to be added
 */
- (void)addObserver:(id<ToastNetworkStatusObserver>)observer;


/**
 Remove observer

 @param observer observer observer to be removed
 */
- (void)removeObserver:(id<ToastNetworkStatusObserver>)observer;

@end


/**
 # Network status observer
 */
@protocol ToastNetworkStatusObserver <NSObject>

- (void)networkManager:(ToastNetworkManager *)manager didChangeNetworkStatus:(ToastNetworkStatus *)status;

@end
