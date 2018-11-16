//
//  ToastLoggerConfiguration.h
//  ToastLogger
//
//  Created by Hyup on 2017. 9. 29..
//  Copyright © 2017년 NHNEnt. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "ToastLoggerConfigurationSetting.h"

typedef enum {
    ToastLoggerServiceZoneReal = 0,
    ToastLoggerServiceZoneAlpha
}ToastLoggerServiceZone;

@interface ToastLoggerConfiguration : NSObject

@property (strong, nonatomic) NSString *projectKey;
@property (strong, nonatomic) ToastLoggerConfigurationSetting *setting;
@property (assign, nonatomic) BOOL enableCrashReporter;

#pragma mark - init Configuration
+ (instancetype)configurationWithProjectKey:(NSString *)projectKey;

+ (instancetype)configurationWithProjectKey:(NSString *)projectKey
                        enableCrashReporter:(BOOL)enableCrashReporter;

#pragma mark - init Detail Setting
+ (instancetype)configurationWithProjectKey:(NSString *)projectKey
                        enableCrashReporter:(BOOL)enableCrashReporter
                                    setting:(ToastLoggerConfigurationSetting *)setting;

+ (instancetype)configurationWithProjectKey:(NSString *)projectKey
                        enableCrashReporter:(BOOL)enableCrashReporter
                                serviceZone:(ToastLoggerServiceZone)serviceZone;

+ (instancetype)configurationWithProjectKey:(NSString *)projectKey
                        enableCrashReporter:(BOOL)enableCrashReporter
                                    setting:(ToastLoggerConfigurationSetting *)setting
                                serviceZone:(ToastLoggerServiceZone)serviceZone;

#pragma mark - ServiceZone
- (void)setLoggerServiceZone:(ToastLoggerServiceZone)serviceZone;
- (ToastLoggerServiceZone)loggerServiceZone;

@end



