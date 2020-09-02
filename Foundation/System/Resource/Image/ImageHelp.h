#pragma once

#include "ImageDetail.h"
#include <string>

namespace sys
{
	class ImageHelp
	{
	public:
		/**
		*	保存图片信息到png文件
		*/
		static bool saveToPNG(const ImageDetail& detail, const std::string& fullpath);
		/**
		*	保存图片信息到jpeg文件
		*/
		static bool saveToJPEG(const ImageDetail& detail, const std::string& fullpath);
	private:
		/**
		*	获取像素大小
		*/
		static int getImageUnitSize(ImageDataFormat dataFormat);
		/**
		*	获取png颜色类型
		*/
		static int getPNGColorType(ImageDataFormat dataFormat);
		/**
		*	获取JPEG颜色类型
		*/
		static int getJPEGColorType(ImageDataFormat dataFormat);
	};
}