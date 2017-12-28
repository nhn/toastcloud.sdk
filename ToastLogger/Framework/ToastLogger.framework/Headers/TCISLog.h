//
//  TCISLog.h
//  ToastLogger
//
//  Created by Hyup on 2017. 10. 16..
//  Copyright © 2017년 NHNEnt. All rights reserved.
//

typedef enum {
    TCISLogLevel_DEBUG = 0,
    TCISLogLevel_INFO,
    TCISLogLevel_WARN,
    TCISLogLevel_ERROR,
    TCISLogLevel_FATAL
} TCISLogLevel;

#import <Foundation/Foundation.h>

@interface TCISLog : NSObject

@property (assign, nonatomic) TCISLogLevel logLevel;
@property (strong, nonatomic) NSString *logType;
@property (strong, nonatomic) NSString *logTag;
@property (strong, nonatomic) NSString *logMessage;
@property (strong, nonatomic) NSNumber *logCreateTime;
@property (strong, nonatomic) NSDictionary<NSString*, NSString*> *userLogField;
@property (strong, nonatomic) NSString *transactionID;

+ (instancetype)logLevel : (TCISLogLevel ) logLevel
                 logType : (NSString *) logType
                  logTag : (NSString *) logTag
              logMessage : (NSString *) logMessage
             userLogField : (NSDictionary<NSString*, NSString*> *) userLogField;

- (instancetype)initWithLogLevel : (TCISLogLevel ) logLevel
                         logType : (NSString *) logType
                          logTag : (NSString *) logTag
                      logMessage : (NSString *) logMessage
                     userLogField : (NSDictionary<NSString*, NSString*> *) userLogField;

@end
