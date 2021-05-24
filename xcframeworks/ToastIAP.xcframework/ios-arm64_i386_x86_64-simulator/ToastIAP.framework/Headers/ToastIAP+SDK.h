//
//  ToastIAP+SDK.h
//  ToastIAP
//
//  Created by Hyup on 2018. 9. 11..
//  Copyright © 2018년 NHN Corp. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <ToastCore/ToastCore.h>
#import "ToastIAPConfiguration.h"
#import "ToastProduct.h"
#import "ToastProductsResponse.h"
#import "ToastPurchaseResult.h"
#import "ToastInAppPurchaseDelegate.h"

@protocol ToastInAppPurchaseDelegate;

NS_ASSUME_NONNULL_BEGIN

/**
 # ToastIAP
 
 SDK to manage in-app-purchase
 
 ## Initialize Precautions
 * ToastIAP SDK uses the UserID set in ToastSDK.
 * After you set the UserID, you need to initialize the ToastIAP Module.
 * At initialization, you must register the delegate to receive the payment result as mandatory.
 * After initialization, reprocessing for uncompleted payments and automatic renewal of Auto-Renewal Subscription occur.
 
 */
@interface ToastIAP : NSObject

/// ---------------------------------
/// @name Set Delegate(ToastInAppPurchaseDelegate)
/// ---------------------------------

/**
 Sets Delegate with a given delegate that following ToastInAppPurchaseDelegate

 @param delegate The delegate that following ToastInAppPurchaseDelegate
 */
+ (void)setDelegate:(nullable id<ToastInAppPurchaseDelegate>)delegate
NS_SWIFT_NAME(setDelegate(_:));

/// ---------------------------------
/// @name Initialize
/// ---------------------------------

/**
 Initialize SDK
 
 @param configuration The configuration about IAP
 */
+ (void)initWithConfiguration:(ToastIAPConfiguration *)configuration
NS_SWIFT_NAME(initialize(configuration:));

/**
 Initialize SDK

 @param configuration The configuration about IAP
 @param delegate The delegate to be executed according to the purchase result.
 */
+ (void)initWithConfiguration:(ToastIAPConfiguration *)configuration
                     delegate:(nullable id<ToastInAppPurchaseDelegate>)delegate
NS_SWIFT_NAME(initialize(configuration:delegate:));

/// ---------------------------------
/// @name IAP Methods
/// ---------------------------------

// 상품 목록 조회
/**
 Gets the list of products registered in IAP Console.

 @param completionHandler The handler to execute after the list of products is complete
 */
+ (void)requestProductsWithCompletionHandler:(nullable void (^)(ToastProductsResponse * _Nullable response, NSError * _Nullable error))completionHandler
NS_SWIFT_NAME(requestProducts(completion:));

// 미소비 결제 내역 조회
/**
 Gets the list of products that have not been paid out of the purchased consumable items.

 @param completionHandler The handler to execute after the list of products is complete
 */
+ (void)requestConsumablePurchasesWithCompletionHandler:(nullable void (^)(NSArray<ToastPurchaseResult *> * _Nullable purchases, NSError * _Nullable error))completionHandler
NS_SWIFT_NAME(requestConsumablePurchases(completion:));

// 상품 구매
/**
 Purchase a product acquired through the request. The purchase result is returned to the delegate.

 @param product The product to purchase
 */
+ (void)purchaseWithProduct:(ToastProduct *)product
NS_SWIFT_NAME(purchase(product:));

/**
 Purchase a product acquired through the request. The purchase result is returned to the delegate.
 
 @param product The product to purchase
 @param payload The developer's purchase payload
 */
+ (void)purchaseWithProduct:(ToastProduct *)product payload:(nullable NSString *)payload
NS_SWIFT_NAME(purchase(product:payload:));

// 구매 복원
/**
 Restore auto-renewable subscription products.
 Restores the transaction of the AppStore's auto-renewable subscription product and returns a list of active subscription products.

 @param completionHandler The handler to execute after the restore is complete.
 */
+ (void)restoreWithCompletionHandler:(nullable void (^)(NSArray<ToastPurchaseResult *> * _Nullable restoredPurchases, NSError * _Nullable error))completionHandler
NS_SWIFT_NAME(restore(completion:));

// 활성화된 구매 목록 조회
/**
 Gets a list of valid subscription items based on UserID, regardless of iOS or Android Store.

 @param completionHandler The handler to execute after the list of products is complete
 */
+ (void)requestActivePurchasesWithCompletionHandler:(nullable void (^)(NSArray<ToastPurchaseResult *> * _Nullable purchases, NSError * _Nullable error))completionHandler
NS_SWIFT_NAME(requestActivePurchases(completion:));

/// ---------------------------------
/// @name Gets the version
/// ---------------------------------

// SDK 버전 정보
/**
 Gets the version of SDK.

 @return The version of SDK
 */
+ (NSString *)version
NS_SWIFT_NAME(version());

@end




NS_ASSUME_NONNULL_END
