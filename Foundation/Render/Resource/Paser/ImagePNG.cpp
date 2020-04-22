#include "ImagePNG.h"
#include "ext-config.h"
#include "system.h"
#include <cstdlib>
#include <cstdio>

using namespace render;

ImagePNG::ImagePNG()
{

}

ImagePNG::~ImagePNG()
{

}
int ImagePNG::setTextureInfo(int color_type)
{
	switch (color_type)
	{
	case PNG_COLOR_TYPE_GRAY:
		setFormat(PixelFormat::LUMINANCE);
		this->setInternalFormat(TextureParameter::ONE);
		return 1;

	case PNG_COLOR_TYPE_PALETTE:
		setFormat(PixelFormat::LUMINANCE_ALPHA);
		this->setInternalFormat(TextureParameter::TWO);
		return 2;

	case PNG_COLOR_TYPE_RGB:
		setFormat(PixelFormat::RGB);
		this->setInternalFormat(TextureParameter::THREE);
		return 3;

	case PNG_COLOR_TYPE_RGB_ALPHA:
		setFormat(PixelFormat::RGBA);
		this->setInternalFormat(TextureParameter::FOUR);
		return 4;

	default:
		/* Badness */
		break;
	}
	return 0;
}

void ImagePNG::load(const std::string& filename)
{
	//gl_texture_t *texinfo;
	png_byte magic[8];
	png_structp png_ptr;
	png_infop info_ptr;
	int bit_depth, color_type;
	FILE *fp = NULL;
	png_bytep *row_pointers = NULL;
	png_uint_32 w, h;
	png_byte* texels;
	png_uint_32 rowbytes;

	const std::string& fullpath = G_FILEPATH->getFilePath(filename);
	if (fullpath.empty())
	{
		return;
	}

	/* Open image file */
	int result = fopen_s(&fp, fullpath.c_str(), "rb");
	if (result != 0)
	{
		return;
	}
	/* Read magic number */
	fread(magic, 1, sizeof (magic), fp);
	/* Check for valid magic number */
	if (!png_check_sig(magic, sizeof (magic)))
	{
		fclose(fp);
		return;
	}
	/* Create a png read struct */
	png_ptr = png_create_read_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
	if (!png_ptr)
	{
		fclose(fp);
		return;
	}
	/* Create a png info struct */
	info_ptr = png_create_info_struct(png_ptr);
	if (!info_ptr)
	{
		fclose(fp);
		png_destroy_read_struct(&png_ptr, NULL, NULL);
		return;
	}
	/* Initialize the setjmp for returning properly after a libpng error occured */
	if (setjmp(png_jmpbuf(png_ptr)))
	{
		fclose(fp);
		png_destroy_read_struct(&png_ptr, &info_ptr, NULL);
		return;
	}
	/* Setup libpng for using standard C fread() function with our FILE pointer */
	png_init_io(png_ptr, fp);
	/* Tell libpng that we have already read the magic number */
	png_set_sig_bytes(png_ptr, sizeof (magic));
	/* Read png info */
	png_read_info(png_ptr, info_ptr);
	/* Get some usefull information from header */
	bit_depth = png_get_bit_depth(png_ptr, info_ptr);
	color_type = png_get_color_type(png_ptr, info_ptr);
	/* Convert index color images to RGB images */
	if (color_type == PNG_COLOR_TYPE_PALETTE)
		png_set_palette_to_rgb(png_ptr);
	/* Convert 1-2-4 bits grayscale images to 8 bits grayscale. */
	if (color_type == PNG_COLOR_TYPE_GRAY && bit_depth < 8)
		png_set_expand_gray_1_2_4_to_8(png_ptr);
	if (png_get_valid(png_ptr, info_ptr, PNG_INFO_tRNS))
		png_set_tRNS_to_alpha(png_ptr);
	if (bit_depth == 16) png_set_strip_16(png_ptr);
	else if (bit_depth < 8) png_set_packing(png_ptr);
	/* Update info structure to apply transformations */
	png_read_update_info(png_ptr, info_ptr);
	/* Retrieve updated information */
	png_get_IHDR(png_ptr, info_ptr, &w, &h, &bit_depth, &color_type, NULL, NULL, NULL);
	/* Get image format and components per pixel */
	rowbytes = png_get_rowbytes(png_ptr, info_ptr);

	/* We can now allocate memory for storing pixel data */
	texels = (png_byte *)malloc(sizeof (png_byte)* h * rowbytes);
	/* Setup a pointer array. Each one points at the begening of a row. */
	row_pointers = (png_bytep *)malloc(sizeof (png_bytep)* h);

	for (unsigned int i = 0; i < h; i++)
	{
		row_pointers[i] = texels + (h - i - 1) * rowbytes;
	}
	/* Read pixel data using row pointers */
	png_read_image(png_ptr, row_pointers);
	/* Finish decompression and release memory */
	png_read_end(png_ptr, NULL);

	png_destroy_read_struct(&png_ptr, &info_ptr, NULL);
	/* We don't need row pointers anymore */
	free(row_pointers);
	fclose(fp);

	int unitSize = this->setTextureInfo(color_type);
	this->setPixels(texels, w, h, unitSize);

	free(texels);
}




