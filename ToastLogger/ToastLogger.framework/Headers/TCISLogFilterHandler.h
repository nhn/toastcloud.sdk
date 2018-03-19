//
//  TCISLogFilterHandler.h
//  ToastLogger
//
//  Created by Hyup on 2017. 9. 18..
//  Copyright © 2017년 NHNEnt. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TCISLoggerConfiguration.h"
#import "TCISLogFilter.h"

@interface TCISLogFilterHandler : NSObject

+ (void)addLogFilter:(TCISLogFilter * __nonnull)logFilter
     withLoggerConfiguration:(TCISLoggerConfiguration * __nonnull)configuration;

@end
