//
//  YBAuthLoginInfo.h
//  YBTVHospitalSdk
//
//  Created by nieyinlong on 2022/3/15.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface YBAuthLoginInfo : NSObject

@property (nonatomic, copy) NSString *user;
@property (nonatomic, copy) NSString *sign;
@property (nonatomic, copy) NSString *appId;
@property (nonatomic, copy) NSString *timestamp;

- (instancetype)initWithUser:(nonnull NSString *)user sign:(nonnull NSString *)sign appId:(nonnull NSString *)appId timestamp:(nonnull NSString *)timestamp;

@end

NS_ASSUME_NONNULL_END
