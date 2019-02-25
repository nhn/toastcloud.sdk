//
//  ToastDFPUserEvent.h
//  ToastDFP
//
//  Created by JooHyun Lee on 2018. 1. 25..
//  Copyright © 2018년 NHNEnt. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface ToastDFPUserEvent : NSObject

@property (nonatomic, copy) NSString *name;

- (instancetype)initWithName:(NSString *)name;
+ (instancetype)userEventWithName:(NSString *)name;

- (void)setValue:(id)value forKey:(NSString *)key;
- (id)valueForKey:(NSString *)key;
- (void)removeValueForKey:(NSString *)key;
- (void)removeAllValues;
- (NSDictionary *)allValues;

@end
