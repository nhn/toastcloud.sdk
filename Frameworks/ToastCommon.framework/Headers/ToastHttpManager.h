//
//  ToastHttpManager.h
//  ToastCommon
//
//  Created by Hyup on 2017. 9. 4..
//  Copyright © 2017년 NHN. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 Http request methods.

 - ToastHttpVerbTypeGET: The get method
 - ToastHttpVerbTypePOST: The post method
 */
typedef NS_ENUM(NSInteger, ToastHttpVerbType) {
    ToastHttpVerbTypeGET,
    ToastHttpVerbTypePOST,
    ToastHttpVerbTypeDELETE,
    ToastHttpVerbTypePUT,
    ToastHttpVerbTypePATCH
};

/**
 # Http Manager
 
 Class responsible for communicating with the server.
 
 */
@interface ToastHttpManager : NSObject

/// ---------------------------------
/// @name Properties
/// ---------------------------------

/** Response to the request  */
@property (nonatomic, copy, readonly) NSURLResponse *URLResponse;

/// ---------------------------------
/// @name Initialize
/// ---------------------------------

/**
 Initialize a httpManager with a given url and http request method.

 @param aURL The url to send the request
 @param aVerbType Http request method(get or post)
 @return Instance of ToastHttpManager
 */
+ (instancetype)requestWithURL:(NSURL *)aURL method:(ToastHttpVerbType)aVerbType;

/// ---------------------------------
/// @name Set Methods
/// ---------------------------------

/**
 Sets the timeout interval for the request.

 @param interval The request’s timeout interval, in seconds
 
 @note The default timeout interval is 5 seconds.
 */
- (void)setTimeoutInterval:(NSTimeInterval)interval;

/**
 Sets the key and value to be passed to the request header.

 @param key The key to be added to the request header.
 @param value The value to be added to the request header.
 */
- (void)setHeaderKey:(NSString *)key Value:(NSString *)value;

/**
 
 Sets the query string with a given key and value.

 @param key The key to be added to the query string.
 @param value The value to be added to the query string.
 
 @ note A query string is the part of a uniform resource locator (URL) which assigns values to specified parameters.
 */
- (void)setQueryStringParamKey:(NSString *)key Value:(NSString *)value;

/**
 Sets the json body for request.

 @param jsonObject The json object to be set the request body
 */
- (void)setJsonBodyParameter:(id)jsonObject;


/**
 Sets the string body parameter for request.

 @param parameter string body parameter to be set the request body
 */
- (void)setStringBodyParameter:(NSString *)parameter;

/// ---------------------------------
/// @name Networking
/// ---------------------------------

/**
 Sends the get request asynchronously.

 @param aBlock The block to execute after request is finished
 */
- (void)sendGetURLRequestWithCompletionBlock:(void (^)(NSData *aResponseData, NSDictionary *aResponseBody, NSError *aError))aBlock;

- (void)sendGetURLRequestWithPreporcess:(BOOL (^)(NSMutableURLRequest *request))preprocess
                        completionBlock:(void (^)(NSData *aResponseData, NSDictionary *aResponseBody, NSError *aError))aBlock;
/**
 Sends the post request with encoded data asynchronously.
 
 @param aBlock The block to execute after request is finished
 */
- (void)sendPostURLEncodeRequestWithCompletionBlock:(void (^)(NSData *aResponseData, NSDictionary *aResponseBody, NSError *aError))aBlock;


/**
 Sends the post request with json body asynchronously.
 
 @param aBlock The block to execute after request is finished
 */
- (void)sendPostJsonBodyRequestWithCompletionBlock:(void (^)(NSData *aResponseData, NSDictionary *aResponseBody, NSError *aError))aBlock;


- (void)sendPostJsonBodyRequestWithPreporcess:(BOOL (^)(NSMutableURLRequest *request))preprocess
                              completionBlock:(void (^)(NSData *aResponseData, NSDictionary *aResponseBody, NSError *aError))aBlock;

/**
 Sends the post request with string body parameter asynchronously.
 
 @param aBlock The block to execute after request is finished
 */
- (void)sendPostStringBodyRequestWithCompletionBlock:(void (^)(NSData *aResponseData, NSDictionary *aResponseBody, NSError *aError))aBlock;


/**
 Sends the get request with encoded data synchronously.

 @return The response to the request
 */
- (NSDictionary *)sendGetURLRequest;

/**
 Sends the post request with json body synchronously.
 
 @return The response to the request
 */
- (NSDictionary *)sendPostURLEncodeRequest;

/**
 Sends the post request with string body parameter synchronously.
 
 @return The response to the request
 */
- (NSDictionary *)sendPostJsonBodyRequest;

/**
 Sends the post request with string body parameter synchronously.
 
 @return The response to the request
 */
- (NSDictionary *)sendPostStringBodyRequest;

@end
