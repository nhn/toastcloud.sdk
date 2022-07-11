//
//  ToastPushTenant.h
//  ToastPush
//
//  Created by JooHyun Lee on 11/03/2020.
//  Copyright © 2020 NHN Corp. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

__attribute__((deprecated("use NHNCloudPushTenantSeparator instead.")))
extern NSString *const ToastPushTenantSeparator;

__attribute__((deprecated("use NHNCloudPushTenant instead.")))
@interface ToastPushTenant : NSObject <NSCoding, NSCopying>

@property (nonatomic, readonly) NSString *tenantIdentifier;
@property (nonatomic, nullable) NSString *userIdentifier;

- (instancetype)init NS_UNAVAILABLE;

- (instancetype)initWithTenantIdentifier:(NSString *)identifier;

@end

NS_ASSUME_NONNULL_END
