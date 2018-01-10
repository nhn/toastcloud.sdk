//
//  TCISDFPUtil.h
//  ToastDFP
//
//  Created by JooHyun Lee on 2017. 12. 27..
//  Copyright © 2017년 NHNEnt. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TCISDFP.h"

@interface TCISDFPUtil : NSObject

+ (NSMutableDictionary *)getDFPDataWithPriority:(TCISDFPPriority)priority;

+ (void)enableLocation:(BOOL)enable;
+ (NSDictionary *)locationWithPriority:(TCISDFPPriority)priority;
+ (NSString *)dns;
+ (NSString *)gateway;

@end
