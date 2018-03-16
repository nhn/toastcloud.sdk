//
//  TCISInstanceLogger.h
//  ToastLogger
//
//  Created by Hyup on 2017. 9. 12..
//  Copyright © 2017년 NHNEnt. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "TCISLog.h"
#import "TCISLogFilter.h"
#import "TCISLoggerConfiguration.h"
#import "TCISInternalLoggerDelegate.h"

@protocol TCISLoggerDelegate <NSObject>
@optional
- (void)instanceLogger:(TCISInstanceLogger *)instanceLogger
   didSendSuccessedLog:(TCISLog *)log;

- (void)instanceLogger:(TCISInstanceLogger *)instanceLogger
      didSendFailedLog:(TCISLog *)log
                 error:(NSError *)error;

- (void)instanceLogger:(TCISInstanceLogger *)instanceLogger
           didSavedLog:(TCISLog *)log;

- (void)instanceLogger:(TCISInstanceLogger *)instanceLogger
        didFilteredLog:(TCISLog *)log
             logFilter:(TCISLogFilter *)logFilter;
@end


@interface TCISInstanceLogger : NSObject

@property (weak, nonatomic) id<TCISLoggerDelegate> loggerDelegate;

+ (TCISInstanceLogger *)sharedInstance:(TCISLoggerConfiguration *)configuration;
- (TCISLoggerConfiguration *)configuration;

- (void)enablePrintLogToConsole:(BOOL) enable;
- (BOOL)isEnablePrintLogToConsole;

- (void)setUserLogField:(NSDictionary<NSString*, NSString*> *)addUserLogField;
- (void)setUserLogFieldWithValue:(NSString *)value forKey:(NSString *)key;
    
- (NSString *)userID;
- (void)setUserID:(NSString *) userID;

#pragma mark - normal log
- (void)debugWithLogTag:(NSString *)logTag message:(NSString *) message;
- (void)infoWithLogTag:(NSString *)logTag message:(NSString *) message;
- (void)warnWithLogTag:(NSString *)logTag message:(NSString *) message;
- (void)errorWithLogTag:(NSString *)logTag message:(NSString *) message;
- (void)fatalWithLogTag:(NSString *)logTag message:(NSString *) message;

#pragma mark - normal log (messageFormat)
- (void)debugWithLogTag:(NSString *)logTag messageFormat:(NSString *)messageFromat, ...;
- (void)infoWithLogTag:(NSString *)logTag messageFormat:(NSString *)messageFromat, ...;
- (void)warnWithLogTag:(NSString *)logTag messageFormat:(NSString *)messageFromat, ...;
- (void)errorWithLogTag:(NSString *)logTag messageFormat:(NSString *)messageFromat, ...;
- (void)fatalWithLogTag:(NSString *)logTag messageFormat:(NSString *)messageFromat, ...;

#pragma mark - normal log (userLogField)
- (void)debugWithLogTag:(NSString *)logTag message:(NSString *)message userLogField:(NSDictionary<NSString*, NSString*> *)userLogField;
- (void)infoWithLogTag:(NSString *)logTag message:(NSString *)message userLogField:(NSDictionary<NSString*, NSString*> *)userLogField;
- (void)warnWithLogTag:(NSString *)logTag message:(NSString *)message userLogField:(NSDictionary<NSString*, NSString*> *)userLogField;
- (void)errorWithLogTag:(NSString *)logTag message:(NSString *)message userLogField:(NSDictionary<NSString*, NSString*> *)userLogField;
- (void)fatalWithLogTag:(NSString *)logTag message:(NSString *)message userLogField:(NSDictionary<NSString*, NSString*> *)userLogField;

#pragma mark - Type Setting log
- (void)debugWithLogType:(NSString *)logType logTag:(NSString *)logTag message:(NSString *)message;
- (void)infoWithLogType:(NSString *)logType logTag:(NSString *)logTag message:(NSString *)message;
- (void)warnWithLogType:(NSString *)logType logTag:(NSString *)logTag message:(NSString *)message;
- (void)errorWithLogType:(NSString *)logType logTag:(NSString *)logTag message:(NSString *)message;
- (void)fatalWithLogType:(NSString *)logType logTag:(NSString *)logTag message:(NSString *)message;

#pragma mark - Type Setting log (userLogField)
- (void)debugWithLogType:(NSString *)logType logTag:(NSString *)logTag messageFormat:(NSString *)messageFromat, ...;
- (void)infoWithLogType:(NSString *)logType logTag:(NSString *)logTag messageFormat:(NSString *)messageFromat, ...;
- (void)warnWithLogType:(NSString *)logType logTag:(NSString *)logTag messageFormat:(NSString *)messageFromat, ...;
- (void)errorWithLogType:(NSString *)logType logTag:(NSString *)logTag messageFormat:(NSString *)messageFromat, ...;
- (void)fatalWithLogType:(NSString *)logType logTag:(NSString *)logTag messageFormat:(NSString *)messageFromat, ...;

#pragma mark - Type Setting log (messageFormat)
- (void)debugWithLogType:(NSString *)logType logTag:(NSString *)logTag message:(NSString *)message userLogField:(NSDictionary<NSString*, NSString*> *)userLogField;
- (void)infoWithLogType:(NSString *)logType logTag:(NSString *)logTag message:(NSString *)message userLogField:(NSDictionary<NSString*, NSString*> *)userLogField;
- (void)warnWithLogType:(NSString *)logType logTag:(NSString *)logTag message:(NSString *)message userLogField:(NSDictionary<NSString*, NSString*> *)userLogField;
- (void)errorWithLogType:(NSString *)logType logTag:(NSString *)logTag message:(NSString *)message userLogField:(NSDictionary<NSString*, NSString*> *)userLogField;
- (void)fatalWithLogType:(NSString *)logType logTag:(NSString *)logTag message:(NSString *)message userLogField:(NSDictionary<NSString*, NSString*> *)userLogField;

#pragma mark - User Log
- (void)userLog:(TCISLog*)log;

#pragma mark - private
//not supported user interface
- (void)internalCrash:(id) internalCrash;

#pragma mark - Version
+ (NSString *)version;

@end




