//
//  TCISDeviceIdentifier.h
//  ToastCommon
//
//  Created by Hyup on 2017. 8. 25..
//  Copyright © 2017년 NHNEnt. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface TCISDeviceIdentifier : NSObject

+ (NSString *)idfa;
+ (NSString *)idfv;
+ (NSString *)uuid;
+ (NSString *)uuidRef;

@end


