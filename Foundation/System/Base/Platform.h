#pragma once

// 平台类型
enum PlatformType
{
	EPT_WINDOWS,	// window
	EPT_MAC,		// mac
	EPT_LINUX,		// linux
};

#if defined(WIN32) || defined(_WIN32)
#define PLATFORM_TARGET EPT_WINDOWS
#elif defined(MAC)
#define PLATFORM_TARGET EPT_MAC
#elif defined(LINUX)
#define PLATFORM_TARGET EPT_LINUX
#endif

#ifndef PLATFORM_TARGET
#define PLATFORM_TARGET EPT_WINDOWS
#endif