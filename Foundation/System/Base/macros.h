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


// �Ƿ��д��ĸ
#define IS_CAPITAL_LETTER(X) (X >= 'A' && X <= 'Z')
// �Ƿ�Сд��ĸ
#define IS_LOWER_CASE_LETTER(X) (X >= 'a' && X <= 'z')
// �Ƿ�������
#define IS_NUMBER(X) (X >= '0' && X <= '9')
// ������
#define LEFT_PARENTHESIS '('
// ������
#define RIGHT_PARENTHESIS ')'

/* Miscellaneous useful macros */

#undef MAX
#define MAX(a,b)	((a) > (b) ? (a) : (b))
#undef MIN
#define MIN(a,b)	((a) < (b) ? (a) : (b))

// ��ȡ��ʽ�����ַ���������ɾ��
extern const char* getCString(const char* format, ...);