//
//  ToastTimer.h
//  ToastPush
//
//  Created by JooHyun Lee on 2018. 12. 21..
//  Copyright © 2018년 NHNEnt. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ToastTimer : NSObject

@property (readonly) NSTimeInterval timeInterval;
@property (readonly) NSTimeInterval remainInterval;
@property (readonly, getter=isExecuting) BOOL executing;
@property (readonly, getter=isCanceled) BOOL canceled;
@property (readonly, getter=isFinished) BOOL finished;

- (instancetype)initWithTimeInterval:(NSTimeInterval)timeInterval
                     completionBlock:(nullable void (^) (void))completionBlock;

- (void)setCompletionBlock:(nullable void (^) (void))completionBlock;

- (void)resume;

- (void)suspend;

- (void)cancel;

@end

NS_ASSUME_NONNULL_END
