//
//  ToastIAPConfiguration.h
//  ToastIAP
//
//  Created by Hyup on 2018. 9. 14..
//  Copyright © 2018년 NHN Entertainment Corp. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <ToastCore/ToastCore.h>

/**
 # ToastIAPConfiguration
 
 Configuration for ToastIAP SDK initialization.
 
 */
@interface ToastIAPConfiguration : NSObject

/** The app key of Toast Console Project Key */
@property (strong, nonatomic, readonly) NSString *appKey;

/** The service zone(Real or Alpha) */
@property (assign, nonatomic, readonly) ToastServiceZone serviceZone;

/**
 Initialize Toast IAP Configuration with a given app key.

 @param appKey The app key of Toast Console Project key
 @return The instance of ToastIAPConfiguration
 */
+ (ToastIAPConfiguration *)configurationWithAppKey:(NSString *)appKey;

/**
 Initialize Toast IAP Configuration with a given app key and service zone.

 @param appKey The app key of Toast Console Project Key
 @param serviceZone The service zone(Real or Alpha)
 @return The instance of ToastIAPConfiguration
 */
+ (ToastIAPConfiguration *)configurationWithAppKey:(NSString *)appKey
                                       serviceZone:(ToastServiceZone)serviceZone;

@end
