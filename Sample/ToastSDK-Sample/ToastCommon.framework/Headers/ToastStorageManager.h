//
//  ToastStorageManager.h
//  ToastLogger
//
//  Created by Hyup on 2017. 9. 11..
//  Copyright © 2017년 NHNEnt. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface ToastStorageManager : NSObject

- (BOOL)existsFileName:(NSString *)fileName;

- (void)saveArrayToFile:(NSMutableArray *) array
                saveKey:(NSString *)saveKey
              condition:(NSCondition *)condition
               fileName:(NSString *)fileName
            removeArray:(BOOL)removeArray;


- (void)fileToMemory:(NSMutableArray *)array
      arrayLimitSize:(NSNumber *)arrayLimitSize
            fileName:(NSString *)fileName
             saveKey:(NSString *)saveKey
           condition:(NSCondition *)condition
          removeFile:(BOOL)removeFile;

- (BOOL)removeFileName:(NSString *)fileName;

@end
