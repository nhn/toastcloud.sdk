//
//  ToastFieldKeyValidater.h
//  ToastCommon
//
//  Created by JooHyun Lee on 2018. 3. 23..
//  Copyright © 2018년 NHNEnt. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface ToastFieldValidator : NSObject

@property (strong, nonatomic) NSMutableArray *ignoreKeys;

- (NSDictionary *)validateFields:(NSDictionary *)fields;
- (NSString *)validateFieldKey:(NSString *)key;
- (NSString *)validateFieldValue:(id)value;
- (BOOL)isValidateFieldKey:(NSString *)key;

@end
