#include "Compiler.h"
#include "../Document/CompilerDocument.h"

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

bool Compiler::compile(CompilerDocument* document)
{
	if (document == nullptr)
	{
		return false;
	}

	if (!m_pScanner->scan(document))
	{
		return false;
	}

	std::vector<ASTNode*> nodeAry;

	if (!m_pParser->parse(
		m_pScanner->getTokenTable()->tokenBegin(), 
		m_pScanner->getTokenTable()->tokenEnd(), 
		nodeAry))
	{
		return false;
	}

	return false;
}