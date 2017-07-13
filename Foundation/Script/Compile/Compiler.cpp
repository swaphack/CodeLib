#include "Compiler.h"
#include "../Document/CompilerDocument.h"
#include "../Core/Console.h"
#include "Scanner.h"
#include "Parser.h"
#include "SemanticAnalyzer.h"
#include "SourceCodeOptimizer.h"
#include "CodeGenerator.h"
#include "TargetCodeOptimizer.h"

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

Compiler* Compiler::getInstance()
{
	static Compiler s_Compiler;
	return &s_Compiler;
}

bool Compiler::compile(CompilerDocument* document)
{
	if (document == nullptr)
	{
		return false;
	}

	Console::getInstance()->info("===================");
	do 
	{
		Console::getInstance()->info("1. scan document");
		if (!m_pScanner->scan(document))
		{
			Console::getInstance()->warn("scan error");
			break;
		}

		Console::getInstance()->info("2. parse document");
		if (!m_pParser->parse(
			m_pScanner->getTokenTable()->tokenBegin(),
			m_pScanner->getTokenTable()->tokenEnd()))
		{
			Console::getInstance()->warn("parse error");
			break;
		}
	} while (0);
	Console::getInstance()->info("===================");
	return false;
}
