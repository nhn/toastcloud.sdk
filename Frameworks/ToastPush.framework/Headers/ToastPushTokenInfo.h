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

/**
 
 A class that contains information about the token that is passed when using the token lookup request API.( [ToastPush requestTokenInfoForPushType:completionHandler:] )
 
 */
@interface ToastPushTokenInfo : NSObject

/// ---------------------------------
/// @name Properties
/// ---------------------------------

/** Identifier of user. */
@property (nonatomic, readonly) NSString *userID;

/** A globally unique token that identifies this device to APNs. */
@property (nonatomic, readonly) NSString *deviceToken;

/** A short alphabetic or numeric geographical codes developed to represent countries and dependent areas. */
@property (nonatomic, readonly) NSString *countryCode;

/** A code that assigns letters or numbers as identifiers or classifiers for languages.  */
@property (nonatomic, readonly) NSString *languageCode;

/** The type of push.( APNs or VoIP ) */
@property (nonatomic, readonly) NSString *pushType;

/** Whether to accept the notification. */
@property (nonatomic, readonly) BOOL allowNotifications;

/** Whether to accept the advertising information notification. */
@property (nonatomic, readonly) BOOL allowAdvertisements;

/** Whether to accept the advertising information notification when night */
@property (nonatomic, readonly) BOOL allowNightAdvertisements;

/** A region of the globe that observes a uniform standard time for legal, commercial and social purposes. */
@property (nonatomic, readonly) NSString *timezone;

/** The latest updated date and time. */
@property (nonatomic, readonly) NSString *updateDateTime;

@end

NS_ASSUME_NONNULL_END
