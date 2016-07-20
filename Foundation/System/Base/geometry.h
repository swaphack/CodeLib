#pragma once

#include <cstring>

#include "Platform.h"

#if PLATFORM_TARGET == EPT_WINDOWS
#define LINE_MARK "\r\n"
#elif PLATFORM_TARGET == EPT_MAC
#define LINE_MARK "\r"
#elif PLATFORM_TARGET == EPT_LINUX
#define LINE_MARK "\n"
#else
#define LINE_MARK "\r\n"
#endif

#define LINE_EQUAL(ptr) (memcmp(ptr, LINE_MARK, strlen(LINE_MARK)) == 0)
#define LINE_APPEND(ptr) strcpy(ptr, LINE_MARK)