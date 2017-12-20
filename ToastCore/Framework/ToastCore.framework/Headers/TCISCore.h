//
//  TCISCore.h
//  ToastCore
//
//  Created by Hyup on 2017. 9. 13..
//  Copyright © 2017년 NHNEnt. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface TCISCore : NSObject

+ (TCISCore *)sharedInstance;

+ (void)setDebugMode : (BOOL) debugMode;
+ (BOOL)isDebugMode;

+ (NSString *)version;

@end
