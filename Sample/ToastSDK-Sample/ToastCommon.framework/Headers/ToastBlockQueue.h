//
//  ToastBlockQueue.h
//  ToastLogger
//
//  Created by Hyup on 2017. 9. 11..
//  Copyright © 2017년 NHNEnt. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface ToastBlockQueue : NSObject

- (id)initWithQueueCapacity:(int)queueCapacity;

- (BOOL)queueEmpty;
- (NSUInteger)queueSize;
- (NSUInteger)queueCount;
- (id)queueFront;
- (id)queueBack;
- (void)queueEnqueue:(id)obj;
- (void)queueFrontEnqueue:(id)obj;
- (id)queueDequeue;

//Queue 저장이 필요할 경우 사용
- (void)queueSaveStorageWithFileName:(NSString *)fileName
                             saveKey:(NSString *)saveKey
                          projectKey:(NSString *)projectKey;

- (void)loadStorageToQueueWithFileName:(NSString *)fileName
                               saveKey:(NSString *)saveKey
                            projectKey:(NSString *)projectKey;

- (BOOL)removeQueueSaveFileWithFileName:(NSString *)fileName projectKey:(NSString *)projectKey;

@end
