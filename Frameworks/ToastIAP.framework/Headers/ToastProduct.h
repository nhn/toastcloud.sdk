//
//  ToastProduct.h
//  ToastIAP
//
//  Created by JooHyun Lee on 2018. 9. 12..
//  Copyright © 2018년 NHNEnt. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 The type of product.

 - ToastProductTypeUnknown: Unknown type
 - ToastProductTypeConsumable: Consumable type
 - ToastProductTypeAutoRenewableSubscription: Ayto renewable subscription type
 */
typedef NS_ENUM(NSInteger, ToastProductType) {
    ToastProductTypeUnknown = 0,
    ToastProductTypeConsumable = 1,
    ToastProductTypeAutoRenewableSubscription = 2,
};

NS_ASSUME_NONNULL_BEGIN

/**
 # ToastProduct
 
 The information of product.
 */
@interface ToastProduct : NSObject

/// ---------------------------------
/// @name Properties
/// ---------------------------------

/** The identifier of product */
@property (nonatomic, copy, readonly) NSString *productIdentifier;

/** The sequence of product. */
@property (nonatomic, assign, readonly) long productSeq;

/** The name of product */
@property (nonatomic, copy, readonly, nullable) NSString *productName;

/** The Type of product(consumable or auto-renewable-subscription) */
@property (nonatomic, readonly) ToastProductType productType;

/** The price of product */
@property (nonatomic, copy, readonly, nullable) NSDecimalNumber *price;

/** The currency of product */
@property (nonatomic, copy, readonly, nullable) NSString *currency;

/** The localized price of product */
@property (nonatomic, copy, readonly, nullable) NSString *localizedPrice;

/** If 'YES', the product is currently active. If 'NO', it is deactive. */
@property (nonatomic, assign, readonly) BOOL active;


/// ---------------------------------
/// @name Gets the isActive
/// ---------------------------------

/**
 Whether or not the product is active.

 @return If 'YES', the product is currently active. If 'NO', it is deactive
 */
- (BOOL)isActive;

@end

NS_ASSUME_NONNULL_END
