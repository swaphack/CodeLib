#pragma once

#include "system.h"

namespace slg
{
	class IRecord
	{
	public:
		virtual ~IRecord() {}
	public:
		virtual sys::Time* getTime() = 0;
		virtual const char* getText() = 0;
	};
}