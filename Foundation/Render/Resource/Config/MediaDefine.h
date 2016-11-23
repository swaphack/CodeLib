#pragma once

#include <string>

namespace render
{
	// 媒体数据描述结构
	struct MediaDefine
	{
		// 文件路径
		std::string filepath;


		MediaDefine()
			:filepath("")
		{}
	};
}