#pragma once

#include "Scanner.h"
#include "Parser.h"
#include "SemanticAnalyzer.h"
#include "SourceCodeOptimizer.h"
#include "CodeGenerator.h"
#include "TargetCodeOptimizer.h"

namespace script
{
	// 编译器
	class Compiler
	{
	public:
		Compiler();
		~Compiler();
	public:
		void read(const char* text, int size);
	protected:
		bool doScan();
		bool doParse();
		bool doSemanticAnalyze();
		bool doSourceCodeOptimize();
		bool doCodeGenerate();
		bool doTargetCodeOptimize();
	private:
		// 扫描程序
		Scanner* m_pScanner;
		// 语法分析
		Parser* m_pParser;
		// 语义分析
		SemanticAnalyzer* m_pSemanticAnalyzer;
		// 优化程序
		SourceCodeOptimizer* m_pSourceCodeOptimizer;
		// 代码生成
		CodeGenerator* m_pCodeGenerator;
		// 目标代码
		TargetCodeOptimizer* m_pTargetCodeOptimizer;
	};
}