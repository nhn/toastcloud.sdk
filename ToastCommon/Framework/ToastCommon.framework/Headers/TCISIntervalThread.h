//
//  TCISIntervalThread.h
//  ToastCommon
//
//  Created by JooHyun Lee on 2017. 12. 21..
//  Copyright © 2017년 NHNEnt. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface TCISIntervalThread : NSObject

@property (assign, nonatomic) NSTimeInterval lastExcuteTime;

- (id)initWithName:(NSString *)name interval:(NSUInteger)interval;
- (id)initWithInterval:(NSUInteger)interval;

- (BOOL)isRunning;
- (BOOL)isPause;
- (void)setInterval:(NSUInteger)interval;
- (NSUInteger)interval;
- (void)start;
- (void)startWithDelay:(NSUInteger)interval;
- (void)stop;
- (void)pause;
- (void)resume;
- (void)restart;

@end
