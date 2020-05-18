#pragma once

#include "Graphic/GLAPI/macros.h"
#include <cstdint>
namespace render
{
	/**
	*	���ز���
	**/
	class MultiSampling
	{
	public:
		static bool isSupport();
	public:
		static void enable();
		static void disable();
	public:
		/**
		*	ǿ�ƿ�����ɫ������
		*/
		static void enableShader();
		static void setMinSampleShader(float value);
		static void disableShader();
	public:
		/**
		*	������
		*/
		static int getSamples();
		/**
		*	��ȡ����λ�������Ĳ���ֵ
		*/
		static void getMultiSample(uint32_t index, float* value);
	};
}
