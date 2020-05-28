#pragma once

#include "Texture.h"

namespace render
{
	// 2d���ز�����������
	class Texture2DMultiSampleArray : public Texture
	{
	public:
		Texture2DMultiSampleArray();
		virtual ~Texture2DMultiSampleArray();
	public:
		/**
		*	����������
		*/
		void setTextureStorage(int samples, TextureInternalSizedFormat internalFormat, int width, int height, int depth, bool fixedSamplelocations);
	public:
		/**
		*	��������
		*/
		void setTextureImage(int samples, TextureInternalSizedFormat internalFormat, int width, int height, int depth, bool fixedSamplelocations);
	};
}