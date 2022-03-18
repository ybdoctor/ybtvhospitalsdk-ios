//
//  YBSdk.h
//  YBTVHospitalSdk
//
//  Created by nieyinlong on 2022/3/3.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "YBAuthLoginInfo.h"

NS_ASSUME_NONNULL_BEGIN


typedef void(^YBLoginHandler)(BOOL isLoginSuccess, NSString * __nullable errStr);
typedef void(^YBStartCallHandler)(BOOL isCallSuccess, NSString * __nullable errStr);

@protocol YBCallDelegate <NSObject>

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

@end


@interface YBSdk : NSObject

/// 是否为正式环境, 默认NO
@property (nonatomic, assign, readonly) BOOL isProductionEnv;
/// 是否打印log, 默认NO
@property (nonatomic, assign, readonly) BOOL isDebug;
/// 代理
@property (nonatomic, weak) id<YBCallDelegate>delegate;
/// 单例
+ (instancetype)shareSdk;

/// 登录授权
/// @param info 传参信息
/// @param isProductionEnv 是否为正式环境,
/// @param isDebug 是否打印
/// @param completion 登录回调
- (void)loginWithAuthInfo:(nonnull YBAuthLoginInfo *)info isProductionEnv:(BOOL)isProductionEnv isDebug:(BOOL)isDebug completion:(YBLoginHandler)completion;

/// 去往咨询页面, 在登录成功之后调用
- (void)goConsult;

/// 关闭窗口
- (void)closeWindow;

@end

NS_ASSUME_NONNULL_END
