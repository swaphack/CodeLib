#pragma once

#include <cassert>
#include <cstdlib>

#define SAFE_DELETE_ARRAY(x) { if(x) { delete[] (x); (x) = 0;} }
#define SAFE_DELETE(x) { if(x) { delete(x); (x) = 0;} }
#define SAFE_FREE(x) { if(x) { free(x); (x) = 0; } }

#define BREAK_IF(x) { if(x) { break; } }
#define RETURN_IF(x) { if(x) { return; } }

#define ASSERT(x) assert(x)

#ifdef REALSE
#define PRINT(FORMAT, ...)
#define PRINTLN(FORMAT, ...)
#else
#define PRINT(FORMAT, ...) printf(FORMAT, __VA_ARGS__);
#define PRINTLN(FORMAT, ...) {printf(FORMAT, __VA_ARGS__);printf("\n");}
#endif

#define LOG_FILENAME "log"
#define LOG(FORMAT, ...)  printf(FORMAT, __VA_ARGS__);


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


#include <cstring>

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

/**
*	�������Ա
*/
#ifndef CREATE_CLASS_MEMBER_WITH_DEFAULT
#define CREATE_CLASS_MEMBER_WITH_DEFAULT(Type, Name, DefaultValue) \
public:\
	Type get##Name() const { return _##Name; }\
	void set##Name(Type val) { _##Name = val; } \
private: Type _##Name = DefaultValue;
#endif

/**
*	�������Ա
*/
#ifndef CREATE_CLASS_MEMBER
#define CREATE_CLASS_MEMBER(Type, Name) \
public:\
	Type get##Name() const { return _##Name; }\
	void set##Name(Type val) { _##Name = val; } \
private: Type _##Name;
#endif

/**
*	�������Ա
*/
#ifndef CREATE_CLASS_VECTOR_MEMBER
#define CREATE_CLASS_VECTOR_MEMBER(Type, Name, VectorName, Index) \
public:\
	Type get##Name() const { return (Type)VectorName[Index]; }\
	void set##Name(Type val) { VectorName[Index] = val; }
#endif

/**
*	��Ŀ��ֵת����ָ��������
*/
#ifndef ADJUST_DURATION_VALUE_RANGE
#define ADJUST_DURATION_VALUE_RANGE(a, min, max, range)\
			while (a < min) a+= range; while (a > max) a-=range;
#endif

// ��ȡ��ʽ�����ַ���������ɾ��
extern const char* getCString(const char* format, ...);