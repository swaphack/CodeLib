#pragma once

#include "Types.h"

namespace sys
{
	// �����
	class Random
	{
	private:
		Random();
	public:
		~Random();
	public:
		static Random* getInstance();
		void setRange(float minValue, float maxValue);
		float getNextNumber();
	protected:
	private:
		float _min;
		float _max;
	};
}