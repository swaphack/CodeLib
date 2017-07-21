#include "SemanticAnalyzer.h"
#include "VariableTable.h"

using namespace script;


SemanticAnalyzer::SemanticAnalyzer()
{
	m_pVarTable = new VariableTable();
}

SemanticAnalyzer::~SemanticAnalyzer()
{
	delete m_pVarTable;
}

bool SemanticAnalyzer::analyze(ASTNodeVec::const_iterator begin, ASTNodeVec::const_iterator end)
{

	return false;
}
