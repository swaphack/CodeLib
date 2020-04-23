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
	public:
		static void setIndexMask(uint32_t mask);
	public:
		static void pushAttrib(AttribMask value);
		static void popAttrib();
	public:
		/**
		*	阴影样式
		*/
		static void setShadeModel(ShadingModel model);
	};
}