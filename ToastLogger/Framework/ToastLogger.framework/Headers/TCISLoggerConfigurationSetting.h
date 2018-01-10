//
//  TCISLoggerConfigurationSetting.h
//  ToastLogger
//
//  Created by Hyup on 2017. 10. 18..
//  Copyright © 2017년 NHNEnt. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "TCISLog.h"

@interface TCISLoggerConfigurationSetting : NSObject

typedef enum {
    TCISLoggerConfigurationTypeDefault = 0,
    TCISLoggerConfigurationTypeConsole,
    TCISLoggerConfigurationTypeUser
} TCISLoggerConfigurationType;

+ (instancetype)defaultSetting;
+ (instancetype)consoleSetting;

+ (instancetype)userSettingWithEnableNormalLog:(BOOL)enableNormalLog
                                enableCrashLog:(BOOL)enableCrashLog
                          enableLogLevelFilter:(BOOL)enableLogLevelFilter
                                filterLogLevel:(TCISLogLevel)filterLogLevel
                           enableLogTypeFilter:(BOOL)enableLogTypeFilter
                            filterLogTypeArray:(NSArray *)filterLogTypeArray
                      enableLogDuplicateFilter:(BOOL)enableLogDuplicateFilter
                 filterLogDuplicateExpiredTime:(NSNumber *)filterLogDuplicateExpiredTime;

- (TCISLoggerConfigurationType)configurationType;

#pragma mark - URL
- (NSString *)collectorServerURL;
- (void)setCollectorServerURL:(NSString *)collectorServerURL;

- (NSString *)collectorServerVersion;
- (void)setCollectorServerVersion:(NSString *)collectorServerVersion;


#pragma mark - Filter
- (BOOL)isEnableLogDuplicateFilter;
- (void)setEnableLogDuplicateFilter:(BOOL)enable;
- (NSNumber *)filterLogDuplicateExpiredTime;
- (void)setFilterLogDuplicateExpiredTime:(NSNumber *)filterLogDuplicateExpiredTime;

- (BOOL)isEnableLogLevelFilter;
- (void)setEnableLogLevelFilter:(BOOL)enable;
- (TCISLogLevel)filterLogLevel;
- (void)setFilterLogLevel:(TCISLogLevel)logLevel;

- (BOOL)isEnableLogTypeFilter;
- (void)setEnableLogTypeFilter:(BOOL)enable;
- (NSArray *)filterLogType;
- (void)setFilterLogType : (NSArray *)fiterLogType;

#pragma mark - Enable, Disable
- (BOOL)isEnableNormalLog;
- (void)enableNormalLog:(BOOL) enable;

- (BOOL)isEnableCrashLog;
- (void)enableCrashLog:(BOOL) enable;

@end

