#pragma once

#include "macros.h"
namespace render
{
	/**
	*	渲染
	*/
	class GLRender
	{
	public:
		static void clear(int mask);
		static void clear(ClearBufferBitType mask);
		/**
		*	drawbuffer:mask为GL_COLOR时为GL_DRAW_BUFFER[n]，否则为0
		*	value  buffer为GL_COLOR时为rgba四元素指针
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