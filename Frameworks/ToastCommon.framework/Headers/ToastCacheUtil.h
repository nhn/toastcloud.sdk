//
//  ToastCacheUtil.h
//  ToastCommon
//
//  Created by JooHyun Lee on 2018. 1. 5..
//  Copyright © 2018년 NHNEnt. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 # Cache Util
 
 A utility used for caching. It is used as a singleton object.
 */
@interface ToastCacheUtil : NSObject

/// ---------------------------------
/// @name Set & Get Methods
/// ---------------------------------

/**
 Caches a given value and key via a safety check.

 @param value Value to save
 @param key Key to save.
 */
+ (void)setObject:(id)value forKey:(NSString *)key;


/**
 Gets the values stored in the cache through the given key.

 @param key The key used to retrieve the stored value
 @return The value found through the key
 */
+ (id)objectForKey:(NSString *)key;

@end
