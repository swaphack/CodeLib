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

void Compiler::read(const char* text, int size)
{

}

bool Compiler::doScan()
{

}

bool Compiler::doParse()
{

}

bool Compiler::doSemanticAnalyze()
{

}

bool Compiler::doSourceCodeOptimize()
{

}

bool Compiler::doCodeGenerate()
{

}

bool Compiler::doTargetCodeOptimize()
{

}
