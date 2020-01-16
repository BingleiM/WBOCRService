//
//  WBOCRService.h
//  Pods
//
//  1. WBOCRService.h 这个头文件中包含了三个类的定义：
//  - `WBIDCardInfoModel` 类封装了身份证的正反面信息，SDK通过该类型的实例向外部传递身份证识别结果
//  - `WBBankCardInfoModel` 类封装了银行卡的正方面信息，SDK通过该类型的实例向外部传递银行卡的识别结果
//  - `WBOCRService` 是SDK的入口类，是一个单例类，是SDK的入口
//
//  2. SDK的具体调用请参考接入文档和SDK附带的demo
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "WBOCRConfig.h"

////////////////////////////////////////////////////////////////////////////////
//////////////////                   ///////////////////////////////////////////
////////////////// WBIDCardInfoModel ///////////////////////////////////////////
//////////////////                   ///////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
/*
 * @brief WBIDCardInfoModel类封装了身份证的正反面信息
 *        SDK会将识别结果包装成一个WBIDCardInfoModel实例，通过回调block通知第三方
 
 * @detail 字段含义
 - idcard        公民身份号码
 - name          姓名
 - sex           性别
 - nation        民族
 - address       住址
 - birth         出生
 - authority     签发机关
 - validDate     有效期限
 - frontFullImg  国徽面截图
 - backFullImg   人像面截图
 - orderNo       订单号，和本次业务相关
 - sign          签名信息
 - warning       识别结果警告信息
 - multiWarning  多重告警码，人像面是frontMultiWarning，国徽面对应backMultiWarning
 - clarity       图片清晰度，人像面是frontClarity，国徽面对应backClarity
 */

@interface WBIDCardInfoModel : NSObject
/// 身份证人像面信息
@property (nonnull, strong, nonatomic) NSString *idcard;
@property (nonnull, strong, nonatomic) NSString *name;
@property (nonnull, strong, nonatomic) NSString *sex;
@property (nonnull, strong, nonatomic) NSString *nation;
@property (nonnull, strong, nonatomic) NSString *address;
@property (nonnull, strong, nonatomic) NSString *birth;

/// 身份证国徽面信息
@property (nonnull, strong, nonatomic) NSString *authority;
@property (nonnull, strong, nonatomic) NSString *validDate;

/// 本次业务相关信息
@property (nonnull, strong, nonatomic) NSString *orderNo;
@property (nonnull, strong, nonatomic) NSString *sign;

/// 正反面识别结果截图信息
@property (nonnull, strong, nonatomic) UIImage *frontFullImg;
@property (nonnull, strong, nonatomic) UIImage *backFullImg;

/// warning，正反面识别结果对应的警告信息
@property (nullable, strong, nonatomic) NSString *frontWarning;
@property (nullable, strong, nonatomic) NSString *frontMultiWarning;

@property (nullable, strong, nonatomic) NSString *backWarning;
@property (nullable, strong, nonatomic) NSString *backMultiWarning;

@property (nonnull, strong, nonatomic) NSString *frontClarity;
@property (nonnull, strong, nonatomic) NSString *backClarity;


- (instancetype _Nullable )initWithModel:(WBIDCardInfoModel *_Nullable)model
                              dictionary:(NSDictionary *_Nullable)dic;

@end

///////////////////////////////////////////////////////////////////////////////
//////////////////                     ////////////////////////////////////////
////////////////// WBBankCardInfoModel ////////////////////////////////////////
//////////////////                     ////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

/**
 * @brief 银行卡信息
 * @detail 字段含义
 - bankcardNo         银行卡号
 - bankcardFullImg    银行卡识别的照片
 - bankcardCropPhoto  银行卡卡号切图
 - bankcardValidDate  银行卡有效期(年／月，没有为空)
 - warningCode        警告码
 - warningMsg         警告码描述
 - multiWarningCode   多重警告码
 - multiWarningMsg    多重警告码描述
 - clarity            图片清晰度
 */
@interface WBBankCardInfoModel : NSObject

@property (nonnull, strong, nonatomic)  NSString *bankcardNo;
@property (nonnull, strong, nonatomic)  UIImage  *bankcardFullImg;
@property (nonnull, strong, nonatomic)  UIImage  *bankcardCropPhoto;

@property (nullable, strong, nonatomic) NSString *bankcardValidDate;
@property (nullable, strong, nonatomic) NSString *warningCode;
@property (nullable, strong, nonatomic) NSString *warningMsg;

@property (nullable, strong, nonatomic) NSString *multiWarningCode;
@property (nullable, strong, nonatomic) NSString *multiWarningMsg;

@property (nonnull, strong, nonatomic) NSString *clarity;

@end

/**
 * @brief WBOCRService类提供了SDK的入口,
 *        通过调用startService方法可以启动SDK,
 *        可以从几个不同的回调中获取相应的结果回调.
 */

///////////////////////////////////////////////////////////////////////////////
//////////////////                     ////////////////////////////////////////
//////////////////    WBOCRService     ////////////////////////////////////////
//////////////////                     ////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

@interface WBOCRService : NSObject

/**
 * @brief SDK启动成功回调，APP已经进入OCR识别界面
 */
typedef void(^WBOCRServiceStartSucceedBlock)(void);

/**
 * @brief SDK识别完成回调，SDK即将退出，回调中包含有包含有本次识别信息
 *
 * @param resultModel 识别到的OCR信息
 * @param extension   扩展字段，目前版本没有使用，为空
 */
typedef void(^WBOCRServiceRecognizeSuccessBlock)(id _Nonnull resultModel,id _Nullable extension);

/**
 * @brief SDK异常退出后回调，SDK即将退出，回调中包含有异常原因
 *
 * @param error     导致退出的Error信息，里面包含错误码和错误描述，具体错误码的对照请参考在线接入文档
 * @param extension 扩展字段，目前版本没有使用，为空
 */
typedef void(^WBOCRServiceFailedBlock) (NSError * _Nonnull error,id _Nullable extension);

/**
 * @brief WBOCRService 单例方法，通过调用该方法实例化 WBOCRService对象
 *
 * @return WBOCRService对象
 */
+ (nonnull instancetype) sharedService;

/**
 * @brief sdk版本号，readonly参数
 */
@property (nonatomic,readonly,nonnull) NSString *sdkVersion;

/**
 * @brief 调起SDK入口方法
 
 * @param config            配置参数
 * @param version           openAPI接口版本号,由腾讯服务统一分配
 * @param appId             appId，由腾讯服务分配的
 * @param nonce             每次请求需要的一次性nonce，一次有效
 * @param userId            每个用户唯一的标识
 * @param sign              签名信息，有接入方后台提供，一次有效
 * @param orderNo           订单号，长度不能超过32位的字符串
 * @param startSucceed      SDK启动成功回调
 * @param recognizeSucceed  识别成功回调，即将退出SDK
 * @param failed            SDK发生异常退出后回调，即将退出SDK
 *
 */
- (void)startOCRServiceWithConfig:(nullable WBOCRConfig *)config
                          version:(nonnull NSString *)version
                            appId:(nonnull NSString *)appId
                            nonce:(nonnull NSString *)nonce
                           userId:(nonnull NSString *)userId
                             sign:(nonnull NSString *)sign
                          orderNo:(nonnull NSString *)orderNo
                     startSucceed:(nonnull WBOCRServiceStartSucceedBlock)startSucceed
                 recognizeSucceed:(nonnull WBOCRServiceRecognizeSuccessBlock)recognizeSucceed
                           failed:(nonnull WBOCRServiceFailedBlock)failed;


@end

