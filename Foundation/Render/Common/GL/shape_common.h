#pragma once

#include "system.h"
#include "mathlib.h"

// 形状
namespace render
{
	// 矩形框顶点集
	struct RectVertex
	{
		// 左下角
		math::Vector3 leftDown;
		// 右下角
		math::Vector3 rightDown;
		// 右上角
		math::Vector3 rightUp;
		// 左上角
		math::Vector3 leftUp;

		RectVertex();

		// 判断
		bool containPoint(float x, float y);
		//  获取点坐在的锚点位置
		math::Vector3 getAnchorByPoint(float x, float y);
	};

	// 立方体顶点集
	struct CubeVertex
	{
		// 前面
		RectVertex front;
		// 背面
		RectVertex back;
		// 左面
		RectVertex left;
		// 右面
		RectVertex right;
		// 顶部
		RectVertex top;
		// 底部
		RectVertex bottom;

		CubeVertex()
		{ }
	};
}