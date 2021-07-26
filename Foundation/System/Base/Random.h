#pragma once

#include <cstdint>

namespace sys
{
	// 随机数
	class Random
	{
	private:
		Random();
		~Random();
	public:
		/** 
		*	设置种子
		*/
		static void setSeed(uint32_t seed);
		/**
		*	设置种子
		*/
		static uint32_t getSeed();
	public:
		/**
		*	设置区间的浮点数， 包含最小值，不包含最大值
		*/ 
		static float getNumber(float minValue, float maxValue);
		/**
		*	获取下一个数值， 包含最小值，不包含最大值
		*/  
		static uint32_t getNumber(uint32_t maxValue);
		/**
		*	获取下一个数值， 包含最小值，不包含最大值
		*/
		static int32_t getNumber(int32_t maxValue);
		/**
		*	获取区间内的整形, 包含最小值，不包含最大值
		*/   
		static int32_t getNumber(int32_t minValue, int32_t maxValue);
	public:
		/**
		*	设置区间的浮点数
		*/
		static float getNumber0_1();
		/**
		*	获取int区间的值
		*/
		static int32_t getNumber0_max();
	private:
		static uint32_t _seed;
	};
}