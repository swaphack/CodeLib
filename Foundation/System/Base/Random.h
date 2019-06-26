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
		void setSeed(uint32 seed);
		// 设置区间
		void setRange(float minValue, float maxValue);
		// 获取下一个数值
		float getNextNumber();
		// 获取下一个整形
		int32 getNextint32eger();
	protected:
	private:
		// 最小值
		float _min;
		// 最大值
		float _max;
	};
}