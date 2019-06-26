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
	protected:
		// 转化成文档格式
		virtual bool convertToDocumentStruct();
		// 转化成文本格式
		virtual bool convertToTextStruct();
	private:
		// 扫描器
		Compiler* m_pCompiler;
		// 语法分析
		Parser* m_pParser;
	};
}