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

@interface ToastPurchaseResult : NSObject <NSCopying>

@property (nonatomic, copy, readonly) NSString *userID;
@property (nonatomic, copy, readonly) NSString *productIdentifier;
@property (nonatomic, assign, readonly) ToastProductType productType;
@property (nonatomic, copy, readonly) NSDecimalNumber *price;
@property (nonatomic, copy, readonly) NSString *currency;
@property (nonatomic, copy, readonly) NSString *paymentSeq;
@property (nonatomic, copy, readonly) NSString *accessToken;
@property (nonatomic, copy, readonly) NSString *transactionIdentifier;
@property (nonatomic, copy, readonly, nullable) NSString *originalTransactionIdentifier;
@property (nonatomic, readonly) NSTimeInterval purchaseTime;
@property (nonatomic, readonly) NSTimeInterval expiryTime;

@end

NS_ASSUME_NONNULL_END
