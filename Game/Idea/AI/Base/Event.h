#pragma once

#include "Message.h"

namespace idea
{
	// �¼�
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