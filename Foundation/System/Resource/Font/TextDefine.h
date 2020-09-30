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
		float fontSize = 0;
		// 水平字间距
		float horizontalDistance = 0;
		// 垂直间距
		float verticalDistance = 0;
		// 显示的文本
		std::string text;

		// 宽度
		float width = 0;
		// 高度
		float height = 0;

		// 颜色
		Color3B color;

		// 加粗
		bool border = false;

		// 水平对齐方式
		sys::HorizontalAlignment horizontalAlignment = sys::HorizontalAlignment::CENTER;
		// 垂直对齐方式
		sys::VerticalAlignment verticalAlignment = sys::VerticalAlignment::MIDDLE;

		TextDefine()
		{

		}
	};
}