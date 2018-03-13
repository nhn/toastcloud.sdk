//
//  TCISLoggerConfiguration.h
//  ToastLogger
//
//  Created by Hyup on 2017. 9. 29..
//  Copyright © 2017년 NHNEnt. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "TCISLoggerConfigurationSetting.h"

typedef enum {
    TCISLoggerServiceZoneReal = 0,
    TCISLoggerServiceZoneAlpha
}TCISLoggerServiceZone;

@interface TCISLoggerConfiguration : NSObject

@property (strong, nonatomic) NSString *projectVersion;
@property (strong, nonatomic) NSString *projectKey;
@property (strong, nonatomic) TCISLoggerConfigurationSetting *setting;

#pragma mark - init Configuration
+ (instancetype)configurationWithProjectKey:(NSString *)projectKey
                             projectVersion:(NSString *)projectVersion;

+ (instancetype)configurationWithProjectKey:(NSString *)projectKey
                             projectVersion:(NSString *)projectVersion
                       configurationSetting:(TCISLoggerConfigurationSetting *)configurationSetting;

#pragma mark - init Configuration With ServiceZone
+ (instancetype)configurationWithProjectKey:(NSString *)projectKey
                             projectVersion:(NSString *)projectVersion
                          loggerServiceZone:(TCISLoggerServiceZone)loggerServiceZone;


+ (instancetype)configurationWithProjectKey:(NSString *)projectKey
                             projectVersion:(NSString *)projectVersion
                       configurationSetting:(TCISLoggerConfigurationSetting *)configurationSetting
                          loggerServiceZone:(TCISLoggerServiceZone)loggerServiceZone;

#pragma mark - ServiceZone
- (void)setLoggerServiceZone:(TCISLoggerServiceZone)loggerServicezZone;
- (TCISLoggerServiceZone)loggerServiceZone;

@end



