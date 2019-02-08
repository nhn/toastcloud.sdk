//
//  ToastPushConfiguration.h
//  ToastPush
//
//  Created by JooHyun Lee on 2018. 11. 30..
//  Copyright © 2018년 NHNEnt. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <ToastCore/ToastCore.h>

typedef NSString *ToastPushType NS_STRING_ENUM;

/** When the type is not a specified value. */
extern ToastPushType const ToastPushTypeNone;

/** When the type is APNs. */
extern ToastPushType const ToastPushTypeAPNS;

/** When the type is VoIP. */
extern ToastPushType const ToastPushTypeVoIP;

NS_ASSUME_NONNULL_BEGIN

@interface ToastPushConfiguration : NSObject

/// ---------------------------------
/// @name Properties
/// ---------------------------------

/** The app key of Toast Console Project key. */
@property (nonatomic, copy, readonly) NSString *appKey;

/** The service zone. (Real or Alpha or Beta)  */
@property (nonatomic) ToastServiceZone serviceZone;

/** The pushTypes. (APNs or VoIP) */
@property (nonatomic, copy) NSSet<ToastPushType> *pushTypes;

/** Whther it is a sandbox environment or not. */
@property (nonatomic) BOOL sandbox;


/// ---------------------------------
/// @name Initializes
/// ---------------------------------

/**
 Initialize ToastPushConfiguration with a given appKey.

 @param appKey The app key of Toast Console Project key.
 @return The instance of ToastPushConfiguration.
 */
- (instancetype)initWithAppKey:(NSString *)appKey;

/**
 Initialize ToastPushConfiguration with a given appKey and pushTypes.

 @param appKey The app key of Toast Console Project key.
 @param pushTypes The pushType. (APNs or VoIP)
 @return The instance of ToastPushConfiguration.
 */
- (instancetype)initWithAppKey:(NSString *)appKey
                     pushTypes:(NSSet<ToastPushType> *)pushTypes;

@end

NS_ASSUME_NONNULL_END
