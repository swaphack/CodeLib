#pragma once

#include "Texture.h"

namespace render
{
	// ����������ӳ�� ���λ��������ȼ�
	class TextureCubeMap : public Texture
	{
	public:
		TextureCubeMap();
		virtual ~TextureCubeMap();
	public:
		// depth Ϊ6�ı�������Ϊһ����������������
		void setTextureStorage(int levels, TextureInternalFormat internalFormat, int width, int height, int depth);
	};
}