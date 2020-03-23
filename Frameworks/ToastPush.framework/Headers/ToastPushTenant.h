//
//  ToastPushTenant.h
//  ToastPush
//
//  Created by JooHyun Lee on 11/03/2020.
//  Copyright © 2020 NHN Corp. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ToastPushTenant : NSObject <NSCoding, NSCopying>

@property (nonatomic, readonly) NSString *tenantIdentifier;
@property (nonatomic, nullable) NSString *userIdentifier;

- (instancetype)initWithTenantIdentifier:(NSString *)identifier;

@end

NS_ASSUME_NONNULL_END
