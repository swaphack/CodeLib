#pragma once

#include "Types.h"

namespace sys
{
	// unicode ���뷽ʽ
	// utf8 utf16 utf32 �洢��ʽ

	// �ж�Դfull�ֽ��Ƿ������ʶmark�ֽ�
	#define BIT_IS_MARK(full, mark) ( (full & mark) == full )
	
	// utf8 ��Ǹ�ʽ
	#define UTF8_MARK_1 0x7F	// 0111 1111
	#define UTF8_MARK_2 0xDF	// 1101 1111
	#define UTF8_MARK_3 0xEF	// 1110 1111
	#define UTF8_MARK_4 0xF7	// 1111 0111
	#define UTF8_MARK_5 0xFB	// 1111 1011
	#define UTF8_MARK_6 0xFD	// 1111 1101
	#define UTF8_MARK_7 0xBF	// 1011 1111

	class BitHelper
	{
	public:
		// ��ȡutf8��������
		static int getUTF8WordCount(const char* data);
		// ��ȡutf8����
		static wchar_t* convertToWideChar(char* &src, const char *locale = "zh_CN.utf8");
	protected:
	private:
	};
}