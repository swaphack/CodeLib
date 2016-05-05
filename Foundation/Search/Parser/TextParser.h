#pragma once

#include <string>
#include <map>
#include <set>

namespace search
{
	// �ı����������ڹ���ؼ���
	class TextParser
	{
	public:
		TextParser(const char* key);
		~TextParser();
	public:
		// �����ı�
		void parserText(const char* key);
		// ������Ĺؼ���
		const std::set<std::string>& getKeys();
	private:
		// ������Ĺؼ���
		std::set<std::string> _keys;
	};
}