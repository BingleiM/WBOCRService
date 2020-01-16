//
//  WBOCRConfig.h
//  Pods
//
//  WBOCRConfig类定义了SDK的配置信息，可以通过 WBOCRConfig 单例进行读取、配置，
//  配置是可选的，如果外部没有配置信息传入，将使用默认的配置参数。
//

#import <Foundation/Foundation.h>

/**
 * @brief WBOCRSDKType定义SDK不同的识别模式
 
 - WBOCRSDKTypeNoraml  : 标准模式，SDK调起成功后，先进入拍摄准备页面，待正反两面识别完成之后，将本次识别结果返回到第三方APP
 - WBOCRSDKTypeFontSide: 人像面识别模式，SDK调起成功后，直接进入拍摄识别页面，识别身份证人像面，识别完成之后，将本次识别结果返回第三方APP
 - WBOCRSDKTypeBackSide: 国徽面识别模式，SDK调起成功后，直接进入拍摄识别页面，识别身份证国徽面，识别完成之后，将本次识别结果返回第三方APP
 */
typedef NS_ENUM(NSInteger, WBOCRSDKType) {
    WBOCRSDKTypeIDCardNormal,
    WBOCRSDKTypeIDCardFrontSide,
    WBOCRSDKTypeIDCardBackSide,
    WBOCRSDKTypeBankCard
};

@interface WBOCRConfig : NSObject

+ (instancetype _Nonnull )sharedConfig;

/**
 * @brief 选择SDK接入模式，default WBOCRSDKTypeNoraml
 */
@property (nonatomic) WBOCRSDKType SDKType;


/**
 * @brief needBothSidesRecognized 参数当 SDKType 为 `WBOCRSDKTypeNoraml` 起作用，default NO
 *
 * @detail 当参数设置为 YES 时，SDK需要人像面和国徽面都识别成功之后，才能点击“完成”按钮退出SDK
 #         当参数设置为 NO 时， SDK只需要人像面识别成功，就可以点击“完成”按钮退出SDK
 */
@property (nonatomic) BOOL needBothSidesRecognized;


/// 适配 iOS13  ViewController Presentation Style 的变化
/// SDK 默认使用 `UIModalPresentationFullScreen`
@property (nonatomic) UIModalPresentationStyle presentationStyle;

/**
 * @brief 设置身份证照片预览页面上的水印信息，default @"仅供本次业务使用"
 */
@property (nonatomic, copy) NSString * _Nullable waterMarking;
/**
 * @brief 设置识别超时时间，默认是20.0s
 */
@property (nonatomic) NSTimeInterval timeoutInterval;
/**
 * @brief 获取SDK的登录接口的baseUrl，readonly
 */
@property (nonatomic, copy, readonly) NSString* _Nonnull baseUrl;

/**
 * @brief 获取本次业务的orderNo，readonly
 */
@property (nonatomic, strong, readonly) NSString *_Nonnull orderNo;

/**
 * @brief 获取本次业务的ocrId，readonly
 */
@property (nonatomic, strong, readonly) NSString *_Nonnull ocrId;

/**
 * @brief 获取本次业务的appId，readonly
 */
@property (nonatomic, strong, readonly) NSString *_Nonnull appId;

/**
 * @brief 获取本次业务的nonce，readonly
 */
@property (nonatomic, strong, readonly) NSString *_Nonnull nonce;

/**
 * @brief 获取本次业务的sign，readonly
 */
@property (nonatomic, strong, readonly) NSString *_Nonnull sign;

/**
 * @brief 获取本次业务的userId，readonly
 */
@property (nonatomic, strong, readonly) NSString *_Nonnull userId;

/**
 * @brief 获取cdn配置参数信息，readonly
 */
@property (nonatomic, strong, readonly) NSDictionary *_Nonnull cdnParam;

@end
