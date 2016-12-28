#pragma once

#include "macros.h"

#include <map>

namespace ll
{
	// 语言库
	class LibLanguage
	{
	public:
		LibLanguage();
		virtual ~LibLanguage();
	public:
		// 添加一个单词
		void addWord(Word* word);
		// 移除一个单词
		void removeWord(const char* word);
		// 移除所有单词
		void removeAllWords();
		// 获取一个单词信息
		const Word* getWord(const char* word);
	private:
		// 一级索引 文本
		typedef std::map<Text, Word*> FirstIndex;
		// 二级索引 文本开头-26个字母
		typedef std::map<int, FirstIndex> SecondIndex;
	private:
		// 文本
		SecondIndex m_iTexts;
	};
}