Pod::Spec.new do |s|
    s.name         = "YBTVHospitalSdk"
    s.version      = "1.0.01"
    s.summary      = "亿保互联网视频咨询"

    s.description  = <<-DESC
    亿保互联网视频咨询SDK, 使用OC实现
    DESC

    s.homepage     = "https://b.jianbaolife.com/"
    
    s.author           = { 'nieyinlong' => 'nyl0819@126.com' }
    s.platform     = :ios, "9.0"
    s.source       = { :git => "https://github.com/ybdoctor/ybtvhospitalsdk-ios.git", :tag => s.version }
  
    s.pod_target_xcconfig = {
        'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64'
    }
    s.user_target_xcconfig = { 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64' }

    s.vendored_frameworks = 'YBTVHospitalSdk.framework'

    s.dependency 'Masonry'
    s.dependency 'YTKNetwork', '3.0.6'
    s.dependency 'YYModel', '1.0.4'
    s.dependency 'WebViewJavascriptBridge', '~> 6.0.3'
    s.dependency 'IQKeyboardManager'
    s.dependency 'AliRTCSdk', '~> 2.0'
    s.dependency 'AFNetworking', '~> 4.0'
    s.dependency 'YTKNetwork', '~> 3.0'
    s.dependency 'SDWebImage', '~> 5.0'

end


