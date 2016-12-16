#pragma once

#include "T_Text.h"
#include "Enumerator.h"

#include <map>

namespace ll
{
	// 单词
	class Word
	{
	public:
		// 单词意思 {词性，说明}
		typedef std::map<WordNominal, T_Text> WordMeaning;
	public:
		// 文本
		T_Text Text;
		// 发音(拼音)
		T_Text Pronunciation;
		// 词意
		WordMeaning Meaning;
	public:

	};
}