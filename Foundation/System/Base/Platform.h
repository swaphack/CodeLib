#pragma once

// 平台类型
enum PlatformType
{
	EPT_ANDROID,
	EPT_WINDOWS,
	EPT_IOS,
};

#if defined(ANDROID)
#define PLATFORM_TARGET EPT_ANDROID
#elif defined(WIN32) || defined(_WIN32)
#define PLATFORM_TARGET EPT_WINDOWS
#elif defined(IOS)
#define PLATFORM_TARGET EPT_IOS
#endif

#ifndef PLATFORM_TARGET
#define PLATFORM_TARGET EPT_WINDOWS
#endif