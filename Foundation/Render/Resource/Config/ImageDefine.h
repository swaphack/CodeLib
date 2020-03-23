#pragma once

#include <string>
#include <algorithm>

namespace render
{
	//	ͼƬ��Դ��ʽ
	enum ImageFormat
	{
		EIF_NONE = 0,
		EIF_PNG,	// png
		EIF_JPEG,	// jpg
		EIF_TARGA,	// tga
	};

	// ͼƬ���������ṹ
	struct ImageDefine
	{
		// ͼƬ·��
		std::string filepath;

		// ͼƬ��ʽ
		ImageFormat format;

		ImageDefine(const ImageDefine& value)
			:filepath(value.filepath), format(value.format)
		{
		}

		ImageDefine(const std::string& _filename = "", ImageFormat _format = EIF_NONE)
			:filepath(_filename)
		{
			this->format = _format;
			if (filepath.empty())
			{
				return;
			}
			if (format != EIF_NONE)
			{
				return;
			}

			int idx = filepath.find_last_of('.') + 1;
			std::string strFormat = filepath.substr(idx, filepath.size() - idx);
			std::transform(strFormat.begin(), strFormat.end(), strFormat.begin(), ::tolower);

			if (strFormat == "png") this->format = EIF_PNG;
			else if (strFormat == "jpg") this->format = EIF_JPEG;
			else if (strFormat == "tga") this->format = EIF_TARGA;
			else this->format = EIF_NONE;
		}
	};
}