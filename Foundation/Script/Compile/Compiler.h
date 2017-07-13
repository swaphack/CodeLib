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
	// ������
	class Compiler
	{
	private:
		Compiler();
		~Compiler();
	public:
		static Compiler* getInstance();

		bool compile(CompilerDocument* document);
	private:
		// ɨ�����
		Scanner* m_pScanner;
		// �﷨����
		Parser* m_pParser;
		// �������
		SemanticAnalyzer* m_pSemanticAnalyzer;
		// �Ż�����
		SourceCodeOptimizer* m_pSourceCodeOptimizer;
		// ��������
		CodeGenerator* m_pCodeGenerator;
		// Ŀ�����
		TargetCodeOptimizer* m_pTargetCodeOptimizer;
	};
}