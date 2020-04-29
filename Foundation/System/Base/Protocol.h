#pragma once

#include <string>
#include <cstdint>
#include "macros.h"

namespace sys
{
	class Name
	{
	public:
		Name() {}
		virtual ~Name() {}
	public:
		CREATE_CLASS_MEMBER(std::string, Name);
	};

	class Identify
	{
	public:
		Identify() {}
		virtual ~Identify() {}
	public:
		CREATE_CLASS_MEMBER_WITH_DEFAULT(int32_t, ID, 0);
	};
}