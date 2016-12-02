#include "Compiler.h"

using namespace  script;


Compiler::Compiler()
{
	m_pScanner = new Scanner();
	m_pParser = new Parser();
	m_pSemanticAnalyzer = new SemanticAnalyzer();
	m_pSourceCodeOptimizer = new SourceCodeOptimizer();
	m_pCodeGenerator = new CodeGenerator();
	m_pTargetCodeOptimizer = new TargetCodeOptimizer();
}

Compiler::~Compiler()
{

}

bool Compiler::compile(const char* text, int size)
{

	if (text == nullptr)
	{
		return false;
	}

	if (!m_pScanner->scan(text, size))
	{
		return false;
	}

	if (!m_pParser->parse(m_pScanner->tokenBegin(), m_pScanner->tokenEnd()))
	{
		return false;
	}


	return false;
}