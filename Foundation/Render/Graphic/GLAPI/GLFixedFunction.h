#pragma once

#include "macros.h"


namespace render
{
	class GLFixedFunction
	{
	public:
		/**
		*	累积缓存
		*/
		static void setAccum(AccumOp op, float value);
		/**
		*	透明度测试
		*/
		static void setAlphaFunc(AlphaFunction func, float value);
		static void clearAccum(float red, float green, float blue, float alpha);
	public:
		static void getTexEnv(TextureEnvTarget target, TextureEnvParameter parameter, float* value);
		static void getTexGen(TextureCoordName coord, TextureGenParameter parameter, float* value);

		static void setTexEnv(TextureEnvTarget target, TextureEnvParameter parameter, float value);
		static void setTexEnv(TextureEnvTarget target, TextureEnvParameter parameter, int value);
		static void setTexEnv(TextureEnvTarget target, TextureEnvParameter parameter, TextureEnvValue value);

		//  a single symbolic constant, single floating-point number, or an RGBA color
		static void setTexEnv(TextureEnvTargetv target, TextureEnvParameterv parameter, const float* value);
		//  a single symbolic constant, single floating-point number, or an RGBA color
		static void setTexEnv(TextureEnvTargetv target, TextureEnvParameterv parameter, const int* value);
	public:
		static void setIndexMask(uint32_t mask);
	public:
		static void pushAttrib(uint32_t value);
		static void pushAttrib(AttribMask value);
		static void popAttrib();
	public:
		/**
		*	阴影样式
		*/
		static void setShadeModel(ShadingModel model);
	};
}