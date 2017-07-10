#pragma once

#include "macros.h"

#include <map>

namespace ll
{
	// 文本库
	class Dictionary
	{
	public:
		Dictionary();
		virtual ~Dictionary();
	public:
		// 添加一个单词
		void addWord(Word* word);
		// 移除一个单词
		void removeWord(Word* word);
		// 移除所有单词
		void removeAllWords();
		// 获取一个单词信息
		const Word* getWord(const Text& text);
	private:
		// 文本
		typedef std::map<Text, Word*> FirstIndex;
	private:
		// 文本
		FirstIndex m_Texts;
	};
}