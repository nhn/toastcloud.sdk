//
//  ToastProduct.h
//  ToastIAP
//
//  Created by JooHyun Lee on 2018. 9. 12..
//  Copyright © 2018년 NHNEnt. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger, ToastProductType) {
    ToastProductTypeUnknown = 0,
    ToastProductTypeConsumable = 1,
    ToastProductTypeAutoRenewableSubscription = 2,
};

NS_ASSUME_NONNULL_BEGIN

@interface ToastProduct : NSObject

@property (nonatomic, copy, readonly) NSString *productIdentifier;
@property (nonatomic, copy, readonly, nullable) NSString *productName;
@property (nonatomic, readonly) ToastProductType productType;
@property (nonatomic, copy, readonly, nullable) NSDecimalNumber *price;
@property (nonatomic, copy, readonly, nullable) NSString *currency;
@property (nonatomic, copy, readonly, nullable) NSString *localizedPrice;
@property (nonatomic, assign, readonly) BOOL active;

- (BOOL)isActive;

@end

NS_ASSUME_NONNULL_END
