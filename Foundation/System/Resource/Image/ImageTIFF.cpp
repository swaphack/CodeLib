#include "ImageTIFF.h"

#include "third_party.h"

sys::ImageTIFF::ImageTIFF()
{

}

sys::ImageTIFF::~ImageTIFF()
{

}

bool sys::ImageTIFF::load(const std::string& filename)
{
	if (filename.empty())
	{
		return false;
	}

	TIFF* tif = TIFFOpen(filename.c_str(), "r");
	if (tif == nullptr)
	{
		return false;
	}

	uint32 w, h;
	size_t npixels;
	uint32* raster;

	TIFFGetField(tif, TIFFTAG_IMAGEWIDTH, &w);
	TIFFGetField(tif, TIFFTAG_IMAGELENGTH, &h);
	npixels = w * h;
	raster = (uint32*)_TIFFmalloc(npixels * sizeof(uint32));
	if (raster != NULL) {
		if (TIFFReadRGBAImage(tif, w, h, raster, 0)) {
			this->setDataFormat(ImageDataFormat::RGBA);
			this->setPixels((uint8_t*)raster, w, h, 4);
		}
		_TIFFfree(raster);
	}
	TIFFClose(tif);

	return true;
}

