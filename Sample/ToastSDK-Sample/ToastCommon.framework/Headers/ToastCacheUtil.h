//
//  ToastCacheUtil.h
//  ToastCommon
//
//  Created by JooHyun Lee on 2018. 1. 5..
//  Copyright © 2018년 NHNEnt. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface ToastCacheUtil : NSObject

+ (void)setObject:(id)value forKey:(NSString *)key;
+ (id)objectForKey:(NSString *)key;

@end
