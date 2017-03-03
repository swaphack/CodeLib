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
		//uchar Opacity;
		// �ĸ���������
		sys::Vector3 Position[4];
		// �ĸ���������
		sys::Vector3 Coord[4];
		// ����
		sys::Vector3 Normal;
		// ��ɫ����
		BlendParam Blend;
	public:
		DCTexture();
		virtual ~DCTexture();
	public:
		virtual void draw();
	public:
		static DCTexture* create(int textureID, const TextureRect* texRect, const sys::Color4B& color, uchar opacity, const BlendParam& blend, const sys::Vector3& normal = sys::Vector3::Zero);
	};
}