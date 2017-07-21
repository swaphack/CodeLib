#pragma once

#include "Scope.h"
#include <functional>
#include <vector>
#include <map>
#include <string>

namespace script
{
	class Variable;

	// 函数
	class Function : public Scope
	{
	public:
		Function();
		virtual ~Function();
	public:
		// 创建函数
		static Function* create(const char* funcName, ScopeHandler handler, AccessType accesType = E_ACCESSTYPE_PUBLIC);
	};
}