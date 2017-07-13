#pragma once

namespace script
{
	class Scanner;
	class Parser;
	class SemanticAnalyzer;
	class SourceCodeOptimizer;
	class CodeGenerator;
	class TargetCodeOptimizer;

	class CompilerDocument;
	// 编译器
	class Compiler
	{
	private:
		Compiler();
		~Compiler();
	public:
		static Compiler* getInstance();

		bool compile(CompilerDocument* document);
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