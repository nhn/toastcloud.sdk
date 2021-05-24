//
//  ToastPushStyle.h
//  ToastPush
//
//  Created by JooHyun Lee on 08/10/2019.
//  Copyright © 2019 NHN Corp. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
# ToastPushStyle

A class that has information about notification's style.
*/
@interface ToastPushStyle : NSObject <NSCoding, NSCopying>

/// ---------------------------------
/// @name Properties
/// ---------------------------------

/** Wether to use html markup string. */
@property (nonatomic, readonly, getter=isUseHtml) BOOL useHtml;

@end

NS_ASSUME_NONNULL_END
