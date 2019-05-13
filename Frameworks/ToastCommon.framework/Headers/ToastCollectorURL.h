//
//  ToastCollectorURL.h
//  ToastLogger
//
//  Created by Hyup on 2018. 4. 4..
//  Copyright © 2018년 NHN. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef enum {
    ToastCollectorServiceZoneReal = 0,
    ToastCollectorServiceZoneAlpha
}ToastCollectorServiceZone;

/**
 # Collector URL
 
 Provides the server URL according to the service zone.
 */
@interface ToastCollectorURL : NSObject

/// ---------------------------------
/// @name Gets the Server URL
/// ---------------------------------

/**
 Gets the collector server URL according to the service zone.

 @param serviceZone Servicezone(Real or Alpha)
 @return The collector server URL according to the service zone.
 */
+ (NSString *)collectorServerURLWithLoggerServiceZone:(ToastCollectorServiceZone)serviceZone;

/**
 Gets the setting server URL according to the service zone.
 
 @param serviceZone Servicezone(Real or Alpha)
 @return The collector server URL according to the service zone.
 */
+ (NSString *)settingsServerURLWithLoggerServiceZone:(ToastCollectorServiceZone)serviceZone;

@end
