#pragma once

#include "../Time/import.h"

namespace slg
{
	class IRecord
	{
	public:
		virtual ~IRecord() {}
	public:
		virtual const DateTime* getTime() = 0;
	protected:
	private:
	};
}