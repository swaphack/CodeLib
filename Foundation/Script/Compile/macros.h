#pragma once

#include <string>
#include <vector>

namespace script
{
	typedef std::vector<std::string> Token;

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
}