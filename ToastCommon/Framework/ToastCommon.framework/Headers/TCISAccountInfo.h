//
//  TCISAccountInfo.h
//  ToastCommon
//
//  Created by Hyup on 2017. 9. 7..
//  Copyright © 2017년 NHNEnt. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface TCISAccountInfo : NSObject

+ (TCISAccountInfo*)sharedInstance;

+ (NSString *)name;
@end
