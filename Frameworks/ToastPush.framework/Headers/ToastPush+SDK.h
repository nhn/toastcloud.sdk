//
//  ToastPush+SDK.h
//  ToastPush
//
//  Created by JooHyun Lee on 2018. 11. 30..
//  Copyright © 2018년 NHN. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UserNotifications/UserNotifications.h>
#import "ToastPushConfiguration.h"
#import "ToastPushAgreement.h"
#import "ToastPushTokenInfo.h"
#import "ToastPushMessage.h"
#import "ToastPushNotificationAction.h"

NS_ASSUME_NONNULL_BEGIN

typedef NS_OPTIONS(NSUInteger, ToastPushNotificationOptions) {
    ToastPushNotificationOptionBadge NS_SWIFT_NAME(badge) = (1 << 0),
    ToastPushNotificationOptionSound NS_SWIFT_NAME(sound) = (1 << 1),
    ToastPushNotificationOptionAlert NS_SWIFT_NAME(alert) = (1 << 2),
};


/**
 # ToastPushDelegate
 
 Delegate to receive notifications.
 */
@protocol ToastPushDelegate <NSObject>

@optional

// 알림 수신
/**
 Delegate the receiving notification.
 
 @param message The received notification's message.
 */
- (void)didReceiveNotificationWithMessage:(ToastPushMessage *)message
NS_SWIFT_NAME(didReceiveNotification(message:));

// 알림 실행
/**
 Delegate the receiving notification's response.
 
 @param message The message for notification that have received response.
 */
- (void)didReceiveNotificationResponseWithMessage:(ToastPushMessage *)message
NS_SWIFT_NAME(didReceiveNotificationResponse(message:));


// 알림 버튼 액션 수신
/**
 Delegate the receiving notification action.
 
 @param action The received notification action.
 */
- (void)didReceiveNotificationAction:(ToastPushNotificationAction *)action
NS_SWIFT_NAME(didReceiveNotificationAction(action:));

@end


/**
 # ToastPush
 
 SDK to manage remote notifications. (APNS)
 */
@interface ToastPush : NSObject

/// ---------------------------------
/// @name Initialize
/// ---------------------------------

/**
 Set the delegate for receiving notification.

 @param delegate The delegate.
*/
+ (void)setDelegate:(nullable id<ToastPushDelegate>)delegate
NS_SWIFT_NAME(setDelegate(_:));

/**
 Initialize SDK
 
 @param configuration The configuration.
*/
+ (void)initWithConfiguration:(ToastPushConfiguration *)configuration
NS_SWIFT_NAME(initialize(configuration:));

/**
 Initialize SDK

 @param configuration The configuration.
 @param delegate The delegate.
 */
+ (void)initWithConfiguration:(ToastPushConfiguration *)configuration
                     delegate:(nullable id<ToastPushDelegate>)delegate
NS_SWIFT_NAME(initialize(configuration:delegate:));

/// ---------------------------------
/// @name Push Methods
/// ---------------------------------

// 토큰 조회
/**
 Queries the token's information.
 
 Queries last registered token's information on the current device.
 
 @param completionHandler The completion handler for result.
 */
+ (void)queryTokenInfoWithCompletionHandler:(void (^)(ToastPushTokenInfo * _Nullable tokenInfo, NSError * _Nullable error))completionHandler
NS_SWIFT_NAME(queryTokenInfo(completion:));


// 토큰 등록
/**
 Register the token.
 
 Register the remote notification with APNS and register the received device token to the toast cloud server.
 
 @param agreement Whether or not to accept the notifications.
 @param completionHandler The completion handler for result.
 */
+ (void)registerWithAgreement:(ToastPushAgreement *)agreement
            completionHandler:(nullable void (^)(ToastPushTokenInfo * _Nullable tokenInfo, NSError * _Nullable error))completionHandler
NS_SWIFT_NAME(register(agreement:completion:));

/**
Register the token.

Register the remote notification with APNS and set the notification options and categories.
Then register the received device token to the toast cloud server.

@param agreement Whether or not to accept the notifications.
@param options Notification options (UNAuthorizationOptions or UIUserNotificationType)
@param completionHandler The completion handler for result.
*/
+ (void)registerWithAgreement:(ToastPushAgreement *)agreement
                      options:(ToastPushNotificationOptions)options
            completionHandler:(nullable void (^)(ToastPushTokenInfo * _Nullable tokenInfo, NSError * _Nullable error))completionHandler
NS_SWIFT_NAME(register(agreement:options:completion:));

/**
Register the token.

Register the remote notification with APNS and if the received device token is already registered with the toast cloud server, update the token's information with current configuration.

@param completionHandler The completion handler for result.
*/
+ (void)registerWithCompletionHandler:(nullable void (^)(ToastPushTokenInfo * _Nullable tokenInfo, NSError * _Nullable error))completionHandler
NS_SWIFT_NAME(register(completion:));

/**
Register the token.

Register the remote notification with APNS and set the notification options and categories.
Then if the received device token is already registered with the toast cloud server, update the token's information with current configuration.

@param options Notification options (UNAuthorizationOptions or UIUserNotificationType)
@param completionHandler The completion handler for result.
*/
+ (void)registerWithOptions:(ToastPushNotificationOptions)options
          completionHandler:(nullable void (^)(ToastPushTokenInfo * _Nullable tokenInfo, NSError * _Nullable error))completionHandler
NS_SWIFT_NAME(register(options:completion:));


// 토큰 삭제
/**
 Unregister the token.
 
 Unregister the token on the current device from the toast cloud server.
 
 @param completionHandler The completion handler for result.
 */
+ (void)unregisterWithCompletionHandler:(nullable void (^)(NSString * _Nullable deviceToken, NSError * _Nullable error))completionHandler
NS_SWIFT_NAME(unregister(completion:));

// 알림 카테고리 설정
/**
Set the notification categories.

Register notification categories in the notification center.

@param categories Set of notification categories
*/
+ (void)setNotificationCategories:(NSSet<UNNotificationCategory *> *)categories API_AVAILABLE(ios(10.0))
NS_SWIFT_NAME(setNotificationCategories(_:));

+ (void)setUserNotificationCategories:(NSSet<UIUserNotificationCategory *> *)categories
NS_SWIFT_NAME(setUserNotificationCategories(_:));

// 알림 카테고리 획득
/**
Get the notifications categories.

Get the notification categories registered in the notification center.

@param completionHandler The completion handler for result.
*/
+ (void)getNotificationCategoriesWithCompletionHandler:(void (^)(NSSet<UNNotificationCategory *> *categories))completionHandler API_AVAILABLE(ios(10.0))
NS_SWIFT_NAME(getNotificationCategories(completion:));

+ (void)getUserNotificationCategoriesWithCompletionHandler:(void (^)(NSSet<UIUserNotificationCategory *> * _Nullable categories))completionHandler
NS_SWIFT_NAME(getUserNotificationCategories(completion:));

// SDK 버전 획득
/**
 Gets the version of SDK.
 
 @return The version.
 */
+ (NSString *)version
NS_SWIFT_NAME(version());

@end

NS_ASSUME_NONNULL_END

