#pragma once

#include <string>

namespace render
{
	//	图片资源格式
	enum ImageFormat
	{
		EIF_NONE = 0,
		EIF_PNG,	// png
		EIF_JPEG,	// jpeg;
	};

	// 图片数据描述结构
	struct ImageDefine
	{
		// 图片路径
		std::string filepath;

		// 图片格式
		ImageFormat format;

		ImageDefine(const char* filename = "", ImageFormat format = EIF_PNG)
			:filepath(filename)
			, format(format)
		{}
	};
}