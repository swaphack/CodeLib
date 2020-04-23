#pragma once
#include "macros.h"

namespace render
{
	/**
	*	ÏñËØ
	*/
	class GLPixels
	{
	public:
		static void setDrawBuffMode(DrawBufferMode mode);
	public:
		
	public:
		
	public:
		// ¶ÁÈ¡ÏñËØ
		static void readPixels(float x, float y, float width, float height, PixelFormat pixelFormat, PixelType pixelType, void* data);
	public:
	public:
		static void copyTexImage1D(int nLevel, TextureParameter internalFormat, int x, int y, int width, int border);
		static void copyTexImage2D(int nLevel, TextureParameter internalFormat, int x, int y, int width, int height, int border);

		static void copyTexSubImage1D(int nLevel, int xoffset,int x, int y, int width);
		static void copyTexSubImage2D(int nLevel, int xoffset, int yoffset, int x, int y, int width, int height);
	};
}