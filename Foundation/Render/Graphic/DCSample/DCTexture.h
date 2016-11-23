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
		sys::Vector Position[4];
		// �ĸ���������
		sys::Vector Coord[4];
		// ����
		sys::Vector Normal;
		// ��ɫ����
		BlendParam Blend;
	public:
		DCTexture();
		virtual ~DCTexture();
	public:
		virtual void draw();
	public:
		static DCTexture* create(int textureID, const TextureRect* texRect, const sys::Color4B& color, uchar opacity, const BlendParam& blend, const sys::Vector& normal = sys::Vector::Zero);
	};
}