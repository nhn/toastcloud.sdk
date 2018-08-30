//
//  ToastLoggerConfigurationSetting.h
//  ToastLogger
//
//  Created by Hyup on 2017. 10. 18..
//  Copyright © 2017년 NHNEnt. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <ToastCommon/ToastCommon.h>
#import "ToastLog.h"

@interface ToastLoggerConfigurationSetting : NSObject

typedef enum {
    ToastLoggerConfigurationTypeDefault = 0,
    ToastLoggerConfigurationTypeConsole,
    ToastLoggerConfigurationTypeUser
} ToastLoggerConfigurationType;

+ (instancetype)defaultSetting;
+ (instancetype)consoleSetting;
+ (instancetype)userSettingWithEnableNormalLog:(BOOL)enableNormalLog
                                enableCrashLog:(BOOL)enableCrashLog
                          enableLogLevelFilter:(BOOL)enableLogLevelFilter
                                filterLogLevel:(ToastLogLevel)filterLogLevel
                           enableLogTypeFilter:(BOOL)enableLogTypeFilter
                            filterLogTypeArray:(NSArray *)filterLogTypeArray
                      enableLogDuplicateFilter:(BOOL)enableLogDuplicateFilter
                 filterLogDuplicateExpiredTime:(NSNumber *)filterLogDuplicateExpiredTime;

- (ToastLoggerConfigurationType)configurationType;

#pragma mark - Filter
- (BOOL)isEnableLogDuplicateFilter;
- (void)setEnableLogDuplicateFilter:(BOOL)enable;
- (NSNumber *)filterLogDuplicateExpiredTime;
- (void)setFilterLogDuplicateExpiredTime:(NSNumber *)filterLogDuplicateExpiredTime;

- (BOOL)isEnableLogLevelFilter;
- (void)setEnableLogLevelFilter:(BOOL)enable;
- (ToastLogLevel)filterLogLevel;
- (void)setFilterLogLevel:(ToastLogLevel)logLevel;

- (BOOL)isEnableLogTypeFilter;
- (void)setEnableLogTypeFilter:(BOOL)enable;
- (NSArray *)filterLogType;
- (void)setFilterLogType:(NSArray *)fiterLogType;

#pragma mark - Enable, Disable
- (BOOL)isEnableNormalLog;
- (void)enableNormalLog:(BOOL)enable;

- (BOOL)isEnableCrashLog;
- (void)enableCrashLog:(BOOL)enable;

#pragma mark - Collector
- (NSString *)collectorServerURL;
- (void)setCollectorServerURL:(NSString *)collectorServerURL;

- (NSString *)collectorServerVersion;
- (void)setCollectorServerVersion:(NSString *)collectorServerVersion;

@end

