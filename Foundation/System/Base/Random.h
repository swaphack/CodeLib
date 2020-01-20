#pragma once

#include <cstdint>

namespace sys
{
	// �����
	class Random
	{
	private:
		Random();
		~Random();
	public:
		/** 
		*	��������
		*/
		static void setSeed(uint32_t seed);
		/**
		*	��������
		*/
		static uint32_t getSeed();
	public:
		/**
		*	��������ĸ�����
		*/ 
		static float getNumber(float minValue, float maxValue);
		/**
		*	��ȡ��һ����ֵ
		*/  
		static uint32_t getNumber(uint32_t maxValue);
		/**
		*	��ȡ�����ڵ�����
		*/   
		static int32_t getNumber(int32_t minValue, int32_t maxValue);
	public:
		/**
		*	��������ĸ�����
		*/
		static float getNumber0_1();
		/**
		*	��������ĸ�����
		*/
		static int32_t getNumber0_max();
	private:
		static uint32_t _seed;
	};
}