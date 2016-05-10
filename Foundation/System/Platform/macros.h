#pragma once

#include "../Device/import.h"
#include "../Base/import.h"

// 平台类型
enum PlatformType
{
	EPT_ANDROID,
	EPT_WINDOW,
	EPT_IOS,
};

#if defined(ANDROID)
#define PLATFORM_TARGET EPT_ANDROID
#elif defined(WIN32) || defined(_WIN32)
#define PLATFORM_TARGET EPT_WINDOW
#elif defined(IOS)
#define PLATFORM_TARGET EPT_IOS
#endif

#ifndef PLATFORM_TARGET
#define PLATFORM_TARGET EPT_WINDOW
#endif