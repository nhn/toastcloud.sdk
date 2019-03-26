//
//  ToastPushError.h
//  ToastPush
//
//  Created by JooHyun Lee on 2018. 11. 30..
//  Copyright © 2018년 NHNEnt. All rights reserved.
//

static NSString *const ToastPushErrorDomain = @"com.toast.push";

/**
 The error used in ToastPush. 
 */
typedef NS_ENUM(NSUInteger, ToastPushErrorCode) {
    /** An unexpected error occured. */
    ToastPushErrorUnknown               = 0,    // 알수 없음
    /** An error caused by not initializing. */
    ToastPushErrorNotInitialize         = 1,    // 초기화하지 않음
    /** An error caused by user ID is invalid. */
    ToastPushErrorUserInvalid           = 2,    // 사용자 아이디 미설정
    /** An error that occurs due to failure to gain permission. */
    ToastPushErrorPermissionDenied      = 3,    // 권한 획득 실패
    /** An error that occurs in the system. */
    ToastPushErrorSystemFailed          = 4,    // 시스템 에러
    /** An error that occurs because the token value is missing or invalid. */
    ToastPushErrorTokenInvalid          = 5,    // 토큰 값이 없거나 유효하지 않음
    /** An error that occurs after performing another procedure already in progress. */
    ToastPushErrorAlreadyInProgress     = 6,    // 이미 진행중
    
    /** An error that occurs because the network is unavailable. */
    ToastPushErrorNetworkNotAvailable   = 100,  // 네트워크 사용 불가
    /** An error occurs because the HTTP status code is not 200. */
    ToastPushErrorNetworkFailed         = 101,  // HTTP Status Code 가 200이 아님
    /** An error that occurs due to a timeout. */
    ToastPushErrorTimeout               = 102,  // 타임아웃
    /** An error that occurs because the request parameters are invalid. */
    ToastPushErrorParameterInvalid      = 103,  // 요청 파라미터 오류
    /** An error that occurs because the server response is invalid. */
    ToastPushErrorResponseInvalid       = 104,  // 서버 응답 오류
};
