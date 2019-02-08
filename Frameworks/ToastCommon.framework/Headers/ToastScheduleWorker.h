//
//  ToastScheduleWorker.h
//  ToastCommon
//
//  Created by JooHyun Lee on 2018. 5. 10..
//  Copyright © 2018년 NHNEnt. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ToastScheduleWorker : NSObject

@property (nonatomic, readonly) NSTimeInterval timeInterval;
@property (readonly) NSTimeInterval remainTimeInterval;
@property (readonly) NSTimeInterval lastExecuteTimeInterval;
@property (readonly, getter=isExecuting) BOOL executing;

- (instancetype)initWithTimeInterval:(NSTimeInterval)timeInterval
                        executeBlock:(nullable void (^) (void))executeBlock;

- (void)setExecuteBlock:(nullable void (^) (void))executeBlock;

- (void)resume;

- (void)suspend;

- (void)reset;

@end

NS_ASSUME_NONNULL_END
