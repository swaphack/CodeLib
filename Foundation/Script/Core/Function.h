#pragma once

#include "Scope.h"
#include <functional>
#include <vector>
#include <map>
#include <string>

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
		// ��������
		static Function* create(const char* funcName, ScopeHandler handler, AccessType accesType = E_ACCESSTYPE_PUBLIC);
	};
}