#pragma once

#include <string>
#include <vector>

#include "../../Core/import.h"

namespace script
{
	typedef std::vector<std::string> Token;

	class ASTNode;
	typedef std::vector<ASTNode*> ASTNodeVec;

	// �ڵ�λ��
	enum NodePosition
	{
		// ��
		ENP_LEFT,
		// ��
		ENP_MIDDLE,
		// ��
		ENP_RIGHT,
	};

#define IS_DECORATOR(x) (x == ' ' || x == '\r' || x == '\n' || x == '\t')
}