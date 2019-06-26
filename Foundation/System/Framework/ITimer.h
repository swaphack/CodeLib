#pragma once

namespace sys
{
	class ITimer
	{
	public:
		virtual ~ITimer() {}
	public:
		virtual void update(float int32erval) = 0;
	};
}