#pragma once

#include "system.h"

// 形状
namespace render
{
	// 矩形框顶点集
	struct RectangeVertex
	{
		// 左下角
		sys::Vector3 leftDown;
		// 右下角
		sys::Vector3 rightDown;
		// 右上角
		sys::Vector3 rightUp;
		// 左上角
		sys::Vector3 leftUp;

		RectangeVertex();

		// 判断
		bool containPoint(float x, float y);
		//  获取点坐在的锚点位置
		sys::Vector3 getAnchorByPoint(float x, float y);
	};
}