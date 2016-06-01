#pragma once

#include "Record.h"

namespace slg
{
	class ILog
	{
	public:
		virtual ~ILog() {}
	public:
		virtual IRecord* create() = 0;
	protected:
	private:
	};
}