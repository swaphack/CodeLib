#pragma once

#include <string>

namespace render
{
	//	ͼƬ��Դ��ʽ
	enum ImageFormat
	{
		EIF_NONE = 0,
		EIF_PNG,	// png
		EIF_JPEG,	// jpeg;
	};

	// ͼƬ���������ṹ
	struct ImageDefine
	{
		// ͼƬ·��
		std::string filepath;

		// ͼƬ��ʽ
		ImageFormat format;

		ImageDefine(const char* filename = "", ImageFormat format = EIF_PNG)
			:filepath(filename)
			, format(format)
		{}
	};
}