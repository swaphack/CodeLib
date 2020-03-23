#pragma once

#include "DCColor.h"

namespace render
{
	/**
	*	������������
	*/
	class DCTexture : public DCColor
	{
	public:
		// ����id
		int TextureID;
		// �ĸ���������
		math::Vector3 Position[4];
		// �ĸ���������
		math::Vector3 Coord[4];
		// ����
		math::Vector3 Normal;
	public:
		DCTexture();
		virtual ~DCTexture();
	protected:
		virtual void drawDC();
	public:
		static DCTexture* create(int textureID, const TextureRect* texRect, const sys::Color4B& color, uint8_t opacity, const BlendParam& blend, const math::Vector3& normal = math::Vector3());
	};
}