#include "ImageDefine.h"

sys::ImageDefine::ImageDefine(const std::string& _filename /*= ""*/, ImageFormat _format /*= ImageFormat::NONE*/)
{
	this->format = _format;
	this->setFilePath(_filename);
}

sys::ImageDefine::ImageDefine(const ImageDefine& value) :filepath(value.filepath), format(value.format)
{

}

void sys::ImageDefine::setFilePath(const std::string& _filename)
{
	filepath = _filename;

	if (filepath.empty())
	{
		return;
	}
	if (format != ImageFormat::NONE)
	{
		return;
	}

	int idx = filepath.find_last_of('.') + 1;
	std::string strFormat = filepath.substr(idx, filepath.size() - idx);
	std::transform(strFormat.begin(), strFormat.end(), strFormat.begin(), ::tolower);

	if (strFormat == "png") this->format = ImageFormat::PNG;
	else if (strFormat == "jpg") this->format = ImageFormat::JPEG;
	else if (strFormat == "tga") this->format = ImageFormat::TARGA;
	else if (strFormat == "bmp") this->format = ImageFormat::BMP;
	else this->format = ImageFormat::NONE;
}
