#pragma once

#include <string>
#include <map>
#include <set>

namespace search
{
	// 文本解析，用于归类关键字
	class TextParser
	{
	public:
		TextParser(const char* key);
		~TextParser();
	public:
		// 解析文本
		void parserText(const char* key);
		// 解析后的关键字
		const std::set<std::string>& getKeys();
	private:
		// 解析后的关键字
		std::set<std::string> _keys;
	};
}