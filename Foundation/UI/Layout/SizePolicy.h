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
	class SizePolicy : public sys::Object
	{
	public:
		SizePolicy();
		virtual ~SizePolicy();
	public:
		/**
		*	 设置宽度调整策略
		*/
		void setWidthType(SizeType type);
		/**
		*	 获取宽度调整策略
		*/
		SizeType getWidthType();
		/**
		*	 设置高度调整策略
		*/
		void setHeightType(SizeType type);
		/**
		*	 获取高度调整策略
		*/
		SizeType getHeightType();
	protected:
		// 宽度调整策略
		SizeType m_stWidth;
		// 高度调整策略
		SizeType m_stHeight;
	};
}