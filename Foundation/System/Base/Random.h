#pragma once

#include "Types.h"

namespace sys
{
	// 随机数
	class Random
	{
	private:
		Random();
	public:
		~Random();
	public:
		static Random* getInstance();
		// 设置种子
		void setSeed(unsigned int seed);
		// 设置区间
		void setRange(float minValue, float maxValue);
		// 获取下一个数值
		float getNextNumber();
		// 获取下一个整形
		int getNextInteger();
	protected:
	private:
		// 最小值
		float _min;
		// 最大值
		float _max;
	};
}