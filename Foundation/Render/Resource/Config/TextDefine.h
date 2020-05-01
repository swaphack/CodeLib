#pragma once

#include "system.h"
#include <string>

namespace render
{
	// 水平对齐方式
	enum HorizontalAlignment
	{
		EHA_LEFT,		// 左对齐
		EHA_CENTER,		// 居中对齐
		EHA_RIGHT,		// 右对齐
	};

	// 垂直对齐方式
	enum VerticalAlignment
	{
		EVA_TOP,		// 顶对齐
		EVA_CENTER,		// 居中对齐
		EVA_BOTTOM,		// 底对齐
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
		sys::Color3B color;

		// 水平对齐方式
		HorizontalAlignment horizontalAlignment;
		// 垂直对齐方式
		VerticalAlignment verticalAlignment;

		TextDefine()
			:filepath("")
			, fontSize(0)
			, horizontalDistance(0)
			, verticalDistance(0)
			, text("")
			, width(0)
			, height(0)
			, horizontalAlignment(EHA_CENTER)
			, verticalAlignment(EVA_CENTER)
		{

		}
	};
}