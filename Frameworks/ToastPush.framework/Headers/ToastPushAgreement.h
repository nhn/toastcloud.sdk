//
//  ToastPushAgreement.h
//  ToastPush
//
//  Created by JooHyun Lee on 2018. 12. 12..
//  Copyright © 2018년 NHNEnt. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ToastPushAgreement : NSObject

@property (nonatomic, assign) BOOL allowNotifications;
@property (nonatomic, assign) BOOL allowAdvertisements;
@property (nonatomic, assign) BOOL allowNightAdvertisements;

- (instancetype)initWithAllowNotifications:(BOOL)allowNotifications;

@end

NS_ASSUME_NONNULL_END
