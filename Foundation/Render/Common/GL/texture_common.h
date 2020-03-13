#pragma once

#include "system.h"
#include "mathlib.h"

// 纹理
namespace render
{
	// 纹理坐标
	struct TextureVertex
	{
		// 顶点坐标
		math::Vector3 point;
		// 顶点纹理坐标
		math::Vector3 coords;
		// 顶点颜色
		sys::Color4B color;

		TextureVertex()
		{

		}
	};

	// 矩形纹理 逆时针方向
	struct TextureRect
	{
		// 左下角
		TextureVertex leftDown;
		// 右下角
		TextureVertex rightDown;
		// 右上角
		TextureVertex rightUp;
		// 左上角
		TextureVertex leftUp;

		TextureRect()
		{
			leftDown.coords = math::Vector3(0.0f, 0.0f, 0.0f);
			rightDown.coords = math::Vector3(1.0f, 0.0f, 0.0f);
			rightUp.coords = math::Vector3(1.0f, 1.0f, 0.0f);
			leftUp.coords = math::Vector3(0.0f, 1.0f, 0.0f);
		}
	};

	// 立方体纹理
	struct TextureCube
	{
		// 前面
		TextureRect front;
		// 背面
		TextureRect back;
		// 左面
		TextureRect left;
		// 右面
		TextureRect right;
		// 顶部
		TextureRect top;
		// 底部
		TextureRect bottom;

		TextureCube()
		{
		}
	};

	// 混合参数
	struct BlendParam
	{
		int src;
		int dest;

		BlendParam() :src(0), dest(0)
		{}

		BlendParam(int src, int dest) :src(src), dest(dest)
		{}

		BlendParam& operator=(const BlendParam& blend)
		{
			src = blend.src;
			dest = blend.dest;

			return *this;
		}
	};
}