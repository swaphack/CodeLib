#pragma once

#include "macros.h"
namespace render
{
	/**
	*	��Ⱦ
	*/
	class GLRender
	{
	public:
		static void clear(int mask);
		static void clear(ClearBufferBitType mask);
		/**
		*	drawbuffer:maskΪGL_COLORʱΪGL_DRAW_BUFFER[n]������Ϊ0
		*	value  bufferΪGL_COLORʱΪrgba��Ԫ��ָ��
		*/
		static void clearBuffer(ClearBufferType mask, int drawbuffer, const float* value);
		static void clearBuffer(ClearBufferType mask, int drawbuffer, const int* value);
		static void clearBuffer(ClearBufferType mask, int drawbuffer, const uint32_t* value);
		static void clearBuffer(float depth, float stencil);

		static void clearColor(float red, float green, float blue, float alpha);

		static void clearDepth(float depth);
		static void clearStencil(int mask);
	public:

		static void setDrawBuffMode(DrawBufferMode mode);
		static void setNamedFramebufferDrawBuffer(GLuint framebuffer, DrawBufferMode mode);
	public:
		static void finish();
		static void flush();
	public:
		static void setReadBuffer(ReadBufferMode mode);
		static void setNamedFramebufferReadBuffer(GLuint framebuffer, DrawBufferMode mode);

		static void readPixels(float x, float y, float width, float height, ReadPixelDataFormat pixelFormat, ReadPixelDataType pixelType, void* data);
	};
}