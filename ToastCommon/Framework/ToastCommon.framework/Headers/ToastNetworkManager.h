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

@interface ToastNetworkManager : NSObject

@property (class, readonly, strong) ToastNetworkManager *defaultManager;
@property (nonatomic, readonly, strong) ToastNetworkStatus *currentNetworkStatus;

- (BOOL)startMonitoringNetworkStatusChanges;
- (void)stopMonitoringNetworkStatusChanges;

- (void)addObserver:(id<ToastNetworkStatusObserver>)observer;
- (void)removeObserver:(id<ToastNetworkStatusObserver>)observer;

@end


@protocol ToastNetworkStatusObserver <NSObject>

- (void)networkManager:(ToastNetworkManager *)manager didChangeNetworkStatus:(ToastNetworkStatus *)status;

@end
