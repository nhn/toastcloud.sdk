//
//  ToastHttpError.h
//  ToastCommon
//
//  Created by JooHyun Lee on 30/10/2019.
//  Copyright © 2019 NHN Corp. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

extern NSErrorDomain const ToastHttpErrorDomain;

typedef NS_ERROR_ENUM(ToastHttpErrorDomain, ToastHttpError) {
    ToastHttpErrorNetworkNotAvailable = 100,        // 네트워크 사용 불가
    ToastHttpErrorRequestFailed = 101,              // HTTP Status Code 가 200이 아니거나 서버에서 요청을 제대로 읽지 못함
    ToastHttpErrorRequestTimeout = 102,             // 타임아웃
    ToastHttpErrorRequestInvalid = 103,             // 잘못된 요청 (파라미터 오류 등)
    ToastHttpErrorURLInvalid = 104,                 // URL 오류
    ToastHttpErrorResponseInvalid = 105,            // 서버 응답 오류
    ToastHttpErrorAlreadyInprogress = 106,          // 동일 요청 이미 수행중
    ToastHttpErrorRequiresSecureConnection = 107,   // Allow Arbitrary Loads 미설정
};

NS_ASSUME_NONNULL_END
