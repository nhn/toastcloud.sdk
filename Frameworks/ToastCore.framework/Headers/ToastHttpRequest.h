//
//  ToastHttpRequest.h
//  ToastCore
//
//  Created by JooHyun Lee on 2018. 12. 11..
//  Copyright © 2018년 NHNEnt. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <ToastCommon/ToastCommon.h>

static NSString *const ToastHttpErrorDomain = @"com.toast.core.http";

typedef NS_ENUM(NSUInteger, ToastHttpErrorCode) {
    ToastHttpErrorNetworkNotAvailable = 100,        // 네트워크 사용 불가
    ToastHttpErrorNetworkFailed = 101,              // HTTP Status Code 가 200이 아님
    ToastHttpErrorTimeout = 102,                    // 타임아웃
    ToastHttpErrorURLInvalid = 103,                 // URL 오류
    ToastHttpErrorResponseInvalid = 104,            // 서버 응답 오류
    ToastHttpErrorAlreadyInprogress = 105,          // 동일 요청 이미 수행중
    ToastHttpErrorRequiresSecureConnection = 106,   // App Transaport Security Setting -> Allow Arbitrary Loads 미설정
};

@class ToastHttpResponse;

@interface ToastHttpRequest : NSObject

@property (nonatomic, copy, readonly) NSString *identifier;
@property (nonatomic, copy, readonly) NSURL *URL;
@property (nonatomic, assign) ToastHttpVerbType method;
@property (nonatomic, copy) NSDictionary<NSString *, NSString *> *headers;
@property (nonatomic, copy) NSDictionary<NSString *, id> *body;
@property (nonatomic, assign) NSTimeInterval timeoutInterval;
@property (nonatomic, assign, readonly, getter=isExecuting) BOOL executing;

- (instancetype)initWithURL:(NSURL *)url;
- (instancetype)initWithURLString:(NSString *)urlString;

- (NSString *)methodString;

- (BOOL)canRequest;

- (void)appendPath:(NSString *)path;

- (void)setQueryParameter:(NSString *)value
                   forKey:(NSString *)key;

- (void)setFragment:(NSString *)fragment;

- (void)setHeader:(NSString *)value
           forKey:(NSString *)key;

- (ToastHttpResponse *)sync;

- (void)async:(void (^)(ToastHttpResponse *response))completionHandler;

@end


@interface ToastHttpResponse : NSObject

@property (nonatomic, copy, readonly) ToastHttpRequest *request;
@property (nonatomic, copy, readonly) NSDictionary<NSString *, NSString *> *headers;
@property (nonatomic, copy, readonly) NSString *mimeType;
@property (nonatomic, assign, readonly) BOOL isSuccessful;
@property (nonatomic, assign, readonly) NSInteger statusCode;
@property (nonatomic, assign, readonly) NSInteger resultCode;
@property (nonatomic, copy, readonly) NSString *resultMessage;
@property (nonatomic, copy, readonly) NSData *data;
@property (nonatomic, copy, readonly) NSDictionary<NSString *, id> *body;
@property (nonatomic, copy, readonly) NSError *error;

- (instancetype)initWithRequest:(ToastHttpRequest *)request
                       response:(NSHTTPURLResponse *)response
                           data:(NSData *)data
                          error:(NSError *)error;

@end

