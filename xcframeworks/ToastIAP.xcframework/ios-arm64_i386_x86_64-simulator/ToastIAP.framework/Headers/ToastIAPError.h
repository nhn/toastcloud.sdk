//
//  ToastIAPError.h
//  ToastIAP
//
//  Created by JooHyun Lee on 2018. 9. 12..
//  Copyright © 2018년 NHN. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

extern NSErrorDomain const ToastIAPErrorDomain;

/**
The error used in ToastIAP.
*/
typedef NS_ERROR_ENUM(ToastIAPErrorDomain, ToastIAPError) {
    ToastIAPErrorUnknown = 0,                       // 알수 없음
    ToastIAPErrorNotInitialized = 1,                // 초기화 하지 않음
    ToastIAPErrorStoreNotAvailable = 2,             // 스토어 사용 불가
    ToastIAPErrorProductNotAvailable = 3,           // 상품 정보 획득 실패
    ToastIAPErrorProductInvalid = 4,                // 원결제의 상품 아이디와 현재 상품 아이디 불일치
    ToastIAPErrorAlreadyOwned = 5,                  // 이미 소유한 상품
    ToastIAPErrorAlreadyInProgress = 6,             // 이미 진행중인 요청 있음
    ToastIAPErrorUserInvalid = 7,                   // 현재 사용자 아이디가 결제 사용자 아이디와 불일치
    ToastIAPErrorPaymentInvalid = 8,                // 결제 추가정보(ApplicationUsername) 획득 실패
    ToastIAPErrorPaymentCancelled = 9,              // 스토어 결제 취소
    ToastIAPErrorPaymentFailed = 10,                // 스토어 결제 실패
    ToastIAPErrorVerifyFailed = 11,                 // 영수증 검증 실패
    ToastIAPErrorChangePurchaseStatusFailed = 12,   // 구매 상태 변경 실패
    ToastIAPErrorPurchaseStatusInvalid = 13,        // 구매 진행 불가 상태
    ToastIAPErrorExpired = 14,                      // 구독 만료
    ToastIAPErrorRenewalPaymentNotFound = 15,       // 영수증내에 갱신 결제와 일치하는 결제 정보가 없음
    ToastIAPErrorRestoreFailed = 16,                // 복원 실패
    ToastIAPErrorPaymentNotAvailable = 17,          // 구매 진행 불가 상태 (e.g. 앱 내 구입 제한 설정)
};

NS_ASSUME_NONNULL_END
