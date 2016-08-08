#pragma once

#include <cassert>
#include <cstdlib>
#include <cstdarg>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cstddef>

#define SAFE_DELETE(x) { if(x) { delete(x); (x) = 0;} }
#define SAFE_FREE(x) { if(x) { free(x); (x) = 0; } }

#define AUTO_RELEASE_OBJECT(object) { if(object) { object->autoRelease(); } }

#define SAFE_RETAIN(x) { if(x) { (x)->retain(); } }

#define SAFE_RELEASE(x) { if(x) { (x)->release(); } }

#define ASSERT(x) assert(x)

#ifdef REALSE
#define PRINT(FORMAT, ...)
#else
#define PRINT(FORMAT, ...) printf(FORMAT, __VA_ARGS__)
#endif

#define LOG_FILENAME "log"
#define LOG(FORMAT, ...)  printf(FORMAT, __VA_ARGS__)


// ��ȡ��ʽ�����ַ���������ɾ��
extern const char* getCString(const char* format, ...);