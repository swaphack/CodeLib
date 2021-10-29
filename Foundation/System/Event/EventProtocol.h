#pragma once

#include <functional>

namespace sys
{
	class Event;
	class EventProtocol
	{
	public:
		virtual ~EventProtocol() {}
	public:
		virtual void onDispatch(const Event* evt) const = 0;
	};

	typedef std::function<void(const Event* evt)> EventFunc;
}
