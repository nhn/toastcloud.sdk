//
//  ToastPushTokenInfo.h
//  ToastPush
//
//  Created by JooHyun Lee on 2018. 11. 30..
//  Copyright © 2018년 NHNEnt. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ToastPushConfiguration.h"

NS_ASSUME_NONNULL_BEGIN

@interface ToastPushTokenInfo : NSObject

@property (nonatomic, readonly) NSString *userID;
@property (nonatomic, readonly) NSString *deviceToken;
@property (nonatomic, readonly) NSString *countryCode;
@property (nonatomic, readonly) NSString *languageCode;
@property (nonatomic, readonly) NSString *pushType;
@property (nonatomic, readonly) BOOL allowNotifications;
@property (nonatomic, readonly) BOOL allowAdvertisements;
@property (nonatomic, readonly) BOOL allowNightAdvertisements;
@property (nonatomic, readonly) NSString *timezone;
@property (nonatomic, readonly) NSString *updateDateTime;

@end

NS_ASSUME_NONNULL_END
