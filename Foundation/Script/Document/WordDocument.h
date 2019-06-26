#pragma once

#include "Document.h"

namespace script
{
	class WordSet;

	// 单词文档解析
	class WordDocument : public Document
	{
	public:
		WordDocument();
		virtual ~WordDocument();
	public:
		// 词组集合
		void setWordSet(WordSet* pWordSet);
		// 
		WordSet* getWordSet();
	protected:
		// 转化成文档格式
		virtual bool convertToDocumentStruct();
		// 转化成文本格式
		virtual bool convertToTextStruct();
	private:
		WordSet* m_pWordSet;
	};
}