#pragma once

#include "Types.h"

namespace sys
{
	// unicode 编码方式
	// utf8 utf16 utf32 存储格式

	// 判断源full字节是否包含标识mark字节
	#define BIT_IS_MARK(full, mark) ( (full & mark) == full )
	
	// utf8 标记格式
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
		// 获取utf8文字数量
		static int getUTF8WordCount(const char* data);
		// 获取utf8文字
		static wchar_t* convertToWideChar(char* &src, const char *locale = "zh_CN.utf8");
	protected:
	private:
	};
}