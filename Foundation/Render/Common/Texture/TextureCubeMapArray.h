#pragma once

#include "Texture.h"

namespace render
{
	// ����������ӳ��
	class TextureCubeMapArray : public Texture
	{
	public:
		TextureCubeMapArray();
		virtual ~TextureCubeMapArray();
	public:
		// depth Ϊ6�ı�������Ϊһ����������������
		void setTextureStorage(int levels, TextureInternalSizedFormat internalFormat, int width, int height, int depth);
		/**
		*	������������
		*/
		void setTextureSubImage(int level, int xoffset, int yoffset, int zoffset, int width, int height, int depth, TextureExternalFormat format, TextureExternalDataType type, const void* pixels);
	};
}