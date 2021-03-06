#include "CharsetHelper.h"

#if (defined WIN32) ||  (defined _WIN32)  
#include<Windows.h>  
#else  
#include<unistd.h>   
#include<sys/types.h>  
#include<strings.h>  
#endif  

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>
#include <locale.h>
#include <stdint.h>

using namespace sys;

int32_t CharsetHelper::getUTF8WordCount(const char* data)
{
	if (data == nullptr)
	{
		return 0;
	}

	char* ptr = (char*)(data);
	int32_t count = 0;

	while (*ptr)
	{
		if (BIT_IS_MARK(*ptr, UTF8_MARK_1))
		{
			count++;
			ptr += 1;
		}
		else if (BIT_IS_MARK(*ptr, UTF8_MARK_2) 
			&& BIT_IS_MARK(*(ptr + 1), UTF8_MARK_7))
		{
			count++;
			ptr += 2;
		}
		else if (BIT_IS_MARK(*ptr, UTF8_MARK_3) 
			&& BIT_IS_MARK(*(ptr + 1), UTF8_MARK_7) 
			&& BIT_IS_MARK(*(ptr + 2), UTF8_MARK_7))
		{
			count++;
			ptr += 3;
		}
		else if (BIT_IS_MARK(*ptr, UTF8_MARK_4)
			&& BIT_IS_MARK(*(ptr + 1), UTF8_MARK_7)
			&& BIT_IS_MARK(*(ptr + 2), UTF8_MARK_7)
			&& BIT_IS_MARK(*(ptr + 3), UTF8_MARK_7))
		{
			count++;
			ptr += 4;
		}
		else if (BIT_IS_MARK(*ptr, UTF8_MARK_5)
			&& BIT_IS_MARK(*(ptr + 1), UTF8_MARK_7)
			&& BIT_IS_MARK(*(ptr + 2), UTF8_MARK_7)
			&& BIT_IS_MARK(*(ptr + 3), UTF8_MARK_7)
			&& BIT_IS_MARK(*(ptr + 4), UTF8_MARK_7))
		{
			count++;
			ptr += 5;
		}
		else if (BIT_IS_MARK(*ptr, UTF8_MARK_6)
			&& BIT_IS_MARK(*(ptr + 1), UTF8_MARK_7)
			&& BIT_IS_MARK(*(ptr + 2), UTF8_MARK_7)
			&& BIT_IS_MARK(*(ptr + 3), UTF8_MARK_7)
			&& BIT_IS_MARK(*(ptr + 4), UTF8_MARK_7)
			&& BIT_IS_MARK(*(ptr + 5), UTF8_MARK_7))
		{
			count++;
			ptr += 6;
		}
		else
		{
			break;
		}
	}

	return count;
}

char* CharsetHelper::convertToUTF8(wchar_t* src)
{
	if (src == nullptr)
	{
		return nullptr;
	}
	int32_t mbs_size;
#if (defined WIN32) ||  (defined _WIN32)  
	setlocale(LC_ALL, "chs");
#else  
	setlocale(LC_ALL, "zh_CN.gbk");
#endif  
	int32_t wc_size = wcslen(src);
	if (wc_size == 0)
		wc_size = UINT32_MAX;

	mbs_size = wcstombs(0, src, wc_size);

	char* mbs = (char*)malloc(sizeof(wchar_t)*(mbs_size + 1));
	if (mbs != 0)
		mbs_size = wcstombs(mbs, src, wc_size);

	return mbs;
}

wchar_t* CharsetHelper::convertToWideChar(const char* src, int32_t& length)
{
	if (src == nullptr) {
		return nullptr;
	}

	// 根据环境变量设置locale
#if (defined WIN32) ||  (defined _WIN32)  
	setlocale(LC_ALL, "chs");
#else  
	setlocale(LC_ALL, "zh_CN.gbk");
#endif  
	int32_t wc_size;
	int32_t mbs_size = strlen(src);

	if (mbs_size == 0)
		mbs_size = UINT32_MAX;

	wc_size = mbstowcs(0, src, mbs_size);

	wchar_t* wc = (wchar_t*)malloc(sizeof(wchar_t)*(mbs_size + 1));
	if (wc != 0)
	{
		wc_size = mbstowcs(wc, src, mbs_size);
		length = mbs_size;
	}

	return wc;
}

wchar_t* CharsetHelper::convertToWideCharWnd(const char *str, int32_t& length)
{
	if (str == nullptr)
	{
		return nullptr;
	}
	length = strlen(str) + 1;
	wchar_t *t = (wchar_t*)malloc(sizeof(wchar_t)*length);
	memset(t, 0, length*sizeof(wchar_t));
	MultiByteToWideChar(CP_UTF8, 0, str, strlen(str), t, length);
	return t;
}

void sys::CharsetHelper::convertToWideChar(const char* str, std::string& text)
{
	if (str == nullptr)
	{
		return;
	}
#ifdef WIN32
	int32_t length = 0;
	wchar_t* content = convertToWideCharWnd(str, length);
	if (content == nullptr)
	{
		text = std::string((char*)content, length);
		free(content);
	}
#else
	int32_t length = 0;
	wchar_t* content = convertToWideChar(str, length);
	if (content == nullptr)
	{
		text = std::string((char*)content, length);
		free(content);
	}
#endif // WIN32
}
