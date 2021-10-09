#pragma once

#include <string>

namespace tp
{
	// 纹理打包工具
	class TexturePacker
	{
	public:
		TexturePacker();
		~TexturePacker();
	public:
		void addImage(const std::string& filepath)
	};
}