#pragma once

#include "ImageDetail.h"
#include <string>

namespace sys
{
	class ImageHelp
	{
	public:
		/**
		*	����ͼƬ��Ϣ��png�ļ�
		*/
		static bool saveToPNG(const ImageDetail& detail, const std::string& fullpath);
		/**
		*	����ͼƬ��Ϣ��jpeg�ļ�
		*/
		static bool saveToJPEG(const ImageDetail& detail, const std::string& fullpath);
	private:
		/**
		*	��ȡ���ش�С
		*/
		static int getImageUnitSize(ImageDataFormat dataFormat);
		/**
		*	��ȡpng��ɫ����
		*/
		static int getPNGColorType(ImageDataFormat dataFormat);
		/**
		*	��ȡJPEG��ɫ����
		*/
		static int getJPEGColorType(ImageDataFormat dataFormat);
	};
}