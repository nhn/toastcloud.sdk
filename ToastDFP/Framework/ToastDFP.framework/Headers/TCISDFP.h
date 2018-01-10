//
//  TCISDFP.h
//  ToastDFP
//
//  Created by Hyup on 2017. 11. 27..
//  Copyright © 2017년 NHNEnt. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <ToastCommon/ToastCommon.h>
#import <ToastLogger/ToastLogger.h>

typedef NS_ENUM(NSInteger, TCISDFPPriority) {
    TCISDFPPriority_1 = 0,
    TCISDFPPriority_2,
    TCISDFPPriority_3,
    TCISDFPPriority_4,
    TCISDFPPriority_All
};

@interface TCISDFP : NSObject
+ (void)setConfigurationLogger:(TCISInstanceLogger *)logger;
+ (void)enableLocationData:(BOOL)enable;
+ (void)setPriority:(TCISDFPPriority)priority;
+ (void)addDFPValue:(NSString *)value key:(NSString *)key;
+ (void)removeDFPValueWithKey:(NSString *)key;
+ (void)removeDFPValues;
+ (void)setSendInterval:(NSUInteger)interval;

+ (NSString *)version;
@end
