#include "ImageTarga.h"
#include "ext-config.h"

using namespace render;

ImageTarga::ImageTarga()
{
}

ImageTarga::~ImageTarga()
{

}

void ImageTarga::load(const std::string& filename)
{
	const std::string& fullpath = G_FILEPATH->getFilePath(filename);
	if (fullpath.empty())
	{
		return;
	}

	tga_image image;
	int result = tga_read(&image, fullpath.c_str());
	if (TGA_NOERR != result)
	{
		PRINT("READ TGA Error id : %d", result);
		return;
	}

	// Make sure the image is left to right
	if (tga_is_right_to_left(&image))
		tga_flip_horiz(&image);

	// Make sure the image is bottom to top
	if (tga_is_top_to_bottom(&image))
		tga_flip_vert(&image);

	// Make the image BGR 24
	tga_convert_depth(&image, 24);

	int sDepth = image.pixel_depth / 8;
	int nSize = sDepth * image.width * image.height * sizeof(char);
	uint8_t * val = (uint8_t*)malloc(nSize);
	memcpy(val, image.image_data, nSize);

	this->setPixels(val, image.width, image.height, sDepth);
	this->setTextureInfo(sDepth);

	tga_free_buffers(&image);

	free(val);
}

void ImageTarga::setTextureInfo(int pixel_depth)
{
	

	switch (pixel_depth)
	{
	case 3:     // Most likely case
		this->setFormat(PixelFormat::BGR_EXT);
		this->setInternalFormat(TextureParameter::THREE);
		break;
	case 4:
		this->setFormat(PixelFormat::BGRA_EXT);
		this->setInternalFormat(TextureParameter::FOUR);
		break;
	case 1:
		this->setFormat(PixelFormat::LUMINANCE);
		this->setInternalFormat(TextureParameter::ONE);
		break;
	};
}

