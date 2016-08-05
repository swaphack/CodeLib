#pragma once

#include "Stream.h"
#include <string>

namespace sys
{
	/*
	字符串流 末尾补\0
	Unix系统里，每行结尾只有“<换行>”，即“\\n”；
	Windows系统里面，每行结尾是“<回车><换行>”，即“\r\\n”；
	Mac系统里，每行结尾是“<回车>”,即“\r”。
	*/
	class StringStream : public Stream
	{
	public:
		StringStream();
		StringStream(const char* text);
		StringStream(const char* text, int size);
		virtual ~StringStream();
	public:
		// 读取一行
		std::string readLine();
		// 写入字符串
		void writeString(const char* line, int size);
		// 写入一行字符串
		void writeLine(const char* line, int size);
		// 写入空行
		void writeLine();
		// 是否读到结束
		bool readEnd();
	};
}