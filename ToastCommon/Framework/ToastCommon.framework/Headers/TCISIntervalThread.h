//
//  TCISIntervalThread.h
//  ToastCommon
//
//  Created by JooHyun Lee on 2017. 12. 21..
//  Copyright © 2017년 NHNEnt. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef void(^ VoidBlock) (void);

@interface TCISIntervalThread : NSObject

@property (assign, nonatomic) NSTimeInterval lastExcuteTime;

- (instancetype)initWithName:(NSString *)name interval:(NSUInteger)interval block:(VoidBlock)block;
- (instancetype)initWithInterval:(NSUInteger)interval block:(VoidBlock)block;

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
- (void)reset;

@end
