//
//  ToastPushMedia.h
//  ToastPush
//
//  Created by JooHyun Lee on 2018. 11. 30..
//  Copyright © 2018년 NHN. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, ToastPushMediaType) {
    ToastPushMediaTypeImage,
    ToastPushMediaTypeVideo,
    ToastPushMediaTypeAudio,
};

typedef NS_ENUM(NSUInteger, ToastPushSourceType) {
    ToastPushSourceTypeRemote,
    ToastPushSourceTypeLocal,
};


@interface ToastPushMedia : NSObject

@property (nonatomic, readonly) ToastPushMediaType mediaType;

@property (nonatomic, readonly) NSString *source;

@property (nonatomic, readonly) ToastPushSourceType sourceType;

@property (nonatomic, readonly) NSString *extension;

@end

NS_ASSUME_NONNULL_END
