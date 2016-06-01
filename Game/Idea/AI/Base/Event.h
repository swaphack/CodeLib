#pragma once

#include "Message.h"

namespace idea
{
	// ÊÂ¼ş
	class Event
	{
	public:
		Event();
		virtual ~Event() {}
	public:
		virtual Message* getMessage() = 0;
	protected:
	private:
	};
}