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
		bool compile(const char* text, int size);
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