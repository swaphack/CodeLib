#pragma once

#include <cstdint>
#include <string>

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

	class CharsetHelper
	{
	public:
		// ��ȡutf8��������
		static int32_t getUTF8WordCount(const char* data);
		// ��ȡutf8����
		static char* convertToUTF8(wchar_t* src);
		// תΪ���ֽ� zh_CN.utf8 zh_CN.GB2312 
		static wchar_t* convertToWideChar(const char* src, int32_t& length);
		// תΪ���ֽ� windows
		static wchar_t* convertToWideCharWnd(const char *str, int32_t& length);

		static void convertToWideChar(const char* str, std::string& text);
	};
}