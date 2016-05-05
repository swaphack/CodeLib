#pragma once

#include "system.h"

// 形状
namespace render
{
	// 矩形框顶点集
	struct RectangeVertex
	{
		// 左下角
		sys::Vector leftDown;
		// 右下角
		sys::Vector rightDown;
		// 右上角
		sys::Vector rightUp;
		// 左上角
		sys::Vector leftUp;

		RectangeVertex()
		{

		}
	};
}