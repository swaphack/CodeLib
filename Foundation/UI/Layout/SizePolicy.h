#pragma once

#include "system.h"

namespace ui
{
	// 大小调整类型
	enum SizeType
	{
		// 固定
		EST_Fixed,
		// 缩小到最小时保持最小
		EST_Minimum,
		// 放大到最大时保持最大
		EST_Maximum,
		// 自动缩放
		EST_Expanding,
	};

	/**
	*	 面积大小调整策略
	*/
	struct SizePolicy 
	{
		// 宽度调整策略
		SizeType width;
		// 高度调整策略
		SizeType height;

		SizePolicy() :width(EST_Expanding), height(EST_Expanding){}
		SizePolicy(SizeType w, SizeType h) :width(w), height(h){}

		SizePolicy& operator=(const SizePolicy& value)
		{
			width = value.width;
			height = value.height;

			return *this;
		}
	};
}