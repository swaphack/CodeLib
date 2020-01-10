#pragma once

#include "macros.h"

namespace render
{
	/**
	*	������������
	*/
	class DCTexture : public DrawCommand
	{
	public:
		// ����id
		int TextureID;
		// ��ɫ
		sys::Color4F Color;
		// ��͸����
		//uint8_t Opacity;
		// �ĸ���������
		math::Vector3 Position[4];
		// �ĸ���������
		math::Vector3 Coord[4];
		// ����
		math::Vector3 Normal;
		// ��ɫ����
		BlendParam Blend;
	public:
		DCTexture();
		virtual ~DCTexture();
	public:
		virtual void draw();
	public:
		static DCTexture* create(int textureID, const TextureRect* texRect, const sys::Color4B& color, uint8_t opacity, const BlendParam& blend, const math::Vector3& normal = math::Vector3());
	};
}