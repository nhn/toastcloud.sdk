//
//  ToastCollectorURL.h
//  ToastLogger
//
//  Created by Hyup on 2018. 4. 4..
//  Copyright © 2018년 NHNEnt. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef enum {
    ToastCollectorServiceZoneReal = 0,
    ToastCollectorServiceZoneAlpha
}ToastCollectorServiceZone;

@interface ToastCollectorURL : NSObject

+ (NSString *)collectorServerURLWithLoggerServiceZone:(ToastCollectorServiceZone)serviceZone;
+ (NSString *)settingsServerURLWithLoggerServiceZone:(ToastCollectorServiceZone)sserviceZone;

@end
