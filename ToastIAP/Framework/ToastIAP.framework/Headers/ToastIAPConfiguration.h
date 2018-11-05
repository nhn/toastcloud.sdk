//
//  ToastIAPConfiguration.h
//  ToastIAP
//
//  Created by Hyup on 2018. 9. 14..
//  Copyright © 2018년 NHN Entertainment Corp. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <ToastCore/ToastCore.h>

@interface ToastIAPConfiguration : NSObject

@property (strong, nonatomic, readonly) NSString *appKey;
@property (assign, nonatomic, readonly) ToastServiceZone serviceZone;

+ (ToastIAPConfiguration *)configurationWithAppKey:(NSString *)appKey;

+ (ToastIAPConfiguration *)configurationWithAppKey:(NSString *)appKey
                                       serviceZone:(ToastServiceZone)serviceZone;

@end
