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
	public:
		// ����
		virtual bool parse();
	private:
		// ɨ����
		Compiler* m_pCompiler;
		// �﷨����
		Parser* m_pParser;
	};
}