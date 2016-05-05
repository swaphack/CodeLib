#include "BitHelper.h"

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>
#include <locale.h>

using namespace sys;

int BitHelper::getUTF8WordCount(const char* data)
{
	if (data == nullptr)
	{
		return 0;
	}

	char* ptr = (char*)(data);
	int count = 0;

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
			break;;
		}
	}

	return count;
}

wchar_t* BitHelper::convertToWideChar(char* &src, const char *locale /*= "zh_CN.utf8"*/)
{
	if (src == NULL) {
		return nullptr;
	}

	// ���ݻ�����������locale
	setlocale(LC_CTYPE, locale);

	// �õ�ת��Ϊ��Ҫ�Ŀ��ַ���С
	int w_size = mbstowcs(NULL, src, 0) + 1;

	// w_size = 0 ˵��mbstowcs����ֵΪ-1���������й����������˷Ƿ��ַ�(���п���ʹlocale
	// û��������ȷ)
	if (w_size == 0) {
		return nullptr;
	}

	wchar_t* dest = new wchar_t[w_size];
	if (!dest) {
		return nullptr;
	}

	int ret = mbstowcs(dest, src, strlen(src) + 1);
	if (ret <= 0) {
		delete dest;
		return nullptr;
	}
	return dest;
}
