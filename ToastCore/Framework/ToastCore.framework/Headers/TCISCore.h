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

+ (void)setUserID : (NSString *)userID;
+ (NSString *)userID;

+ (void)setDebugMode : (BOOL) debugMode;
+ (BOOL)isDebugMode;

@end
