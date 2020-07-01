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
		StringStream(const std::string& text);
		StringStream(const char* text, size_t size);
		virtual ~StringStream();
	public:
		// 字符串初始化
		void initWithData(const std::string& text);
		// 字符串初始化
		void initWithData(const char* content, size_t size);
		// 读取一行
		void readLine(std::string& text);
		// 读取剩余
		void readRemain(std::string& text);
		// 写入字符串
		void writeString(const char* line, size_t size);
		// 写入字符串
		void writeString(const std::string& text);
		// 写入一行字符串
		void writeLine(const char* line, size_t size);
		// 写入一行字符串
		void writeLine(const std::string& text);
		// 写入空行
		void writeLine();
		// 是否读到结束
		bool readEnd();
	};
}