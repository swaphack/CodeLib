#pragma once

#include "macros.h"

namespace script
{
	// ������Ϣ
	struct SymbolInformation
	{
		// ����
		std::string name;
		// ���ʽ
		std::string expression;
		// ���ȼ�
		int priorityLevel;

		// �Ƿ���Ƕ
		bool embed;
		// ����
		std::string begin;
		// ���ʽ
		std::string end;

		SymbolInformation()
			:name(""), expression(""), priorityLevel(0)
			, embed(false), begin(""), end(""){}
	};
}