//
//  ToastLogFilter.h
//  ToastLogger
//
//  Created by Hyup on 2017. 9. 18..
//  Copyright © 2017년 NHNEnt. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ToastLog.h"

@interface ToastLogFilter : NSObject

- (BOOL)filter:(ToastLog *)log;

- (NSString *)name;

@end
