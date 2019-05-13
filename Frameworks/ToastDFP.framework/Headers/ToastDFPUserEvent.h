//
//  ToastDFPUserEvent.h
//  ToastDFP
//
//  Created by JooHyun Lee on 2018. 1. 25..
//  Copyright © 2018년 NHN. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ToastDFPUserEvent : NSObject <NSCoding, NSCopying>

@property (nonatomic, copy, readonly) NSString *name;

@property (nonatomic, copy, readonly) NSDictionary<NSString *, id> *allValues;


+ (nullable instancetype)userEventWithName:(NSString *)name;

- (nullable instancetype)initWithName:(NSString *)name;

- (void)setValue:(nullable id)value forKey:(NSString *)key;

- (nullable id)valueForKey:(NSString *)key;

- (void)removeValueForKey:(NSString *)key;

- (void)removeAllValues;

@end

NS_ASSUME_NONNULL_END
