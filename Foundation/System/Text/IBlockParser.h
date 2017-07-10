#pragma once

#include <string>

namespace sys
{
	// 文本块
	class IBlockParser
	{
	public:
		// 解析文本块
		virtual bool readBlock(char* inPtr, std::string& outData) = 0;
	};

	// 解析一行文本
	class LineParser : IBlockParser
	{
	public:
		// 解析文本块
		virtual bool readBlock(char* inPtr, std::string& outData);
	};
}