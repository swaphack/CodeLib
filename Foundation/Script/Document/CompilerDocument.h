#pragma once

#include "Document.h"

namespace script
{
	class Compiler;
	class Parser;

	// �ű��ĵ�����
	class CompilerDocument : public Document
	{
	public:
		CompilerDocument();
		virtual ~CompilerDocument();
	protected:
		// ת�����ĵ���ʽ
		virtual bool convertToDocumentStruct();
		// ת�����ı���ʽ
		virtual bool convertToTextStruct();
	private:
		// ɨ����
		Compiler* m_pCompiler;
		// �﷨����
		Parser* m_pParser;
	};
}