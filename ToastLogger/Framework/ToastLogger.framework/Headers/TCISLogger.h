//
//  TCISLogger.h
//  ToastLogger
//
//  Created by Hyup on 2017. 9. 12..
//  Copyright © 2017년 NHNEnt. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "TCISLoggerConfiguration.h"
#import "TCISInstanceLogger.h"

@interface TCISLogger : NSObject

+ (void)loggerConfiguration : (TCISLoggerConfiguration *)configuration;

+ (void)enablePrintLogToConsole : (BOOL)enable;

+ (void)setDelegate : (id<TCISLoggerDelegate>) delegate;

+ (void)setUserID : (NSString *)userID;

+ (void)addUserLogField : (NSDictionary<NSString*, NSString*> *)addUserLogField;

+ (void)debugWithLogTag:(NSString *)logTag message:(NSString *)message;
+ (void)infoWithLogTag:(NSString *)logTag message:(NSString *)message;
+ (void)warnWithLogTag:(NSString *)logTag message:(NSString *)message;
+ (void)errorWithLogTag:(NSString *)logTag message:(NSString *)message;
+ (void)fatalWithLogTag:(NSString *)logTag message:(NSString *)message;

+ (void)debugWithLogTag:(NSString *)logTag message:(NSString *)message userLogField:(NSDictionary<NSString*, NSString*> *)userLogField;
+ (void)infoWithLogTag:(NSString *)logTag message:(NSString *)message userLogField:(NSDictionary<NSString*, NSString*> *)userLogField;
+ (void)warnWithLogTag:(NSString *)logTag message:(NSString *)message userLogField:(NSDictionary<NSString*, NSString*> *)userLogField;
+ (void)errorWithLogTag:(NSString *)logTag message:(NSString *)message userLogField:(NSDictionary<NSString*, NSString*> *)userLogField;
+ (void)fatalWithLogTag:(NSString *)logTag message:(NSString *)message userLogField:(NSDictionary<NSString*, NSString*> *)userLogField;

+ (void)debugWithLogTag:(NSString *)logTag messageFormat:(NSString *)messageFromat, ...;
+ (void)infoWithLogTag:(NSString *)logTag messageFormat:(NSString *)messageFromat, ...;
+ (void)warnWithLogTag:(NSString *)logTag messageFormat:(NSString *)messageFromat, ...;
+ (void)errorWithLogTag:(NSString *)logTag messageFormat:(NSString *)messageFromat, ...;
+ (void)fatalWithLogTag:(NSString *)logTag messageFormat:(NSString *)messageFromat, ...;

+ (void)userLog : (TCISLog *)log;

+ (TCISInstanceLogger *)instanceLogger;
@end
