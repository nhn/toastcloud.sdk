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
    ToastPushMediaTypeImage NS_SWIFT_NAME(image) = 0,
    ToastPushMediaTypeVideo NS_SWIFT_NAME(video) = 1,
    ToastPushMediaTypeAudio NS_SWIFT_NAME(audio) = 2,
};

/**
# ToastPushMedia

A class that has information about media.
*/
@interface ToastPushMedia : NSObject <NSCoding, NSCopying>

/// ---------------------------------
/// @name Properties
/// ---------------------------------

/** Type of media. */
@property (nonatomic, readonly) ToastPushMediaType mediaType;

/** Source information of media. */
@property (nonatomic, readonly) NSString *source;

@end

NS_ASSUME_NONNULL_END
