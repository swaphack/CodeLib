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
		// ��������
		void setSeed(unsigned int seed);
		// ��������
		void setRange(float minValue, float maxValue);
		// ��ȡ��һ����ֵ
		float getNextNumber();
		// ��ȡ��һ������
		int getNextInteger();
	protected:
	private:
		// ��Сֵ
		float _min;
		// ���ֵ
		float _max;
	};
}