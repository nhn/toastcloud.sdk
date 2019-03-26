//
//  ToastPurchaseResult.h
//  ToastIAP
//
//  Created by JooHyun Lee on 2018. 9. 12..
//  Copyright © 2018년 NHNEnt. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ToastProduct.h"
#import "ToastIAPConfiguration.h"

NS_ASSUME_NONNULL_BEGIN

// --no-merge-categories \

/**
 # ToastPurchaseResult
 
 The result of purchase.
 
 It used in
 
 * [ToastIAP requestConsumablePurchasesWithCompletionHandler:]
 * [ToastIAP restoreWithCompletionHandler:]
 * [ToastIAP requestActivePurchasesWithCompletionHandler:]
 * [ToastIAP consumeWithPurchaseResult:completionHandler:]
 * [ToastInAppPurchaseDelegate didReceivePurchaseResult:]
 
 */
@interface ToastPurchaseResult : NSObject <NSCoding, NSCopying>

/// ---------------------------------
/// @name Properties
/// ---------------------------------

/** The userID of purchase */
@property (nonatomic, copy, readonly) NSString *userID;

/** The product identifier of purchase */
@property (nonatomic, copy, readonly) NSString *productIdentifier;

/** The product type of purchase */
@property (nonatomic, readonly) ToastProductType productType;

/** The price of purchase */
@property (nonatomic, copy, readonly) NSDecimalNumber *price;

/** The currency of purchse */
@property (nonatomic, copy, readonly) NSString *currency;

/** The payment sequence of purchase(Issued from the IAP server) */
@property (nonatomic, copy, readonly) NSString *paymentSeq;

/** The access token of purchase */
@property (nonatomic, copy, readonly) NSString *accessToken;

/** The appstore transaction identifier of purchase */
@property (nonatomic, copy, readonly) NSString *transactionIdentifier;

/** The original transaction identifier of purchase(In case of auto-renewable-subscription) */
@property (nonatomic, copy, readonly, nullable) NSString *originalTransactionIdentifier;

/** The purchase time of purchase */
@property (nonatomic, readonly) NSTimeInterval purchaseTime;

/** The expiry time of purchse */
@property (nonatomic, readonly) NSTimeInterval expiryTime;

@end

NS_ASSUME_NONNULL_END
