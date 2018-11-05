//
//  ToastProductsResponse.h
//  ToastIAP
//
//  Created by JooHyun Lee on 2018. 9. 12..
//  Copyright © 2018년 NHNEnt. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ToastProduct.h"

NS_ASSUME_NONNULL_BEGIN

@interface ToastProductsResponse : NSObject

@property (nonatomic, readonly) NSArray<ToastProduct *> *products;
@property (nonatomic, readonly) NSArray<ToastProduct *> *invalidProducts;

@end

NS_ASSUME_NONNULL_END
