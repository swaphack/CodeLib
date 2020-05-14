#pragma once

namespace sys
{
	class ITimer
	{
	public:
		virtual ~ITimer() {}
	public:
		virtual void update(float interval) = 0;
	};
}