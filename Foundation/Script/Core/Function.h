#pragma once

#include "Scope.h"
#include <functional>
#include <vector>
#include <map>
#include <string>

namespace script
{
	class Variable;

	// º¯Êý
	class Function : public Scope
	{
	public:
		Function();
		virtual ~Function();
	public:
	};
}