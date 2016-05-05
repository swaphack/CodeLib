#pragma once

#include "Object.h"

namespace sys
{
	class IHandler
	{
	public:
		virtual ~IHandler() {}
	public:
		virtual void hand(Object* command) = 0;
	protected:
	private:
	};
}