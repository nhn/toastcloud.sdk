//
//  ToastInstanceLogger.h
//  ToastLogger
//
//  Created by Hyup on 2017. 9. 12..
//  Copyright © 2017년 NHNEnt. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "ToastLog.h"
#import "ToastLogFilter.h"
#import "ToastLoggerConfiguration.h"
#import "ToastLoggerDelegate.h"


@interface ToastInstanceLogger : NSObject

@property (weak, nonatomic) id<ToastLoggerDelegate> loggerDelegate;

+ (ToastInstanceLogger *)sharedInstanceWithConfiguration:(ToastLoggerConfiguration *)configuration;
- (ToastLoggerConfiguration *)configuration;

- (void)setUserFieldWithValue:(NSString *)value forKey:(NSString *)key;
 
#pragma mark - normal log
- (void)debug:(NSString *)message;
- (void)info:(NSString *)message;
- (void)warn:(NSString *)message;
- (void)error:(NSString *)message;
- (void)fatal:(NSString *)message;

#pragma mark - normal log (messageFormat)
- (void)debugWithFormat:(NSString *)format, ...;
- (void)infoWithFormat:(NSString *)format, ...;
- (void)warnWithFormat:(NSString *)format, ...;
- (void)errorWithFormat:(NSString *)format, ...;
- (void)fatalWithFormat:(NSString *)format, ...;

#pragma mark - normal log (userLogField)
- (void)debug:(NSString *)message userFields:(NSDictionary<NSString *, NSString *> *)userFields;
- (void)info:(NSString *)message userFields:(NSDictionary<NSString *, NSString *> *)userFields;
- (void)warn:(NSString *)message userFields:(NSDictionary<NSString *, NSString *> *)userFields;
- (void)error:(NSString *)message userFields:(NSDictionary<NSString *, NSString *> *)userFields;
- (void)fatal:(NSString *)message userFields:(NSDictionary<NSString *, NSString *> *)userFields;

#pragma mark - Type Setting log
- (void)debugWithLogType:(NSString *)logType message:(NSString *)message;
- (void)infoWithLogType:(NSString *)logType message:(NSString *)message;
- (void)warnWithLogType:(NSString *)logType message:(NSString *)message;
- (void)errorWithLogType:(NSString *)logType message:(NSString *)message;
- (void)fatalWithLogType:(NSString *)logType message:(NSString *)message;

#pragma mark - Type Setting log (userLogField)
- (void)debugWithLogType:(NSString *)logType format:(NSString *)format, ...;
- (void)infoWithLogType:(NSString *)logType format:(NSString *)format, ...;
- (void)warnWithLogType:(NSString *)logType format:(NSString *)format, ...;
- (void)errorWithLogType:(NSString *)logType format:(NSString *)format, ...;
- (void)fatalWithLogType:(NSString *)logType format:(NSString *)format, ...;

#pragma mark - Type Setting log (messageFormat)
- (void)debugWithLogType:(NSString *)logType message:(NSString *)message userFields:(NSDictionary<NSString *, NSString *> *)userFields;
- (void)infoWithLogType:(NSString *)logType message:(NSString *)message userFields:(NSDictionary<NSString *, NSString *> *)userFields;
- (void)warnWithLogType:(NSString *)logType message:(NSString *)message userFields:(NSDictionary<NSString *, NSString *> *)userFields;
- (void)errorWithLogType:(NSString *)logType message:(NSString *)message userFields:(NSDictionary<NSString *, NSString *> *)userFields;
- (void)fatalWithLogType:(NSString *)logType message:(NSString *)message userFields:(NSDictionary<NSString *, NSString *> *)userFields;

#pragma mark - User Log - private
- (void)userLog:(ToastLog*)log;

#pragma mark - Version
+ (NSString *)version;

@end




