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

	if (strFormat == IMAGE_FORMAT_PNG) this->format = ImageFormat::PNG;
	else if (strFormat == IMAGE_FORMAT_JPG) this->format = ImageFormat::JPEG;
	else if (strFormat == IMAGE_FORMAT_TGA) this->format = ImageFormat::TARGA;
	else if (strFormat == IMAGE_FORMAT_BMP) this->format = ImageFormat::BMP;
	else if (strFormat == IMAGE_FORMAT_TIF) this->format = ImageFormat::TIFF;
	else this->format = ImageFormat::NONE;
}
