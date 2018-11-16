//
//  ToastScheduleWorker.h
//  ToastCommon
//
//  Created by JooHyun Lee on 2018. 5. 10..
//  Copyright © 2018년 NHNEnt. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface ToastScheduleWorker : NSObject

@property (nonatomic, readonly) BOOL isPaused;
@property (nonatomic, readonly) BOOL isExecuting;
@property (nonatomic, readonly) NSDate *lastExecuteDate;
@property (nonatomic, readonly) NSTimeInterval interval;

- (instancetype)initWithInterval:(NSUInteger)interval;
- (instancetype)initWithInterval:(NSUInteger)interval block:(void(^)(void))block;
- (instancetype)initWithLabel:(NSString *)label;
- (instancetype)initWithLabel:(NSString *)label interval:(NSUInteger)interval;
- (instancetype)initWithLabel:(NSString *)label interval:(NSUInteger)interval block:(void(^)(void))block;

- (void)start;
- (void)startWithDelay:(NSUInteger)delay;
- (void)stop;

- (void)resume;
- (void)pause;

- (void)restart;
- (void)setInterval:(NSTimeInterval)interval;

- (NSTimeInterval)timeIntervalSinceLastExecute;

@end
