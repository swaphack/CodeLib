#pragma once

#include "macros.h"


namespace render
{
	class GLFixedFunction
	{
	public:
		/**
		*	�ۻ�����
		*/
		static void setAccum(AccumOp op, float value);
		/**
		*	͸���Ȳ���
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
		*	��Ӱ��ʽ
		*/
		static void setShadeModel(ShadingModel model);
	};
}