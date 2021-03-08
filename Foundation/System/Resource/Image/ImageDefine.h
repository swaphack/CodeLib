#pragma once

#include <string>
#include <algorithm>

namespace sys
{
	//	ͼƬ��Դ��ʽ
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

	// ͼƬ���������ṹ
	struct ImageDefine
	{
		// ͼƬ·��
		std::string filepath;

		// ͼƬ��ʽ
		ImageFormat format;

		ImageDefine(const ImageDefine& value);

		ImageDefine(const std::string& _filename = "", ImageFormat _format = ImageFormat::NONE);

		void setFilePath(const std::string& _filename);
	};
}