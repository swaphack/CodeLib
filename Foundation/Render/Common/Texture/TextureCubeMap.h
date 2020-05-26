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
		void load(const sys::ImageDetail* imageDetails[6], const TextureSetting& setting = TextureSetting());
	};
}