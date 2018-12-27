//
//  ToastPushError.h
//  ToastPush
//
//  Created by JooHyun Lee on 2018. 11. 30..
//  Copyright © 2018년 NHNEnt. All rights reserved.
//

#import <Foundation/Foundation.h>


static NSString *const ToastPushErrorDomain = @"com.toast.push";

typedef NS_ENUM(NSUInteger, ToastPushErrorCode) {
    ToastPushErrorUnknown               = 0,    // 알수 없음
    ToastPushErrorNotInitialize         = 1,    // 초기화하지 않음
    ToastPushErrorUserInvalid           = 2,    // 사용자 아이디 미설정
    ToastPushErrorPermissionDenied      = 3,    // 권한 획득 실패
    ToastPushErrorSystemFailed          = 4,    // 시스템 에러
    ToastPushErrorTokenInvalid          = 5,    // 토큰 값이 없거나 유효하지 않음
    ToastPushErrorAlreadyInProgress     = 6,    // 이미 진행중
    
    ToastPushErrorNetworkNotAvailable   = 100,  // 네트워크 사용 불가
    ToastPushErrorNetworkFailed         = 101,  // HTTP Status Code 가 200이 아님
    ToastPushErrorTimeout               = 102,  // 타임아웃
    ToastPushErrorParameterInvalid      = 103,  // 요청 파라미터 오류
    ToastPushErrorResponseInvalid       = 104,  // 서버 응답 오류
};
