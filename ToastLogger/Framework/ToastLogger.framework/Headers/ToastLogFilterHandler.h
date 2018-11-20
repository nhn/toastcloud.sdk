//
//  ToastLogFilterHandler.h
//  ToastLogger
//
//  Created by Hyup on 2017. 9. 18..
//  Copyright © 2017년 NHNEnt. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ToastLoggerConfiguration.h"
#import "ToastLogFilter.h"

/**
 # ToastLogFilterHandler
 
 A class that manages to add ToastLogFilter according to ToastLoggerConfiguration.
 */
@interface ToastLogFilterHandler : NSObject

/**
 Add the log filter user want.

 @param logFilter The filter to add
 @param configuration The configuration about Toast Logger
 */
+ (void)addLogFilter:(ToastLogFilter * __nonnull)logFilter
     withLoggerConfiguration:(ToastLoggerConfiguration * __nonnull)configuration;

@end
