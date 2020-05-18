#pragma once

#include "system.h"
#include "mathlib.h"

// 形状
namespace render
{
	// 矩形框顶点集
	struct RectVectices
	{
		// 左下角
		math::Vector3 leftDown;
		// 右下角
		math::Vector3 rightDown;
		// 右上角
		math::Vector3 rightUp;
		// 左上角
		math::Vector3 leftUp;

		RectVectices();

		// 判断
		bool containPoint(float x, float y);
		//  获取点坐在的锚点位置
		math::Vector3 getAnchorByPoint(float x, float y);
	};

	// 立方体顶点集
	struct CubeVectices
	{
		// 前面
		RectVectices front;
		// 背面
		RectVectices back;
		// 左面
		RectVectices left;
		// 右面
		RectVectices right;
		// 顶部
		RectVectices top;
		// 底部
		RectVectices bottom;

		CubeVectices()
		{ }
	};
}