#pragma once

#include "Texture.h"

namespace render
{
	// 2d多重采样纹理
	class Texture2DMultiSample : public Texture
	{
	public:
		Texture2DMultiSample();
		virtual ~Texture2DMultiSample();
	public:
		/**
		*	分配纹理缓存
		*/
		void setTextureStorage(int samples, TextureInternalFormat internalFormat, int width, int height, bool fixedSamplelocations);
	public:
		/**
		*	设置纹理
		*/
		void setTextureImage(int samples, TextureInternalFormat internalFormat, int width, int height, bool fixedSamplelocations);
	};
}