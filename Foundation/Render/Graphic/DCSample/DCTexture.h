#pragma once

#include "DCColor.h"

namespace render
{
	/**
	*	绘制纹理命令
	*/
	class DCTexture : public DCColor
	{
	public:
		// 纹理id
		int TextureID;
		// 四个顶点坐标
		math::Vector3 Position[4];
		// 四个纹理坐标
		math::Vector3 Coord[4];
		// 法线
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