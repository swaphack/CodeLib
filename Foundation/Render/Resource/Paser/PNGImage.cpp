#include "PNGImage.h"

#include "macros.h"
#include <stdlib.h>
#include <stdio.h>

using namespace render;

PNGImage::PNGImage()
{

}

PNGImage::~PNGImage()
{

}
void PNGImage::setTextureInfo(int color_type)
{
	switch (color_type)
	{
	case PNG_COLOR_TYPE_GRAY:
		setFormat(GL_LUMINANCE);
		setInternalFormat(1);
		break;

	case PNG_COLOR_TYPE_GRAY_ALPHA:
		setFormat(GL_LUMINANCE_ALPHA);
		setInternalFormat(2);
		break;

	case PNG_COLOR_TYPE_RGB:
		setFormat(GL_RGB);
		setInternalFormat(3);
		break;

	case PNG_COLOR_TYPE_RGB_ALPHA:
		setFormat(GL_RGBA);
		setInternalFormat(4);
		break;

	default:
		/* Badness */
		break;
	}
}

void PNGImage::load(const char* filename)
{
	//gl_texture_t *texinfo;
	png_byte magic[8];
	png_structp png_ptr;
	png_infop info_ptr;
	int bit_depth, color_type;
	FILE *fp = NULL;
	png_bytep *row_pointers = NULL;
	png_uint_32 w, h;
	GLubyte* texels;
	png_uint_32 rowbytes;

	const char* fullpaht = G_FILEPATH->getFilePath(filename);

	/* Open image file */
	fp = fopen(filename, "rb");
	if (!fp)
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
	this->setWidth(w);
	this->setHeight(h);
	/* Get image format and components per pixel */
	setTextureInfo(color_type);

	rowbytes = png_get_rowbytes(png_ptr, info_ptr);

	/* We can now allocate memory for storing pixel data */
	texels = (GLubyte *)malloc(sizeof (GLubyte)* h * rowbytes);
	/* Setup a pointer array. Each one points at the begening of a row. */
	row_pointers = (png_bytep *)malloc(sizeof (png_bytep)* h);

	for (int i = 0; i < h; i++)
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
	this->setPixels(texels);
}




