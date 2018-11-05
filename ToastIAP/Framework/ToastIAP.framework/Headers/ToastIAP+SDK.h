//
//  ToastIAP+SDK.h
//  ToastIAP
//
//  Created by Hyup on 2018. 9. 11..
//  Copyright © 2018년 NHN Entertainment Corp. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <ToastCore/ToastCore.h>
#import "ToastIAPConfiguration.h"
#import "ToastProduct.h"
#import "ToastProductsResponse.h"
#import "ToastPurchaseResult.h"

@protocol ToastInAppPurchaseDelegate;

NS_ASSUME_NONNULL_BEGIN

@interface ToastIAP : NSObject

// Delegate 설정
+ (void)setDelegate:(nullable id<ToastInAppPurchaseDelegate>)delegate;

// SDK 초기화
+ (void)initWithConfiguration:(ToastIAPConfiguration *)configuration;

+ (void)initWithConfiguration:(ToastIAPConfiguration *)configuration
                     delegate:(nullable id<ToastInAppPurchaseDelegate>)delegate;

// 상품 목록 조회
+ (void)requestProductsWithCompletionHandler:(nullable void (^)(ToastProductsResponse * _Nullable response, NSError * _Nullable error))completionHandler;

// 미소비 결제 내역 조회
+ (void)requestConsumablePurchasesWithCompletionHandler:(nullable void (^)(NSArray<ToastPurchaseResult *> * _Nullable purchases, NSError * _Nullable error))completionHandler;

// 상품 구매
+ (void)purchaseWithProduct:(ToastProduct *)product;

// 구매 복원
+ (void)restoreWithCompletionHandler:(nullable void (^)(NSArray<ToastPurchaseResult *> * _Nullable purchases, NSError * _Nullable error))completionHandler;

// 활성화된 구매 목록 조회
+ (void)requestActivePurchasesWithCompletionHandler:(nullable void (^)(NSArray<ToastPurchaseResult *> * _Nullable purchases, NSError * _Nullable error))completionHandler;

// SDK 버전 정보
+ (NSString *)version;

@end


@protocol ToastInAppPurchaseDelegate <NSObject>

// 결제 성공
- (void)didReceivePurchaseResult:(ToastPurchaseResult *)purchase;
// 결제 실패
- (void)didFailPurchaseProduct:(NSString *)productIdentifier withError:(NSError *)error;

@end

NS_ASSUME_NONNULL_END
