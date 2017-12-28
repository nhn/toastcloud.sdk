//
//  TCISJailbreakInfo.h
//  ToastCommon
//
//  Created by Hyup on 2017. 9. 7..
//  Copyright © 2017년 NHNEnt. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface TCISJailbreakInfo : NSObject

+ (NSArray *)detectionJailbreakFilePath;
+ (NSArray *)detectionJailbreakDyld;
+ (NSArray *)detectionJailbreakSymlinked;
+ (NSArray *)detectionJailbreakWritable;
+ (NSArray *)detectionJailbreakUrlSchemesOpenable;
+ (NSArray *)detectionJailbreakSystemCall;

@end
