#pragma once

#include "Texture.h"

namespace render
{
	// 2d多重采样纹理数组
	class Texture2DMultiSampleArray : public Texture
	{
	public:
		Texture2DMultiSampleArray();
		virtual ~Texture2DMultiSampleArray();
	public:
		/**
		*	分配纹理缓存
		*/
		void setTextureStorage(int samples, TextureInternalSizedFormat internalFormat, int width, int height, int depth, bool fixedSamplelocations);
	public:
		/**
		*	设置纹理
		*/
		void setTextureImage(int samples, TextureInternalSizedFormat internalFormat, int width, int height, int depth, bool fixedSamplelocations);
	};
}