//
//  ToastLoggerDelegate.h
//  ToastLogger
//
//  Created by Hyup on 2018. 4. 5..
//  Copyright © 2018년 NHNEnt. All rights reserved.
//

#ifndef ToastLoggerDelegate_h
#define ToastLoggerDelegate_h

@class ToastInstanceLogger;

@protocol ToastLoggerDelegate <NSObject>

@optional
/**
 Called after the log has been successfully sent.

 @param log The log that sent successfully
 */
- (void)toastLogDidSuccess:(ToastLog *)log;

/**
 Called after the log fails to send.

 @param log The log that sent failed
 @param error The error about the cause of the failure
 */
- (void)toastLogDidFail:(ToastLog *)log error:(NSError *)error;

/**
 Called after the log has been successfully saved.

 @param log The log that saved successfully
 */
- (void)toastLogDidSave:(ToastLog *)log;

/**
 Called after the log has been successfully filtered.

 @param log The log that filtered successfully
 @param logFilter The filter used when filtering log
 */
- (void)toastLogDidFilter:(ToastLog *)log logFilter:(ToastLogFilter *)logFilter;

@end



#endif /* ToastLoggerDelegate_h */
