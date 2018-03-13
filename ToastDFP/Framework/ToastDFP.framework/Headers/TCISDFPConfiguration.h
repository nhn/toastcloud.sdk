//
//  TCISDFPConfiguration.h
//  ToastDFP
//
//  Created by JooHyun Lee on 2018. 2. 21..
//  Copyright © 2018년 NHNEnt. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger, TCISDFPServiceZone) {
    TCISDFPServiceZoneReal = 0,
    TCISDFPServiceZoneAlpha
};

typedef NS_ENUM(NSInteger, TCISDFPPriority) {
    TCISDFPPriority_1 = 0,
    TCISDFPPriority_2,
    TCISDFPPriority_3,
    TCISDFPPriority_4,
    TCISDFPPriority_All
};

@interface TCISDFPConfiguration : NSObject

@property (nonatomic, copy, readonly) NSString *projectKey;
@property (nonatomic, copy) NSString *projectVersion;
@property (nonatomic, assign) TCISDFPServiceZone serviceZone;
@property (nonatomic, assign) TCISDFPPriority priority;

- (instancetype)initWithProjectKey:(NSString *)projectKey;

- (instancetype)initWithProjectKey:(NSString *)projectKey
                       serviceZone:(TCISDFPServiceZone)serviceZone;

- (instancetype)initWithProjectKey:(NSString *)projectKey
                    projectVersion:(NSString *)projectVersion;

- (instancetype)initWithProjectKey:(NSString *)projectKey
                    priority:(TCISDFPPriority)priority;

- (instancetype)initWithProjectKey:(NSString *)projectKey
                    projectVersion:(NSString *)projectVersion
                       serviceZone:(TCISDFPServiceZone)serviceZone;

- (instancetype)initWithProjectKey:(NSString *)projectKey
                    projectVersion:(NSString *)projectVersion
                          priority:(TCISDFPPriority)priority;

- (instancetype)initWithProjectKey:(NSString *)projectKey
                       serviceZone:(TCISDFPServiceZone)serviceZone
                          priority:(TCISDFPPriority)priority;

- (instancetype)initWithProjectKey:(NSString *)projectKey
                    projectVersion:(NSString *)projectVersion
                       serviceZone:(TCISDFPServiceZone)serviceZone
                          priority:(TCISDFPPriority)priority;

+ (instancetype)configurationProjectKey:(NSString *)projectKey;

+ (instancetype)configurationWithProjectKey:(NSString *)projectKey
                                serviceZone:(TCISDFPServiceZone)serviceZone;

+ (instancetype)configurationWithProjectKey:(NSString *)projectKey
                             projectVersion:(NSString *)projectVersion;

+ (instancetype)configurationWithProjectKey:(NSString *)projectKey
                                   priority:(TCISDFPPriority)priority;

+ (instancetype)configurationWithProjectKey:(NSString *)projectKey
                             projectVersion:(NSString *)projectVersion
                                serviceZone:(TCISDFPServiceZone)serviceZone;

+ (instancetype)configurationWithProjectKey:(NSString *)projectKey
                             projectVersion:(NSString *)projectVersion
                                   priority:(TCISDFPPriority)priority;

+ (instancetype)configurationWithProjectKey:(NSString *)projectKey
                                serviceZone:(TCISDFPServiceZone)serviceZone
                                   priority:(TCISDFPPriority)priority;

+ (instancetype)configurationWithProjectKey:(NSString *)projectKey
                             projectVersion:(NSString *)projectVersion
                                serviceZone:(TCISDFPServiceZone)serviceZone
                                   priority:(TCISDFPPriority)priority;

@end
