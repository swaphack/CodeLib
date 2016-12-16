#pragma once

#include "Document.h"

namespace script
{
	class Compiler;
	class Parser;

	// 脚本文档解析
	class CompilerDocument : public Document
	{
	public:
		CompilerDocument();
		virtual ~CompilerDocument();
	public:
		// 解析
		virtual bool parse();
	private:
		// 扫描器
		Compiler* m_pCompiler;
		// 语法分析
		Parser* m_pParser;
	};
}