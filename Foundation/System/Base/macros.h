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

#define BREAK_IF(x) { if(x) { break; } }
#define RETURN_IF(x) { if(x) { return; } }

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


// 是否大写字母
#define IS_CAPITAL_LETTER(X) (X >= 'A' && X <= 'Z')
// 是否小写字母
#define IS_LOWER_CASE_LETTER(X) (X >= 'a' && X <= 'z')
// 是否是数字
#define IS_NUMBER(X) (X >= '0' && X <= '9')
// 左括号
#define LEFT_PARENTHESIS '('
// 右括号
#define RIGHT_PARENTHESIS ')'

/* Miscellaneous useful macros */

#undef MAX
#define MAX(a,b)	((a) > (b) ? (a) : (b))
#undef MIN
#define MIN(a,b)	((a) < (b) ? (a) : (b))

// 获取格式化的字符串，无需删除
extern const char* getCString(const char* format, ...);