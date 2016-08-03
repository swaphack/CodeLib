#pragma once

#include <cassert>
#include <cstdlib>
#include <cstdarg>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#define SAFE_DELETE(x) {if(x) {delete(x); (x) = 0;}}
#define SAFE_FREE(x) {if(x) {free(x); (x) = 0;}}

#define AUTO_RELEASE_OBJECT(object) \
	{ \
		if (object) {\
		object->autoRelease(); \
		} \
	}

#define SAFE_RETAIN(x) \
	{\
		if (x) { \
		(x)->retain();\
		} \
	}

#define SAFE_RELEASE(x) \
	{\
		if (x) {\
		(x)->release(); \
		} \
	}

#ifdef REALSE
#define LOG(FORMAT, ...)
#else
#include <cstddef>
#define LOG(FORMAT, ...)  printf(FORMAT, __VA_ARGS__)
#endif

#define ASSERT(x) assert(x)
#define WARING(RESULT, FORMAT, ...) if (!RESULT) LOG(FORMAT, __VA_ARGS__)

// 获取格式化的字符串，无需删除
extern const char* getCString(const char* format, ...);