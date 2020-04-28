## TOAST > TOAST SDK 사용 가이드 > 시작하기 > iOS

## 지원 환경

* iOS 9.0 이상
* XCode 최신 버전(버전 10 이상)

## TOAST SDK의 구성

iOS용 TOAST SDK의 구성은 다음과 같습니다.

* [TOAST Logger](https://docs.toast.com/ko/TOAST/ko/toast-sdk/log-collector-ios/) SDK
* [TOAST In-app Purchase AppStore](https://docs.toast.com/ko/TOAST/ko/toast-sdk/iap-ios/) SDK
* [TOAST Push](https://docs.toast.com/ko/TOAST/ko/toast-sdk/push-ios/) SDK

TOAST SDK가 제공하는 서비스 중 원하는 기능을 선택해 적용할 수 있습니다.

| Service  | Cocoapods Pod Name | Framework | Dependency | Build Settings |
| --- | --- | --- | --- | --- | 
| All | ToastSDK | ToastCore.framework<br/>ToastCommon.framework<br/>ToastLogger.framework<br/>ToastIAP.framework |  |  |
| Mandatory   | ToastCore<br/>ToastCommon | ToastCore.framework<br/>ToastCommon.framework | | OTHER_LDFLAGS = (<br/>    "-ObjC",<br/>    "-lc++" <br/>); |
| TOAST Log & Crash | ToastLogger | ToastLogger.framework | [External & Optional]<br/> * CrashReporter.framework | ENABLE_BITCODE = NO; |
| TOAST IAP | ToastIAP | ToastIAP.framework | * StoreKit.framework<br/><br/>[Optional]<br/> * libsqlite3.tdb | |
| TOAST Push | ToastPush | ToastPush.framework | * UserNotifications.framework<br/><br/>[Optional]<br/> * PushKit.framework | |

## TOAST SDK를 Xcode 프로젝트에 적용

### 1. Cococapods를 사용해 TOAST SDK 적용

Podfile을 생성하여 TOAST SDK에 대한 Pod을 추가합니다.

```podspec
platform :ios, '9.0'
use_frameworks!

target '{YOUR PROJECT TARGET NAME}' do
pod 'ToastSDK'
end
```

생성된 Workspace를 열어 사용할 SDK를 가져옵니다(import).

```objc
#import <ToastCore/ToastCore.h>
#import <ToastLogger/ToastLogger.h>
#import <ToastIAP/ToastIAP.h>
#import <ToastPush/ToastPush.h>
```

### 2. 바이너리를 다운로드하여 TOAST SDK 적용

#### SDK 가져오기(import)

TOAST의 [Downloads](https://docs.toast.com/ko/Download/#toast-sdk) 페이지에서 전체 iOS SDK를 다운로드할 수 있습니다.

![import_frameworks](http://static.toastoven.net/toastcloud/sdk/ios/overview_import_frameworks_folder.png)

TOAST Logger의 Crash Report 기능을 사용하려면 함께 배포되는 CrashReporter.framework도 프로젝트에 추가해야 합니다.

![import_external_framework](http://static.toastoven.net/toastcloud/sdk/ios/overview_import_external_folder.png)

프로젝트에 다음과 같이 프레임워크(framework)가 추가된 것을 확인합니다.

![import_frameworks_complete](http://static.toastoven.net/toastcloud/sdk/ios/overview_import_complete_folder.png)

> TOAST IAP 기능을 사용하려면 StoreKit.framework를 추가해야 합니다.

![linked__storekit_frameworks](http://static.toastoven.net/toastcloud/sdk/ios/overview_link_frameworks_StoreKit.png)

![linked_frameworks](http://static.toastoven.net/toastcloud/sdk/ios/overview_link_frameworks_noAdSupport_IAP.png)

> TOAST Push 기능을 사용하려면 UserNotifications.framework를 추가해야 합니다.

![linked__usernotifications_frameworks](http://static.toastoven.net/toastcloud/sdk/ios/overview_link_frameworks_UserNotifications.png)

> TOAST Push 의 VoIP 기능을 사용하려면 PushKit.framework를 추가해야 합니다.

![linked__pushkit_frameworks](http://static.toastoven.net/toastcloud/sdk/ios/overview_link_frameworks_PushKit.png)

![linked_frameworks](http://static.toastoven.net/toastcloud/sdk/ios/overview_link_frameworks_Push.png)


#### Project Settings

**Build Settings**의 **Other Linker Flags**에 **-lc++**와 **-ObjC** 항목을 추가합니다.

**Project Target > Build Settings > Linking > Other Linker Flags**를 클릭해 추가할 수 있습니다.

![other_linker_flags](http://static.toastoven.net/toastcloud/sdk/ios/overview_settings_flags.png)

CrashReporter.framewor를 직접 다운로드하거나 빌드한 경우에는 Build Setting의 Enable Bitcode의 값을 **NO**로 변경해야 합니다.

**Project Target > Build Settings > Build Options > Enable Bitcode**을 클릭하고 **NO**를 클릭합니다.

![enable_bitcode](http://static.toastoven.net/toastcloud/sdk/ios/overview_settings_bitcode.png)
> TOAST의 [Downloads](https://docs.toast.com/ko/Download/#toast-sdk) 페이지에서 다운로드 받은 CrashReporter.framework는 bitCode를 지원합니다.

#### 프레임워크 가져오기 

사용하려는 프레임워크를 가져옵니다(import).

```objc
#import <ToastCore/ToastCore.h>
#import <ToastLogger/ToastLogger.h>
#import <ToastIAP/ToastIAP.h>
#import <ToastPush/ToastPush.h>
```

## UserID 설정

TOASAT SDK에 사용자 ID를 설정할 수 있습니다.
설정한 UserID는 TOAST SDK의 각 모듈에서 공통으로 사용됩니다.
TOAST Logger의 로그 전송 API를 호출할 때마다 설정한 사용자 ID를 로그와 함께 서버로 전송합니다.

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
## 디버그 모드 설정

TOAST SDK의 내부 로그를 확인하기 위해 디버그 모드를 설정할 수 있습니다.
TOAST SDK와 관련해 문의하실 때는 디버그 모드를 활성화해서 전달해 주시면 빠르게 지원해드릴 수 있습니다.

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

> [주의] 앱을 릴리스할 경우, 반드시 디버그 모드를 비활성화해야 합니다.

## TOAST Service 사용

* [TOAST Log & Crash](https://docs.toast.com/ko/TOAST/ko/toast-sdk/log-collector-ios/) 사용 가이드
* [TOAST In-app Purchase](https://docs.toast.com/ko/TOAST/ko/toast-sdk/iap-ios/) 사용 가이드
* [TOAST Push](https://docs.toast.com/ko/TOAST/ko/toast-sdk/push-ios/) 사용 가이드
