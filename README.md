## TOAST > TOAST SDK 사용 가이드 > 시작하기 > iOS

## 지원 환경

* iOS 8.0 이상
* XCode 최신 버전 (버전 9 이상)

## TOAST SDK의 구성

iOS 용 TOAST SDK의 구성은 다음과 같습니다.

* [TOAST Logger](https://docs.toast.com/ko/TOAST/ko/toast-sdk/log-collector-ios/)) SDK
* [TOAST In-app Purchase AppStore](https://docs.toast.com/ko/TOAST/ko/toast-sdk//iap-ios) SDK

TOAST SDK가 제공하는 서비스 중 원하는 기능을 선택하여 적용할 수 있습니다.

| Service  | Cocoapods Pod Name | Framework | Dependency | Build Settings |
| --- | --- | --- | --- | --- | 
| All | ToastSDK | ToastCore.framework<br/>ToastCommon.framework<br/>ToastLogger.framework<br/>ToastIAP.framework |  |  |
| Mandatory   | ToastCore<br/>ToastCommon | ToastCore.framework<br/>ToastCommon.framework | | OTHER_LDFLAGS = (<br/>    "-ObjC",<br/>    "-lc++" <br/>); |
| TOAST Log & Crash | ToastLogger | ToastLogger.framework | [External & Optional]<br/> * CrashReporter.framework | ENABLE_BITCODE = NO; |
| TOAST IAP | ToastIAP | ToastIAP.framework | [iOS]<br/> * StoreKit.framework<br/><br/>[Optional]<br/> * libsqlite3.tdb | |

## TOAST SDK를 Xcode 프로젝트에 적용하기

### 1. Cococapods을 사용해서 TOAST SDK 적용하기

Podfile을 생성하여 TOAST SDK에 대한 Pod을 추가합니다.

```podspec
platform :ios, '8.0'
use_frameworks!

target '{YOUR PROJECT TARGET NAME}' do
    pod 'ToastSDK'
end
```

생성된 Workspace를 열어 사용자고자하는 SDK를 Import 합니다.

```objc
#import <ToastCore/ToastCore.h>
#import <ToastLogger/ToastLogger.h>
#import <ToastIAP/ToastIAP.h>
```

### 2. 바이너리 다운로드로 TOAST SDK 적용하기

#### SDK import

TOAST의 [Downloads](https://docs.toast.com/ko/Download/#toast-sdk) 페이지에서 전체 iOS SDK를 다운로드 받을 수 있습니다.

![import_frameworks](http://static.toastoven.net/toastcloud/sdk/ios/overview_import_frameworks_folder.png)

TOAST Logger의 Crash Report 기능을 사용하기 위해서는 함께 배포되는 CrashReporter.framework도 프로젝트에 추가해야 합니다.

![import_external_framework](http://static.toastoven.net/toastcloud/sdk/ios/overview_import_external_folder.png)

프로젝트에 다음과 같이 Framework 들이 추가된 것을 확인합니다.

![import_frameworks_complete](http://static.toastoven.net/toastcloud/sdk/ios/overview_import_complete_folder.png)

> TOAST IAP를 사용하기 위해서는 StoreKit.framework를 추가로 Link해야 합니다.

![linked__storekit_frameworks](http://static.toastoven.net/toastcloud/sdk/ios/overview_link_frameworks_StoreKit.png)

![linked_frameworks](http://static.toastoven.net/toastcloud/sdk/ios/overview_link_frameworks_noAdSupport_IAP.png)


#### Project Settings

"Build Settings"의 "Other Linker Flags"에 "-lc++"와 "-ObjC" 항목을 추가합니다.

* Project Target - Build Settings - Linking - Other Linker Flags

![other_linker_flags](http://static.toastoven.net/toastcloud/sdk/ios/overview_settings_flags.png)

CrashReporter.framework를 직접 다운로드받거나 빌드한 경우에는 Build Setting의 Enable Bitcode의 값을 NO로 변경해야 합니다.

* Project Target - Build Settings - Build Options - Enable Bitcode - "NO"

![enable_bitcode](http://static.toastoven.net/toastcloud/sdk/ios/overview_settings_bitcode.png)
> TOAST의 [Downloads](https://docs.toast.com/ko/Download/#toast-sdk) 페이지에서 다운로드 받은 CrashReporter.framework는 bitCode를 지원합니다.

#### import framework 

사용하고자 하는 Framework를 import 합니다.

```objc
#import <ToastCore/ToastCore.h>
#import <ToastLogger/ToastLogger.h>
#import <ToastIAP/ToastIAP.h>
```

## UserID 설정하기

ToastSDK에 사용자 아이디를 설정할 수 있습니다.
설정한 UserID는 ToastSDK의 각 모듈에서 공통으로 사용됩니다.
ToastLogger의 로그 전송 API를 호출할 때마다 설정한 사용자 아이디를 로그와 함께 서버로 전송합니다.

### UserID API 명세

```objc
@interface ToastSDK : NSObject

//...

+ (void)setUserID:(NSString *)userID;

//...

@end
```

### UserID 설정 사용 예

```objc
[ToastSDK setUserID:@"TOAST-USER"];
```
## 디버그 모드 설정하기

TOAST SDK의 내부 로그 확인을 위해서 디버그 모드를 설정할 수 있습니다.
TOAST SDK 문의를 하실 경우, 디버그 모드를 활성화해서 전달해주시면 빠른 지원을 받을 수 있습니다.

### 디버그 모드 설정 API 명세


```objc
@interface ToastSDK : NSObject

//...

+ (void)setDebugMode:(BOOL)debugMode;

//...

@end
```

### 디버그 모드 설정 사용 예

```objc
// Set Debug Mode.
[ToastSDK setDebugMode:YES];// or NO
```

> (주의) 앱을 릴리즈할 경우, 반드시 디버그 모드를 비활성화 해야 합니다.

## TOAST Service 사용하기

* [TOAST Log & Crash](https://docs.toast.com/ko/TOAST/ko/toast-sdk/log-collector-ios/) 사용 가이드
* [TOAST In-app Purchase](https://docs.toast.com/ko/TOAST/ko/toast-sdk//iap-ios) 사용 가이드
