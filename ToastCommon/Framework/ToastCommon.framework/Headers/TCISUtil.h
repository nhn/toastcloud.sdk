//
//  TCISUtil.h
//  ToastCommon
//
//  Created by Hyup on 2017. 9. 13..
//  Copyright © 2017년 NHNEnt. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface TCISUtil : NSObject

#pragma mark - Version Util
+ (BOOL)isiOSVersion : (int)majorVersion orLater : (BOOL)later;

#pragma mark - Time Util
+ (uint64_t)unixEpochTime;

#pragma mark - Network Util
+ (NSString *)URLEncodedString : (NSString *)string;
+ (NSString *)URLEncodedStringWithData : (NSData *)data;

#pragma mark - Data Util 
+ (NSString *)hash_SHA1 : (NSString *)str;
+ (NSString *)hash_MD5 : (NSString *)str;
+ (NSString *)base64Encoding : (NSString *)source;

#pragma mark - Search Util
+ (BOOL)containsValueWithKey:(NSString *)key value:(id)value sourceArray:(NSArray *)sourceArray;
+ (NSArray *)containsArrayValueWithKey:(NSString *)key value:(id)value sourceArray:(NSArray *)sourceArray;

#pragma mark - String Util
+ (NSString *)createFileName:(NSString *)name key:(NSString *)key;
+ (NSString *)emptyStringToUnknown : (NSString *)value;
+ (NSString *)nilToEmptyString : (NSString *)value;
+ (NSString *)dictionaryToJsonString : (NSDictionary *)dictionary;

#pragma mark - Type Search Util
+ (BOOL)checkDictionaryInNSStringType : (NSDictionary *)dictionary ;



@end
