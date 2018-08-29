//
//  ToastLog.h
//  ToastLogger
//
//  Created by Hyup on 2017. 10. 16..
//  Copyright © 2017년 NHNEnt. All rights reserved.
//

typedef enum {
    ToastLogLevel_DEBUG = 0,
    ToastLogLevel_INFO,
    ToastLogLevel_WARN,
    ToastLogLevel_ERROR,
    ToastLogLevel_FATAL
} ToastLogLevel;

#import <Foundation/Foundation.h>

@interface ToastLog : NSObject

@property (strong, nonatomic) NSString *transactionID;
@property (assign, nonatomic) ToastLogLevel level;
@property (strong, nonatomic) NSString *type;
@property (strong, nonatomic) NSString *message;
@property (strong, nonatomic) NSNumber *createTime;
@property (strong, nonatomic) NSDictionary<NSString*, NSString*> *userFields;

+ (instancetype)logWithLevel:(ToastLogLevel)level
                        type:(NSString *)type
                     message:(NSString *)message
                  userFields:(NSDictionary<NSString*, NSString*> *)userFields;

- (instancetype)initWithLevel:(ToastLogLevel)level
                         type:(NSString *)type
                      message:(NSString *)message
                   userFields:(NSDictionary<NSString*, NSString*> *)userFields;

@end
