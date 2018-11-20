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

/**
 # ToastLoggerConfigurationSetting
 
 The configuration setting about ToastLogger.
 
 There are three kinds of settings.
 
 * default setting (Set to the default setting.)
 * console setting (Get and set the settings you set in the Toast Console.)
 * user setting (Set it as you want.)
 
 */
@interface ToastLoggerConfigurationSetting : NSObject

typedef enum {
    ToastLoggerConfigurationTypeDefault = 0,
    ToastLoggerConfigurationTypeConsole,
    ToastLoggerConfigurationTypeUser
} ToastLoggerConfigurationType;

/**
 Gets the instance of ToastLoggerConfigurationSetting with the type set to the default.

 @return The instance of ToastLoggerConfigurationSetting with the type set to the default.
 */
+ (instancetype)defaultSetting;

/**
 Gets the instance of ToastLoggerConfigurationSetting with the type set to the console.
 
 @return The instance of ToastLoggerConfigurationSetting with the type set to the console.
 */
+ (instancetype)consoleSetting;


/**
 Gets the instance of ToastLoggerConfigurationSetting with the user's setting values.

 @param enableNormalLog If `YES`, enables sending normal log. If `NO`, disable it.
 @param enableCrashLog If `YES`, enables sending crash log. If `NO`, disable it.
 @param enableLogLevelFilter If `YES`, enables filtering by log level. If `NO`, disable it.
 @param filterLogLevel The log level to filter. (If this value set to 'warn', only warn, error and fatal can be sent)
 @param enableLogTypeFilter If `YES`, enables filtering by log type. If `NO`, disable it.
 @param filterLogTypeArray The log types to filter. The types in this array are not sent.
 @param enableLogDuplicateFilter If `YES`, enables filtering the same log. If `NO`, disable it.
 @param filterLogDuplicateExpiredTime Time to check for duplicate logs.(2 - 120 second)
 @return The instance of ToastLoggerConfigurationSetting with the type set to the user values.
 */
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
/**
 Whether or not duplicate log filter is enabled.

 @return If `YES`, enables filtering the same log. If `NO`, disable it.
 */
- (BOOL)isEnableLogDuplicateFilter;

/**
 Sets whether duplicate log filter is enabled or disabled.

 @param enable If `YES`, enables filtering the same log. If `NO`, disable it.
 */
- (void)setEnableLogDuplicateFilter:(BOOL)enable;


/**
 Gets the time to check for duplicate logs

 @return Time to check for duplicate logs.(2 - 120 second)
 */
- (NSNumber *)filterLogDuplicateExpiredTime;


/**
 Sets the time to check for duplicate logs

 @param filterLogDuplicateExpiredTime Time to check for duplicate logs.(2 - 120 second)
 */
- (void)setFilterLogDuplicateExpiredTime:(NSNumber *)filterLogDuplicateExpiredTime;

/**
 Whether or not log level filter is enabled.

 @return If `YES`, enables filtering by log level. If `NO`, disable it.
 */
- (BOOL)isEnableLogLevelFilter;


/**
 Sets whether log level filter is enabled or disabled.

 @param enable If `YES`, enables filtering by log level. If `NO`, disable it.
 */
- (void)setEnableLogLevelFilter:(BOOL)enable;


/**
 Gets the log level to filter.

 @return The log level to filter. (If this value set to 'warn', only warn, error and fatal can be sent)
 */
- (ToastLogLevel)filterLogLevel;


/**
 Sets the log level to filter.

 @param logLevel The log level to filter. (If this value set to 'warn', only warn, error and fatal can be sent)
 */
- (void)setFilterLogLevel:(ToastLogLevel)logLevel;

/**
 Whether or not log type filter is enabled.

 @return If `YES`, enables filtering by log type. If `NO`, disable it.
 */
- (BOOL)isEnableLogTypeFilter;


/**
 Sets whether or not log type filter is enabled.

 @param enable If `YES`, enables filtering by log type. If `NO`, disable it.
 */
- (void)setEnableLogTypeFilter:(BOOL)enable;

/**
 Gets the log types to filter. The types in this array are not sent.

 @return The log types to filter. The types in this array are not sent.
 */
- (NSArray *)filterLogType;


/**
 Sets the log types to filter. The types in this array are not sent.

 @param fiterLogType The log types to filter. The types in this array are not sent.
 */
- (void)setFilterLogType:(NSArray *)fiterLogType;

#pragma mark - Enable, Disable
/**
 Whether or not sending normal log is enabled.

 @return If `YES`, enables sending normal log. If `NO`, disable it.
 */
- (BOOL)isEnableNormalLog;

/**
 Sets whether or not sending normal log is enabled.

 @param enable If `YES`, enables sending normal log. If `NO`, disable it.
 */
- (void)enableNormalLog:(BOOL)enable;


/**
 Whether or not sending crash log is enabled.
 
 @return If `YES`, enables sending crash log. If `NO`, disable it.
 */
- (BOOL)isEnableCrashLog;

/**
 Sets whether or not sending crash log is enabled.
 
 @param enable If `YES`, enables sending crash log. If `NO`, disable it.
 */
- (void)enableCrashLog:(BOOL)enable;

#pragma mark - Collector
/**
 Gets the url of collector server.

 @return url of collector server
 */
- (NSString *)collectorServerURL;

/**
 Sets the url of collector server.

 @param collectorServerURL url of collector server
 */
- (void)setCollectorServerURL:(NSString *)collectorServerURL;

/**
 Gets the version of collector server.

 @return version of collector server
 */
- (NSString *)collectorServerVersion;

/**
 Sets the version of collector server.

 @param collectorServerVersion version of collector server
 */
- (void)setCollectorServerVersion:(NSString *)collectorServerVersion;

@end

