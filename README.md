## TOAST > TOAST SDK 사용 가이드 > 시작하기 > iOS

## 지원 환경

* iOS 8.0 이상
* XCode 최신 버전 (버전 9 이상)

## TOAST SDK의 구성

iOS 용 TOAST SDK의 구성은 다음과 같습니다.

* [TOAST Logger](./log-collector-ios) SDK

TOAST SDK가 제공하는 서비스 중 원하는 기능을 선택하여 적용할 수 있습니다.

| Framework | CocoaPods Pod Name | Service |
| --- | --- | --- |
| ToastLogger | ToastLogger | TOAST Logger |

## TOAST SDK를 Xcode 프로젝트에 적용하기

### 1. CococaPods을 사용해서 TOAST SDK 적용하기

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
#import <ToastLogger/ToastLogger.h>
```

### 2. 바이너리 다운로드로 TOAST SDK 적용하기

#### SDK import

TOAST의 [Downloads](../../../Download/#toast-sdk) 페이지에서 전체 iOS SDK를 다운로드 받을 수 있습니다.

![import_frameworks](http://static.toastoven.net/toastcloud/sdk/ios/overview_import_frameworks.png)

TOAST Logger의 Crash Report 기능을 사용하기 위해서는 함께 배포되는 CrashReporter.framework도 프로젝트에 추가해야합니다.

![import_external_framework](http://static.toastoven.net/toastcloud/sdk/ios/overview_import_external.png)

프로젝트에 다음과 같이 Framework 들이 추가 된 것을 확인합니다.

![import_frameworks_complete](http://static.toastoven.net/toastcloud/sdk/ios/overview_import_complete.png)

![link_frameworks](http://static.toastoven.net/toastcloud/sdk/ios/overview_link_frameworks.png)

#### Project Settings

"Build Settings"의 "Other Linker Flags"에 "-lc++"와 "-ObjC" 항목을 추가합니다.

* Project Target - Build Settings - Linking - Other Linker Flags

![other_linker_flags](http://static.toastoven.net/toastcloud/sdk/ios/overview_settings_flags.png)

CrashReporter.framewor를 직접 다운로드받거나 빌드한 경우에는 Build Setting의 Enable Bitcode의 값을 NO로 변경해야 합니다.

* Project Target - Build Settings - Build Options - Enable Bitcode - "NO"

![enable_bitcode](http://static.toastoven.net/toastcloud/sdk/ios/overview_settings_bitcode.png)
> TOAST의 [Downloads](../../../Download/#toast-sdk) 페이지에서 다운로드 받은 CrashReporter.framewor는 bitCode를 지원합니다.

#### import framework

사용하고자 하는 Framework를 import 합니다.

```objc
#import <ToastLogger/ToastLogger.h>
```

## Using the TOAST Service

* [TOAST Logger](./log-collector-ios) 사용 가이드


