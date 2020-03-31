#pragma once
#include "macros.h"

namespace render
{
	/**
	*	像素
	*/
	class GLPixels
	{
	public:
		static void setDrawBuffMode(DrawBufferMode mode);
	public:
		static void setIndexMask(int mask);
		static void setColorMask(bool red, bool green, bool blue, bool alpha);
		static void setDepthMask(bool flag);

		/**
		*	0xFF == 0b11111111
		*	此时，模板值与它进行按位与运算结果是模板值，模板缓冲可写
		*	0x00 == 0b00000000 == 0
		*	此时，模板值与它进行按位与运算结果是0，模板缓冲不可写
		*/
		static void setStencilMask(int mask);
	public:
		static void clearBuffer(int mask);
		static void clearBuffer(ClearBufferMask mask);
	public:
		static void clearColor(float red, float green, float blue, float alpha);
		static void clearIndex(int mask);
		static void clearDepth(float depth);
		static void clearStencil(int mask);
		static void clearAccum(float red, float green, float blue, float alpha);
	public:
		// 读取像素
		static void readPixels(float x, float y, float width, float height, PixelFormat pixelFormat, PixelType pixelType, void* data);
		// 复制数据到缓存区
		static void copyPixels(float x, float y, float width, float height, PixelCopyType copyType);
	public:
		static void setReadBufferMode(ReadBufferMode mode);
	public:
		static void copyTexImage1D(int nLevel, TextureParameter internalFormat, int x, int y, int width, int border);
		static void copyTexImage2D(int nLevel, TextureParameter internalFormat, int x, int y, int width, int height, int border);

		static void copyTexSubImage1D(int nLevel, int xoffset,int x, int y, int width);
		static void copyTexSubImage2D(int nLevel, int xoffset, int yoffset, int x, int y, int width, int height);
	};
}