#pragma once

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

		SizePolicy() :width(SizeType::EXPANDING), height(SizeType::EXPANDING) {}
		SizePolicy(SizeType w, SizeType h) :width(w), height(h) {}

		SizePolicy& operator=(const SizePolicy& value)
		{
			width = value.width;
			height = value.height;

			return *this;
		}
	};
}
