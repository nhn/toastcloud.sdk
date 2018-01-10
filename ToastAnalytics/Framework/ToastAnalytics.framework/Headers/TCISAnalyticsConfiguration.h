//
//  TCISAnalyticsConfiguration.h
//  ToastAnalytics
//
//  Created by JooHyun Lee on 2017. 12. 27..
//  Copyright © 2017년 NHNEnt. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface TCISAnalyticsConfiguration : NSObject

@property (copy, nonatomic) NSString *appKey;
@property (copy, nonatomic) NSString *appVersion;
@property (copy, nonatomic) NSString *companyId;

+ (instancetype)configurationWithAppKey : (NSString *)appKey
                             appVersion : (NSString *)appVersion
                              companyId : (NSString *)companyId;

- (instancetype)initWithAppKey : (NSString *)appKey
                    appVersion : (NSString *)appVersion
                     companyId : (NSString *)companyId;

@end
