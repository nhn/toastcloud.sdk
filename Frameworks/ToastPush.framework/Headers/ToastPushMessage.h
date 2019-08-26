//
//  ToastPushMessage.h
//  ToastPush
//
//  Created by JooHyun Lee on 25/06/2019.
//  Copyright © 2019 NHN Corp. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ToastPushRichMessage.h"

NS_ASSUME_NONNULL_BEGIN

@interface ToastPushMessage : NSObject <NSCoding, NSCopying>

@property (nonatomic, readonly) NSString *identifier;

@property (nonatomic, readonly, nullable) NSString *title;

@property (nonatomic, readonly, nullable) NSString *body;

@property (nonatomic, readonly) NSInteger badge;

@property (nonatomic, readonly, nullable) NSString *sound;

@property (nonatomic, readonly, nullable) ToastPushRichMessage *richMessage;

@property (nonatomic, readonly) NSDictionary<NSString *, NSString *> *payload;

@end

NS_ASSUME_NONNULL_END
