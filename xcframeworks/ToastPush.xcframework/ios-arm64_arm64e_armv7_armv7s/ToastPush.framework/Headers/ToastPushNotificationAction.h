//
//  ToastPushNotificationAction.h
//  ToastPush
//
//  Created by JooHyun Lee on 25/06/2019.
//  Copyright © 2019 NHN Corp. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UserNotifications/UserNotifications.h>
#import "ToastPushMessage.h"

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, ToastPushNotificationActionType) {
    ToastPushNotificationActionDismiss  NS_SWIFT_NAME(dismiss) = 0,
    ToastPushNotificationActionOpenApp  NS_SWIFT_NAME(openApp) = 1,
    ToastPushNotificationActionOpenURL  NS_SWIFT_NAME(openURL) = 2,
    ToastPushNotificationActionReply    NS_SWIFT_NAME(reply) = 3,
};

/**
# ToastPushMessage

A class that has information about received message.
*/
@interface ToastPushNotificationAction : NSObject <NSCoding, NSCopying>

/// ---------------------------------
/// @name Properties
/// ---------------------------------

/** Identifier of notification action. */
@property (nonatomic, readonly) NSString *actionIdentifier;

/** Identifier of category that contains notification action. */
@property (nonatomic, readonly) NSString *categoryIdentifier;

/** Type of notification action. */
@property (nonatomic, readonly) ToastPushNotificationActionType actionType;

/** Button's information of notification action. */
@property (nonatomic, readonly) ToastPushButton *button;

/** Received push message of notification action. */
@property (nonatomic, readonly) ToastPushMessage *message;

/** User input text for reply type action. */
@property (nonatomic, readonly, nullable) NSString *userText;

@end

NS_ASSUME_NONNULL_END
