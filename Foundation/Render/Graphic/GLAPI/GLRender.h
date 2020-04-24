#pragma once

#include "macros.h"
namespace render
{
	/**
	*	‰÷»æ
	*/
	class GLRender
	{
	public:
		static void clearBuffer(int mask);
		static void clearBuffer(ClearBufferMask mask);
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
		static void setReadBufferMode(ReadBufferMode mode);
		static void setNamedFramebufferReadBuffer(GLuint framebuffer, DrawBufferMode mode);

		static void readPixels(float x, float y, float width, float height, TexImageDataFormat pixelFormat, TexImageDataType pixelType, void* data);
	};
}