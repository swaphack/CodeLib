#pragma once

#include "Scope.h"

#include <vector>

namespace script
{
	class Variable;

	// ����
	class Function : public Scope
	{
	public:
		Function();
		virtual ~Function();
	public:
	};
}