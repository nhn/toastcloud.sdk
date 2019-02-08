//
//  ToastLoggerConfiguration.h
//  ToastLogger
//
//  Created by Hyup on 2017. 9. 29..
//  Copyright © 2017년 NHNEnt. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <ToastCore/ToastCore.h>
#import "ToastLoggerConfigurationSetting.h"

/**
 # ToastLoggerConfiguration
 
 The configuration used to initialize the ToastLogger SDK.
 */
@interface ToastLoggerConfiguration : NSObject

/// ---------------------------------
/// @name Properties
/// ---------------------------------

/** Log & Crasyh Search project key on the toast console */
@property (strong, nonatomic) NSString *projectKey;

/** configuration setting about Toast Logger */
@property (strong, nonatomic) ToastLoggerConfigurationSetting *setting;

/** Whether or not sending crash is enabled. */
@property (assign, nonatomic) BOOL enableCrashReporter;

#pragma mark - init Configuration
/// ---------------------------------
/// @name Initialize
/// ---------------------------------

/**
 Initialize a configuration with the given projectKey.

 @param projectKey Project key on the toast console
 @return A instance of ToastLoggerConfiguration
 */
+ (instancetype)configurationWithProjectKey:(NSString *)projectKey;


/**
 Initialize a configuration with the given projectKey and enableCrashReport.

 @param projectKey Project key on the toast console
 @param enableCrashReporter Whether or not sending crash is enabled
 @return A instance of ToastLoggerConfiguration
 */
+ (instancetype)configurationWithProjectKey:(NSString *)projectKey
                        enableCrashReporter:(BOOL)enableCrashReporter;

#pragma mark - init Detail Setting
/// ---------------------------------
/// @name Initialize (detail setting)
/// ---------------------------------

/**
 Initialize a configuration with the given projectKey, enableCrashReport and setting.

 @param projectKey Project key on the toast console
 @param enableCrashReporter Whether or not sending crash is enabled
 @param setting configuration setting about Toast Logger
 @return A instance of ToastLoggerConfiguration
 */
+ (instancetype)configurationWithProjectKey:(NSString *)projectKey
                        enableCrashReporter:(BOOL)enableCrashReporter
                                    setting:(ToastLoggerConfigurationSetting *)setting;

/**
 Initialize a configuration with the given projectKey, enableCrashReport and serviceZone.
 
 @param projectKey Project key on the toast console
 @param enableCrashReporter Whether or not sending crash is enabled
 @param serviceZone service zone of the toast console
 @return A instance of ToastLoggerConfiguration
 */
+ (instancetype)configurationWithProjectKey:(NSString *)projectKey
                        enableCrashReporter:(BOOL)enableCrashReporter
                                serviceZone:(ToastServiceZone)serviceZone;

/**
 Initialize a configuration with the given projectKey, enableCrashReport, setting and serviceZone.
 
 @param projectKey Project key on the toast console
 @param enableCrashReporter Whether or not sending crash is enabled
 @param setting configuration setting about Toast Logger
 @param serviceZone service zone of the toast console
 @return A instance of ToastLoggerConfiguration
 */
+ (instancetype)configurationWithProjectKey:(NSString *)projectKey
                        enableCrashReporter:(BOOL)enableCrashReporter
                                    setting:(ToastLoggerConfigurationSetting *)setting
                                serviceZone:(ToastServiceZone)serviceZone;

#pragma mark - ServiceZone
/// ---------------------------------
/// @name Set & Get service zone
/// ---------------------------------

/**
 Sets service zone of the toast console.

 @param serviceZone service zone of the toast console.(Real or Alpha or Beta)
 */
- (void)setLoggerServiceZone:(ToastServiceZone)serviceZone;

/**
 Gets service zone of the toast console.

 @return service zone of the toast console.(Real or Alpha or Beta)
 */
- (ToastServiceZone)loggerServiceZone;

@end



