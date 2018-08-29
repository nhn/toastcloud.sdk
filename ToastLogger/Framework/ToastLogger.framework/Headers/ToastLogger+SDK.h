//
//  ToastLogger.h
//  ToastLogger
//
//  Created by Hyup on 2017. 9. 12..
//  Copyright © 2017년 NHNEnt. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "ToastLoggerConfiguration.h"
#import "ToastInstanceLogger.h"

@interface ToastLogger : NSObject

+ (void)initWithConfiguration:(ToastLoggerConfiguration *)configuration;

+ (ToastLoggerConfiguration *)loggerConfiguration;

+ (void)setDelegate:(id<ToastLoggerDelegate>) delegate;

+ (void)setUserFieldWithValue:(NSString *)value forKey:(NSString *)key;

+ (void)setShouldReportCrashHandler:(void (^)(void))handler;

+ (void)debug:(NSString *)message;
+ (void)info:(NSString *)message;
+ (void)warn:(NSString *)message;
+ (void)error:(NSString *)message;
+ (void)fatal:(NSString *)message;

+ (void)debug:(NSString *)message userFields:(NSDictionary<NSString *, NSString *> *)userFields;
+ (void)info:(NSString *)message userFields:(NSDictionary<NSString *, NSString *> *)userFields;
+ (void)warn:(NSString *)message userFields:(NSDictionary<NSString *, NSString *> *)userFields;
+ (void)error:(NSString *)message userFields:(NSDictionary<NSString *, NSString *> *)userFields;
+ (void)fatal:(NSString *)message userFields:(NSDictionary<NSString *, NSString *> *)userFields;

+ (void)debugWithFormat:(NSString *)format, ...;
+ (void)infoWithFormat:(NSString *)format, ...;
+ (void)warnWithFormat:(NSString *)format, ...;
+ (void)errorWithFormat:(NSString *)format, ...;
+ (void)fatalWithFormat:(NSString *)format, ...;


+ (void)userLog:(ToastLog *)log;

#pragma mark - Version
+ (NSString *)version;

@end
