//
//  ToastIAP+Additional.h
//  ToastIAP
//
//  Created by JooHyun Lee on 2018. 9. 27..
//  Copyright © 2018년 NHN Entertainment Corp. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ToastIAP+SDK.h"

NS_ASSUME_NONNULL_BEGIN

typedef void(^TIARequestHandler)(id _Nullable result, NSError * _Nullable error);

@interface ToastIAP (Additional)

+ (void)processesIncompletePurchasesWithCompletionHandler:(nullable TIARequestHandler)completionHandler;

+ (void)consumeWithPurchaseResult:(ToastPurchaseResult *)result
                completionHandler:(void (^)(NSError *error))completionHandler;

@end

NS_ASSUME_NONNULL_END
