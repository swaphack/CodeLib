#pragma once

#include "macros.h"

namespace render
{
	/**
	*	绘制纹理命令
	*/
	class DCTexture : public DrawCommand
	{
	public:
		// 纹理id
		int TextureID;
		// 颜色
		sys::Color4F Color;
		// 不透明度
		//uint8_t Opacity;
		// 四个顶点坐标
		math::Vector3 Position[4];
		// 四个纹理坐标
		math::Vector3 Coord[4];
		// 法线
		math::Vector3 Normal;
		// 混色参数
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