#pragma once

#include "Graphic/GLAPI/macros.h"
#include <cstdint>
namespace render
{
	/**
	*	多重采样
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
		*	强制开启作色器采样
		*/
		static void enableShader();
		static void setMinSampleShader(float value);
		static void disableShader();
	public:
		/**
		*	采样数
		*/
		static int getSamples();
		/**
		*	获取各个位置索引的采样值
		*/
		static void getMultiSample(uint32_t index, float* value);
	};
}
