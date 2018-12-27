//
//  ToastDFPConfiguration.h
//  ToastDFP
//
//  Created by JooHyun Lee on 2018. 2. 21..
//  Copyright © 2018년 NHNEnt. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <ToastCore/ToastCore.h>

typedef NS_ENUM(NSInteger, ToastDFPServiceZone) {
    ToastDFPServiceZoneReal = 0,
    ToastDFPServiceZoneAlpha
};

typedef NS_ENUM(NSInteger, ToastDFPPriority) {
    ToastDFPPriority_All = 0,
    ToastDFPPriority_1,
    ToastDFPPriority_2,
    ToastDFPPriority_3,
    ToastDFPPriority_4,
};

@interface ToastDFPConfiguration : NSObject <NSCopying> 

@property (nonatomic, copy, readonly) NSString *projectKey;
@property (nonatomic, assign) ToastDFPPriority priority;
@property (nonatomic, assign) ToastDFPServiceZone serviceZone;
@property (nonatomic, assign, getter=isLocationServicesEnabled) BOOL locationServicesEnabled;

+ (instancetype)configurationWithProjectKey:(NSString *)projectKey;

- (instancetype)initWithProjectKey:(NSString *)projectKey;

@end
