#pragma once

#include "Base/Types.h"

namespace sys
{
	class IBlockParser;

	class TextParser
	{
	public:
		TextParser();
	public:
		// 添加解析器
		void AddParser(IBlockParser* parser);
		// 移除解析器
		void removeParser(IBlockParser* parser);
		// 移除解所有析器
		void removeAllParsers();
		// 读取块信息
		bool readBlock(char* inPtr, std::vector<std::string>& outData);
	private:
		std::vector<IBlockParser*> _textParsers;
	};
}