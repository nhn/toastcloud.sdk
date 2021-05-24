//
//  ToastFileCache.h
//  ToastCommon
//
//  Created by JooHyun Lee on 20/03/2020.
//  Copyright © 2020 NHN Corp. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ToastMemoryCache.h"

NS_ASSUME_NONNULL_BEGIN

@interface ToastFileCache : ToastMemoryCache <ToastCacheProtocol>

@property (nonatomic) NSURL *fileURL;
@property (nonatomic) BOOL iCloudBackupEnabled;

@end

NS_ASSUME_NONNULL_END
