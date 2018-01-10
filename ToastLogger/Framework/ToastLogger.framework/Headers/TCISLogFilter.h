//
//  TCISLogFilter.h
//  ToastLogger
//
//  Created by Hyup on 2017. 9. 18..
//  Copyright © 2017년 NHNEnt. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TCISLog.h"

@interface TCISLogFilter : NSObject

- (BOOL)filter:(TCISLog *)log;

- (NSString *)name;

@end
