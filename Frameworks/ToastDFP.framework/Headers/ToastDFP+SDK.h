//
//  ToastDFP+SDK.h
//  ToastDFP
//
//  Created by Hyup on 2017. 11. 27..
//  Copyright © 2017년 NHN. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <ToastCore/ToastCore.h>
#import "ToastDFPUserEvent.h"

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, ToastDFPPriority) {
    ToastDFPPriority_All = 0,
    ToastDFPPriority_1,
    ToastDFPPriority_2,
    ToastDFPPriority_3,
    ToastDFPPriority_4,
};

@interface ToastDFP : NSObject

+ (BOOL)startService;
+ (void)stopService;

+ (void)setPriority:(ToastDFPPriority)priority;

+ (void)setUserFieldWithValue:(nullable NSString *)value forKey:(NSString *)key;
+ (void)removeUserFieldForKey:(NSString *)key;
+ (void)removeAllUserFields;
+ (BOOL)sendUserEvent:(nullable ToastDFPUserEvent *)event;

+ (NSString *)version;

@end

NS_ASSUME_NONNULL_END
