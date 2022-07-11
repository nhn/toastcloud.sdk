//
//  ToastLogFilterHandler.h
//  ToastLogger
//
//  Created by Hyup on 2017. 9. 18..
//  Copyright © 2017년 NHN. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ToastLoggerConfiguration.h"
#import "ToastLogFilter.h"

NS_ASSUME_NONNULL_BEGIN

/**
 # ToastLogFilterHandler
 
 A class that manages to add ToastLogFilter according to ToastLoggerConfiguration.
 */
//! Project version number for ToastUnityCommon.
__attribute__((deprecated("use NHNCloudLogFilterHandler instead.")))
@interface ToastLogFilterHandler : NSObject

/// ---------------------------------
/// @name Adding log filter
/// ---------------------------------

/**
 Add the log filter user want.

 @param logFilter The filter to add
 @param configuration The configuration about Toast Logger
 */
+ (void)addLogFilter:(nullable ToastLogFilter *)logFilter withLoggerConfiguration:(nullable ToastLoggerConfiguration *)configuration
__attribute__((deprecated("use NHNCloudLogFilterHandler instead. ToastLogFilterHandler addLogFilter:withLoggerConfiguration: is not working.")));

@end

NS_ASSUME_NONNULL_END
