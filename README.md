#Sunteng Analytics iOS SDK

v1.0.0

## 开发环境

* Xcode 6.*+
* 支持 iOS 6.0.0+

## TrackingID 获取

从 [clicki](http://www.clicki.cn/) 官网获取对应 App 的 TrackingID。

## SDK 集成

1. 将最新的 SDK 头文件 `SuntengAnalyticsSDK.h` 和静态库 `libSuntengAnalyticsSDK.a` 加入项目中，在使用的地方 `#import "SuntengAnalyticsSDK.h"`。
2. 添加需要的 Framework，AdSupport.framework、CoreData.framework、CoreLocation.framework、CoreTelephony.framework、libz.dylib、Security.framework、SystemConfiguration.framework。
3. 设置对应 target 的编译选项，在『Build Settings』->『Linking』->『Other Linker Flags』，添加『-all_load』参数。
4. 添加 iOS 8+ 定位支持，在 App 的 info.plist 中添加『NSLocationWhenInUseUsageDescription』字段以支持程序运行时的定位。

## SDK 使用

### 初始化 SDK

在 `AppDelegate.m` 的 `application:didFinishLaunchingWithOptions:` 方法中使用 `startWithTrackingId:` 或 `startWithTrackingId:channelId:` 方法初始化 SDK。

```objc
[[SuntengAnalyticsSDK sharedInstance] startWithTrackingId:@"dc-1008611"];
```
```objc
[[SuntengAnalyticsSDK sharedInstance] startWithTrackingId:@"dc-1008611" channelId:@"App Store"];
```

### 使用特定标志追踪用户

开发者使用如邮箱、手机号码等，用以追踪具体用户。需要每次设置，SDK 不保存用户 ID。切换用户，注销等直接设置新 ID 或者 `nil`。

```objc
[[SuntengAnalyticsSDK sharedInstance] setUserId:@"admin@clicki.cn"];
```

### 页面统计

在对应页面的 `viewDidAppear:` 方法中使用 `enterPage:` 统计页面路径。如需统计页面停留时长，需要在页面的 `viewDidDisappear:` 方法中添加 `exitPage:` 方法配对使用，否则只能统计到路径。

```objc
- (void)viewDidAppear:(BOOL)animated {
    [super viewDidAppear:animated];
    [[SuntengAnalyticsSDK sharedInstance] enterPage:@"首页"];
}
```
```objc
- (void)viewDidDisappear:(BOOL)animated {
    [super viewDidDisappear:animated];
    [[SuntengAnalyticsSDK sharedInstance] exitPage:@"首页"];
}
```

```objc
[[SuntengAnalyticsSDK sharedInstance] enterPage:@"Web" path:@"clicki.cn"];
```

### 行为事件统计

```objc
[[SuntengAnalyticsSDK sharedInstance] eventWithCategory:@"分类" action:@"事件" label:@"标签" value:8.88];
```