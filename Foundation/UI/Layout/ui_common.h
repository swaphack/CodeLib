#pragma once

#include "system.h"

namespace ui
{
	// 大小调整类型
	enum class SizeType
	{
		// 固定
		FIXED,
		// 缩小到最小时保持最小
		MINIMUM,
		// 放大到最大时保持最大
		MAXIMUM,
		// 自动缩放
		EXPANDING,
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

		SizePolicy() :width(SizeType::EXPANDING), height(SizeType::EXPANDING){}
		SizePolicy(SizeType w, SizeType h) :width(w), height(h){}

		SizePolicy& operator=(const SizePolicy& value)
		{
			width = value.width;
			height = value.height;

			return *this;
		}
	};

	/**
	*	元素类型
	*/
	enum class ElementType
	{
		/**
		*	未定义
		*/
		NONE,
		/**
		*	控件
		*/
		WIDGET,
		/**
		*	布局
		*/
		LAYOUT,
	};

	/**
	*	布局方向
	*/
	enum class LayoutDirection
	{
		// 无
		NONE,
		// 垂直布局
		HORIZONTAL,
		// 水平布局
		ERTICAL,
	};

	/**
	* 位置
	*/
	enum class AnchorPosition
	{
		// 无，默认
		NONE,
		DOWN_LEFT,
		DOWN_CENTER,
		DOWN_RIGHT,
		CENTER_LEFT,
		CENTER_CENTER,
		CENTER_RIGHT,
		UP_LEFT,
		UP_CENTER,
		UP_RIGHT,
	};
}