#pragma once

#include "system.h"
#include <string>

namespace render
{
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
		sys::Color4B color;

		TextDefine()
			:filepath("")
			, fontSize(0)
			, horizontalDistance(0)
			, verticalDistance(0)
			, text("")
			, width(0)
			, height(0)
		{

		}
	};
}