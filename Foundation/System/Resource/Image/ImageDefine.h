#pragma once

#include <string>
#include <algorithm>

namespace sys
{
	//	图片资源格式
	enum class ImageFormat
	{
		NONE = 0,
		PNG,	// png
		JPEG,	// jpg
		TARGA,	// tga
		BMP,	// bmp
		TIFF,	// tif
	};

#define IMAGE_FORMAT_PNG "png"
#define IMAGE_FORMAT_JPG "jpg"
#define IMAGE_FORMAT_TGA "tga"
#define IMAGE_FORMAT_BMP "bmp"
#define IMAGE_FORMAT_TIF "tif"

	// 图片数据描述结构
	struct ImageDefine
	{
		// 图片路径
		std::string filepath;

		// 图片格式
		ImageFormat format;

		ImageDefine(const ImageDefine& value);

		ImageDefine(const std::string& _filename = "", ImageFormat _format = ImageFormat::NONE);

		void setFilePath(const std::string& _filename);
	};
}