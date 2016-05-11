#pragma once

#include <cassert>
#include <cstdlib>

#define SAFE_DELETE(x) {if(x) {delete(x); (x) = 0;}}
#define SAFE_FREE(x) {if(x) {free(x); (x) = 0;}}

#define ASSERT(x) assert(x)

#define AUTO_RELEASE_OBJECT(object) \
	{ \
		if (object) {\
		object->retain(); \
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

#ifndef PI
#define PI 3.14159265358979323846
#endif

#ifdef REALSE
#define LOG(format, ...)
#else
#include <cstddef>
#define LOG(format, ...)  printf(format, __VA_ARGS__)
#endif