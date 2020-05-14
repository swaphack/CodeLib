#pragma once

#include <string>
#include "Light/ColorSample.h"

namespace sys
{
	// 水平对齐方式
	enum class HorizontalAlignment
	{
		LEFT,		// 左对齐
		CENTER,		// 居中对齐
		RIGHT,		// 右对齐
	};

	// 垂直对齐方式
	enum class VerticalAlignment
	{
		TOP,		// 顶对齐
		MIDDLE,		// 居中对齐
		BOTTOM,		// 底对齐
	};

	// 文本数据描述结构
	struct TextDefine
	{
		// 字库路径
		std::string filepath;
		// 字体大小
		float fontSize;
		// 水平字间距
		float horizontalDistance;
		// 垂直间距
		float verticalDistance;
		// 显示的文本
		std::string text;

		// 宽度
		float width;
		// 高度
		float height;

		// 颜色
		Color3B color;

		// 水平对齐方式
		sys::HorizontalAlignment horizontalAlignment;
		// 垂直对齐方式
		sys::VerticalAlignment verticalAlignment;

		TextDefine()
			:filepath("")
			, fontSize(0)
			, horizontalDistance(0)
			, verticalDistance(0)
			, text("")
			, width(0)
			, height(0)
			, horizontalAlignment(sys::HorizontalAlignment::CENTER)
			, verticalAlignment(sys::VerticalAlignment::MIDDLE)
		{

		}
	};
}