//
//  ToastLog.h
//  ToastLogger
//
//  Created by Hyup on 2017. 10. 16..
//  Copyright © 2017년 NHNEnt. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <ToastCore/ToastCore.h>

/**
 # Toastlog
 
 The information of log.
 
 There are methods to create a log.
 */
@interface ToastLog : NSObject


/// ---------------------------------
/// @name Properties
/// ---------------------------------

/** unique number of log */
@property (strong, nonatomic) NSString *transactionID;
/** level of log (debug, info, warn, error, fatal) */
@property (assign, nonatomic) ToastLogLevel level;
/** type of log*/
@property (strong, nonatomic) NSString *type;
/** message of log */
@property (strong, nonatomic) NSString *message;
/** created time of log (unix epoch) */
@property (strong, nonatomic) NSNumber *createTime;
/** additional fileds(key, value) of log */
@property (strong, nonatomic) NSDictionary<NSString*, NSString*> *userFields;



/// ---------------------------------
/// @name Craete ToastLog
/// ---------------------------------


/**
 Create ToastLog instance with the given level, type, message and userFields.

 @param level The level of log
 @param type The type of log
 @param message The message of log
 @param userFields The userFields of log
 @return The instance of a ToastLog
 */
+ (instancetype)logWithLevel:(ToastLogLevel)level
                        type:(NSString *)type
                     message:(NSString *)message
                  userFields:(NSDictionary<NSString*, NSString*> *)userFields;



/// ---------------------------------
/// @name Initialize with parameters
/// ---------------------------------

/**
 Initialize log with the given level, type, message and userFields.
 
 @param level The level of log
 @param type The type of log
 @param message The message of log
 @param userFields The userFields of log
 @return The instance of a ToastLog
 */
- (instancetype)initWithLevel:(ToastLogLevel)level
                         type:(NSString *)type
                      message:(NSString *)message
                   userFields:(NSDictionary<NSString*, NSString*> *)userFields;

@end