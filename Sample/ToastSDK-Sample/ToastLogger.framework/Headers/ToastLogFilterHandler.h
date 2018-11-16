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

@interface ToastLogFilterHandler : NSObject

+ (void)addLogFilter:(ToastLogFilter * __nonnull)logFilter
     withLoggerConfiguration:(ToastLoggerConfiguration * __nonnull)configuration;

@end
