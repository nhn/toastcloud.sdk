//
//  ToastTaskQueue.h
//  ToastCommon
//
//  Created by JooHyun Lee on 2020/07/02.
//  Copyright © 2020 NHN Corp. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ToastAsyncTask.h"

NS_ASSUME_NONNULL_BEGIN

@interface ToastTaskQueue : NSObject

- (void)addTask:(ToastAsyncTask *)task;

- (void)removeTask:(ToastAsyncTask *)task;

@end

NS_ASSUME_NONNULL_END
