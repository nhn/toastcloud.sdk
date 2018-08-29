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
- (void)toastLogDidSuccess:(ToastLog *)log;

- (void)toastLogDidFail:(ToastLog *)log error:(NSError *)error;

- (void)toastLogDidSave:(ToastLog *)log;

- (void)toastLogDidFilter:(ToastLog *)log logFilter:(ToastLogFilter *)logFilter;

@end



#endif /* ToastLoggerDelegate_h */
