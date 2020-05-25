#pragma once

#include "Texture.h"

namespace render
{
	// 2d���ز�������
	class Texture2DMultiSample : public Texture
	{
	public:
		Texture2DMultiSample();
		virtual ~Texture2DMultiSample();
	public:
		/**
		*	������������
		*/
		void setTextureStorage(int samples, TextureInternalSizedFormat internalFormat, int width, int height, bool fixedSamplelocations);
	public:
		/**
		*	��������
		*/
		void setTextureImage(int samples, TextureInternalBaseFormat internalFormat, int width, int height, bool fixedSamplelocations);
	};
}