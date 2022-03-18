

# YBTVHospitalSdk iOS 文档
支持iOS9.0及以以上

## 1. 自动集成(推荐)
```pod 'YBTVHospitalSdk'```


## 2. 手动集成
```
把framework复制到工程

配置Build setting, Enable Bitcode 改为NO

pod 文件加入以下依赖项, 执行pod install

pod 'Masonry'
pod 'YYModel', '1.0.4'
pod 'WebViewJavascriptBridge', '~> 6.0.3'
pod 'IQKeyboardManager'
pod 'AliRTCSdk', '~>2.0'
pod 'AFNetworking', '~> 4.0'
pod 'YTKNetwork', '~> 3.0'
pod 'SDWebImage', '~> 5.0'

```
     

## 3.  配置info.plist, 添加以下几项
```
    <key>NSPhotoLibraryUsageDescription</key>
    <string>是否允许此App访问您的相册</string>
    <key>NSAppleMusicUsageDescription</key>
    <string>是否允许此App访问你的媒体资料库</string>
    <key>NSMicrophoneUsageDescription</key>
    <string>是否允许此App访问你的麦克风以便医生聊天</string>
    <key>NSCameraUsageDescription</key>
    <string>是否允许此App访问你的相机以便医生视频聊天</string>

```

## 4. Signing & Capabilities页签中打开后台音频权限
Background Modes -> Audio,AirPlay,andPicture in Picture

## 5.  使用

在AppDelegate中调用登录方法, 会把用户信息保存起来

在合适的地方调用``` [[YBSdk shareSdk] goConsult];```去咨询

也可以每次都登录, 在回调里面调用``` [[YBSdk shareSdk] goConsult];```

```Objc

import <YBTVHospitalSdk/YBTVHospitalSdk.h>
    
YBAuthLoginInfo *info = [[YBAuthLoginInfo alloc] init];
info.user = @"用户";
info.sign = @"加密信息";
info.appId = @"分配的appId";
info.timestamp = @"加密时用的时间戳";
YBSdk.shareSdk.delegate = self;
[[YBSdk shareSdk] loginWithAuthInfo:info isProductionEnv:NO isDebug:YES completion:^(BOOL isLoginSuccess, NSString * _Nullable errStr) {
    if(isLoginSuccess) {
        [[YBSdk shareSdk] goConsult];
    }       
}];
        
 #pragma mark - YBCallDelegate
 
 /// 通话通道已建立(此时对方未接)
- (void)callDidConnect;
/// 通话结束
- (void)callDidEnd;
/// 医生上线
- (void)onRemoteUserOnLine;
/// 医生下线
- (void)onRemoteUserOffLine;
/// 失败
- (void)onFail:(NSString * _Nullable)errStr;
```


 


