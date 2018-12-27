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

extern ToastPushType const ToastPushTypeNone;
extern ToastPushType const ToastPushTypeAPNS;
extern ToastPushType const ToastPushTypeVoIP;

NS_ASSUME_NONNULL_BEGIN

@interface ToastPushConfiguration : NSObject

@property (nonatomic, copy, readonly) NSString *appKey;
@property (nonatomic) ToastServiceZone serviceZone;
@property (nonatomic, copy) NSSet<ToastPushType> *pushTypes;
@property (nonatomic) BOOL sandbox;

- (instancetype)initWithAppKey:(NSString *)appKey;

- (instancetype)initWithAppKey:(NSString *)appKey
                     pushTypes:(NSSet<ToastPushType> *)pushTypes;

@end

NS_ASSUME_NONNULL_END
