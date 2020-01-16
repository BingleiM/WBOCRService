Pod::Spec.new do |s|
s.authors      = "BingleiM"
#名称
s.name         = "WBOCRService"
#版本号
s.version      = "2.7.0"
#简介
s.summary      = "腾讯官方OCR扫描，所有权归腾讯公司所有，此处为了方便使用 cocoapods 管理"
s.description  = <<-DESC
腾讯官方OCR扫描，所有权归腾讯公司所有，此处为了方便使用 cocoapods 管理
DESC
#项目主页地址
s.homepage     = "https://github.com/BingleiM/WBOCRService.git"
#许可证
s.license      = { :type => 'MIT', :file => 'LICENSE' }
#作者
s.author       = { "BingleiM" => "houdaoc@163.com" }
s.source       = { :git => "https://github.com/BingleiM/WBOCRService.git", :tag => s.version }
s.resources    = "WBOCRService/**"
s.requires_arc = true
#支持最小系统版本
s.ios.deployment_target = '8.0'
#依赖库
s.frameworks = "CoreTelephony", "AssetsLibrary", "CoreMedia", "AVFoundation", "WebKit", "SystemConfiguration"
#你的SDK路径（因为传的是静态库，这个必须要）
s.vendored_frameworks = "WBOCRService/WBOCRService.framework", "WBOCRService/opencv2.framework"
# 如果第三方 SDK 有lib包，这个是必填的（注意路径）
s.vendored_libraries = 'WBOCRService/librecdetect.a'

end

