#pragma once

#include <string>
#include <vector>

#include "../../Core/import.h"

namespace script
{
	typedef std::vector<std::string> Token;

	class ASTNode;
	typedef std::vector<ASTNode*> ASTNodeVec;

	// 节点位置
	enum NodePosition
	{
		// 左
		ENP_LEFT,
		// 中
		ENP_MIDDLE,
		// 右
		ENP_RIGHT,
	};


}