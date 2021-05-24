//
//  ToastPushError.h
//  ToastPush
//
//  Created by JooHyun Lee on 2018. 11. 30..
//  Copyright © 2018년 NHN. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

extern NSErrorDomain const ToastPushErrorDomain;

/**
 The error used in ToastPush. 
 */
typedef NS_ERROR_ENUM(ToastPushErrorDomain, ToastPushError) {
    ToastPushErrorUnknown = 0,              // 알수 없음
    ToastPushErrorNotInitialized = 1,       // 초기화하지 않음
    ToastPushErrorUserInvalid = 2,          // 사용자 아이디 미설정
    ToastPushErrorPermissionDenied = 3,     // 권한 획득 실패
    ToastPushErrorSystemFailed = 4,         // 시스템에 의한 실패
    ToastPushErrorTokenInvalid = 5,         // 토큰 값이 없거나 유효하지 않음
    ToastPushErrorAlreadyInProgress = 6,    // 이미 진행중
    ToastPushErrorParameterInvalid = 7,     // 매계변수 오류
    ToastPushErrorNotSupported = 8,         // 지원하지 않는 기능
    ToaStPushErrorClientFailed = 9,         // 서버 오류
};

NS_ASSUME_NONNULL_END
