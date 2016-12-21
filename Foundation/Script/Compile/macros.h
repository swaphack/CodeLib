#pragma once

#include <string>
#include <vector>

namespace script
{
	typedef std::vector<std::string> Token;

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