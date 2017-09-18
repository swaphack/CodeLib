#pragma once

namespace sys
{
	struct Range
	{
	public:
		float min = 0;
		float max = 0;
	public:
		Range(float min, float max)
		{
			this->min = min;
			this->max = max;
		}
		Range()
		{
			this->min = 0;
			this->max = 0;
		}

	public:
		bool in(float value)
		{
			return value >= min && value <= max;
		}
	};
}