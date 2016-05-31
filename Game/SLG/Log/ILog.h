#pragma once

#include "Record.h"

namespace slg
{
	class ILog
	{
	public:
		virtual ~ILog() {}
	public:
		virtual IRecord* create();
	protected:
	private:
	};
}