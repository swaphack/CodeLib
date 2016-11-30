#pragma once

#include "Scanner.h"
#include "Parser.h"
#include "SemanticAnalyzer.h"
#include "SourceCodeOptimizer.h"
#include "CodeGenerator.h"
#include "TargetCodeOptimizer.h"

namespace script
{
	// ������
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