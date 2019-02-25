//
//  ToastScheduleTask.h
//  ToastPush
//
//  Created by JooHyun Lee on 2018. 12. 21..
//  Copyright © 2018년 NHNEnt. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface ToastScheduleTask : NSObject

@property (nonatomic, readonly) NSTimeInterval timeInterval;
@property (readonly) NSTimeInterval remainTimeInterval;

@property (readonly, getter=isExecuting) BOOL executing;
@property (readonly, getter=isCancelled) BOOL cancelled;
@property (readonly, getter=isFinished) BOOL finished;

- (instancetype)initWithTimeInterval:(NSTimeInterval)timeInterval
                   completionHandler:(nullable void (^) (void))completionBlock;

- (void)resume;

- (void)suspend;

- (void)cancel;

@end

NS_ASSUME_NONNULL_END
