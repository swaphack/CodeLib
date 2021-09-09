#pragma once

#include "Texture.h"

namespace render
{
	// ����������ӳ�� ���ά��������ȼ�
	class TextureCubeMap : public Texture
	{
	public:
		TextureCubeMap();
		virtual ~TextureCubeMap();
	public:
		void load(int count, sys::ImageDetail** imageDetails, const TextureSetting& setting = TextureSetting());
	};
}