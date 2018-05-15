#pragma once

namespace game
{
	/**
	*	����
	*/
	struct Interval
	{
	public:
		float Min = 0;
		float Max = 0;
	public:
		Interval()
			:Min(0), Max(0)
		{}
		Interval(float min, float max)
			:Min(min), Max(max)
		{
		}

		bool contains(float value)
		{
			return value >= Min && value <= Max;
		}
	};
}