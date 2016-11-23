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
		//uchar Opacity;
		// 四个顶点坐标
		sys::Vector Position[4];
		// 四个纹理坐标
		sys::Vector Coord[4];
		// 法线
		sys::Vector Normal;
		// 混色参数
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