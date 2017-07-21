#pragma once

#include "macros.h"

namespace script
{
	class ASTNode;
	class VariableTable;

	/**
	*	语义分析
	*/
	class SemanticAnalyzer
	{
	public:
		SemanticAnalyzer();
		~SemanticAnalyzer();
	public:
		// 分析节点
		bool analyze(ASTNodeVec::const_iterator begin, ASTNodeVec::const_iterator end);
	private:
		// 变量表
		VariableTable* m_pVarTable;
	};
}