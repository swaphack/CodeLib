#pragma once

#include "macros.h"

namespace script
{
	class ASTNode;
	class VariableTable;

	/**
	*	�������
	*/
	class SemanticAnalyzer
	{
	public:
		SemanticAnalyzer();
		~SemanticAnalyzer();
	public:
		// �����ڵ�
		bool analyze(ASTNodeVec::const_iterator begin, ASTNodeVec::const_iterator end);
	private:
		// ������
		VariableTable* m_pVarTable;
	};
}