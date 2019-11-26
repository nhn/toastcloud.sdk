//
//  ToastPushRichMessage.h
//  ToastPush
//
//  Created by JooHyun Lee on 25/06/2019.
//  Copyright © 2019 NHN Corp. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ToastPushMedia.h"
#import "ToastPushButton.h"

NS_ASSUME_NONNULL_BEGIN

/**
# ToastPushRichMessage

A class that has information about rich message.
*/
@interface ToastPushRichMessage : NSObject <NSCoding, NSCopying>

/// ---------------------------------
/// @name Properties
/// ---------------------------------

/** Media information for rich message notification. */
@property (nonatomic, readonly, nullable) ToastPushMedia *media;

/** Button information for rich message notification. */
@property (nonatomic, readonly, nullable) NSArray<ToastPushButton *> *buttons;

@end

NS_ASSUME_NONNULL_END
