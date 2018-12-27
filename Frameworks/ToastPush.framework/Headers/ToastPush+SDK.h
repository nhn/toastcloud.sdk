//
//  ToastPush+SDK.h
//  ToastPush
//
//  Created by JooHyun Lee on 2018. 11. 30..
//  Copyright © 2018년 NHNEnt. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UserNotifications/UserNotifications.h>
#import "ToastPushConfiguration.h"
#import "ToastPushAgreement.h"
#import "ToastPushTokenInfo.h"

NS_ASSUME_NONNULL_BEGIN

@protocol ToastPushDelegate;

@interface ToastPush : NSObject

// SDK 초기화
+ (void)initWithConfiguration:(ToastPushConfiguration *)configuration
                     delegate:(nullable id<ToastPushDelegate>)delegate;

// 토큰 등록 요청
+ (void)registerWithAgreement:(ToastPushAgreement *)agreement;

// 카테고리 설정
+ (void)setCategories:(nullable NSSet<UNNotificationCategory *> *)categories NS_AVAILABLE_IOS(10_0);

// 토큰 조회 요청
+ (void)requestTokenInfoForPushType:(ToastPushType)type
                  completionHandler:(nullable void (^) (ToastPushTokenInfo * _Nullable tokenInfo, NSError * _Nullable error))completionHandler;

// SDK 버전 획득
+ (NSString *)version;

@end


@protocol ToastPushDelegate <NSObject>

@optional

// 토큰 등록 성공
- (void)didRegisterWithDeviceToken:(NSString *)deviceToken
                           forType:(ToastPushType)type;

// 토큰 등록 실패
- (void)didFailToRegisterForType:(ToastPushType)type
                       withError:(NSError *)error;

// 푸쉬 메세지 수신
- (void)didReceivePushWithPayload:(NSDictionary *)payload
                          forType:(ToastPushType)type;

// 알림 액션 수신
- (void)didReceiveNotificationActionWithIdentifier:(NSString *)actionIdentifier
                                categoryIdentifier:(NSString *)categoryIdentifier
                                           payload:(NSDictionary *)payload
                                          userText:(nullable NSString *)userText;

@end

NS_ASSUME_NONNULL_END
