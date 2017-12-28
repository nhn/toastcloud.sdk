//
//  TCISInternalLoggerDelegate.h
//  ToastLogger
//
//  Created by Hyup on 2017. 10. 23..
//  Copyright © 2017년 NHNEnt. All rights reserved.
//

@class TCISInstanceLogger;

@protocol TCISInternalCrashLoggerDelegate <NSObject>

- (void)internalCrashLogger:(TCISInstanceLogger *)instanceLogger
   didSendSuccessedCrashLog:(TCISLog *)crashLog;

- (void)internalCrashLogger:(TCISInstanceLogger *)instanceLogger
      didSendFailedCrashLog:(TCISLog *)crashLog
                      error:(NSError *)error;

- (void)internalCrashLogger:(TCISInstanceLogger *)instanceLogger
           didSavedCrashLog:(TCISLog *)crashLog;

- (void)internalCrashLogger:(TCISInstanceLogger *)instanceLogger
        didFilteredCrashLog:(TCISLog *)crashLog
                  logFilter:(TCISLogFilter *)logFilter;
@end
