#pragma once

#include "T_Text.h"
#include "Enumerator.h"

#include <map>

namespace ll
{
	// 文本结构
	typedef std::string Text;

	// 单词意思 {词性，说明}
	typedef std::map<WordNominal, Text> WordMeaning;

	// 单词
	struct Word
	{		
	public:
		Word(const Text& value);
		Word(const Text& value, const WordMeaning& meaning);
		// 哈希编号
		int hashID() const;
		// 文本
		const Text& value() const;
		// 顺序
		const char index() const;
		// 是否为空
		bool empty() const;
		// 销毁
		void release();
	private:
		static int s_HashID;
		// 文本
		Text _value;
		// 词意
		WordMeaning _meaning;
		// 哈希编号
		int _hashID;
	};
}