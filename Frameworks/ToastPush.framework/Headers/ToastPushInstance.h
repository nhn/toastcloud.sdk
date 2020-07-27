//
//  ToastPushInstance.h
//  ToastPush
//
//  Created by JooHyun Lee on 2020/04/06.
//  Copyright © 2020 NHN Corp. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ToastPushConfiguration.h"
#import "ToastPushAgreement.h"
#import "ToastPushTokenInfo.h"
#import "ToastPushTenant.h"
#import "ToastNotificationOptions.h"

NS_ASSUME_NONNULL_BEGIN

@interface ToastPushInstance : NSObject

@property (nonatomic, readonly) BOOL isDefaultInstance;
@property (nonatomic, readonly) ToastPushConfiguration *configuration;
@property (nonatomic, readonly) ToastNotificationOptions *notificationOptions;
@property (nonatomic, readonly, nullable) NSString *userID;
@property (nonatomic, readonly, nullable) ToastPushAgreement *agreement;
@property (nonatomic, readonly, nullable) ToastPushTenant *tenant;

/**
Get instance for app key.

@param appKey The app key.
*/
+ (nullable instancetype)sharedInstanceForAppKey:(NSString *)appKey
NS_SWIFT_NAME(shared(appKey:));

/**
Get instance with configuration.
 
If no instance exists, create and return instance.

@param configuration The configuration.
*/
+ (instancetype)sharedInstanceWithConfiguration:(ToastPushConfiguration *)configuration
NS_SWIFT_NAME(shared(configuration:));

- (void)setNotificationOptions:(nullable ToastNotificationOptions *)options
NS_SWIFT_NAME(setNotificationOptions(_:));

/**
Set the user identifier.

@param userID The user identifier.
*/
- (void)setUserID:(nullable NSString *)userID
NS_SWIFT_NAME(setUserID(_:));

/**
Set tenant information.

@param agreement The agreement information.
*/
- (void)setAgreement:(nullable ToastPushAgreement *)agreement
NS_SWIFT_NAME(setAgreement(_:));

/**
Set tenant information.

@param tenant The tenant information.
*/
- (void)setTenant:(nullable ToastPushTenant *)tenant
NS_SWIFT_NAME(setTenant(_:));

/**
Register the token.

@param pushType PushType (ToastPushTypeAPNS / ToastPushTypeVoIP)
@param completionHandler The completion handler for result.
*/
- (void)registerWithPushType:(ToastPushType)pushType
           completionHandler:(nullable void (^)(ToastPushTokenInfo * _Nullable tokenInfo, NSError * _Nullable error))completionHandler
NS_SWIFT_NAME(register(pushType:completion:));

/**
Queries the token's information.

@param pushType PushType (ToastPushTypeAPNS / ToastPushTypeVoIP)
@param completionHandler The completion handler for result.
*/
- (void)queryTokenInfoWithPushType:(ToastPushType)pushType
                 completionHandler:(void (^)(ToastPushTokenInfo * _Nullable tokenInfo, NSError * _Nullable error))completionHandler
NS_SWIFT_NAME(queryTokenInfo(pushType:completion:));

/**
Unregister the token.

@param pushType PushType (ToastPushTypeAPNS / ToastPushTypeVoIP)
@param completionHandler The completion handler for result.
*/
- (void)unregisterWithPushType:(ToastPushType)pushType
             completionHandler:(nullable void (^)(NSString * _Nullable deviceToken, NSError * _Nullable error))completionHandler
NS_SWIFT_NAME(unregister(pushType:completion:));

/**
Get user tag.

@param completionHandler The completion handler for result.
*/
- (void)getUserTagWithCompletionHandler:(void (^)(NSSet<NSString *> * _Nullable tagIdentifiers, NSError * _Nullable error))completionHandler
NS_SWIFT_NAME(getUserTag(completion:));

/**
Add tag identifiers to user tag.

@param tagIdentifiers The tag identifiers.
@param completionHandler The completion handler for result.
*/
- (void)addUserTagWithIdentifiers:(NSSet<NSString *> *)tagIdentifiers
                completionHandler:(nullable void (^)(NSSet<NSString *> * _Nullable tagIdentifiers, NSError * _Nullable error))completionHandler
NS_SWIFT_NAME(addUserTag(_:completion:));

/**
Set tag identifiers to user tag.

@param tagIdentifiers The tag identifiers.
@param completionHandler The completion handler for result.
*/
- (void)setUserTagWithIdentifiers:(NSSet<NSString *> *)tagIdentifiers
                completionHandler:(nullable void (^)(NSError * _Nullable error))completionHandler
NS_SWIFT_NAME(setUserTag(_:completion:));

/**
Remove tag identifiers from the user tag.

@param tagIdentifiers The tag identifiers.
@param completionHandler The completion handler for result.
*/
- (void)removeUserTagWithIdentifiers:(NSSet<NSString *> *)tagIdentifiers
                   completionHandler:(nullable void (^)(NSSet<NSString *> * _Nullable tagIdentifiers, NSError * _Nullable error))completionHandler
NS_SWIFT_NAME(removeUserTag(_:completion:));

/**
Remove all user tag.

@param completionHandler The completion handler for result.
*/
- (void)removeAllUserTagWithCompletionHandler:(nullable void (^)(NSError * _Nullable error))completionHandler
NS_SWIFT_NAME(removeAllUserTag(completion:));

@end

NS_ASSUME_NONNULL_END
