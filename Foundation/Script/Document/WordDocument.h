#pragma once

#include "Document.h"

namespace script
{
	class WordSet;

	// �����ĵ�����
	class WordDocument : public Document
	{
	public:
		WordDocument();
		virtual ~WordDocument();
	public:
		// ���鼯��
		void setWordSet(WordSet* pWordSet);
		// 
		WordSet* getWordSet();
	protected:
		// ת�����ĵ���ʽ
		virtual bool convertToDocumentStruct();
		// ת�����ı���ʽ
		virtual bool convertToTextStruct();
	private:
		WordSet* m_pWordSet;
	};
}