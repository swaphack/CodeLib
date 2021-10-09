#include "ImageHelper.h"
#include "../extensions.h"
#include "IO/Directory.h"

bool sys::ImageHelper::saveToPNG(const ImageDetail& detail, const std::string& fullpath)
{
	int unitSize = getImageUnitSize(detail.getDataFormat());
	if (unitSize == -1)
	{
		return false;
	}

	int colorType = getPNGColorType(detail.getDataFormat());
	if (colorType == -1)
	{
		return false;
	}

	png_structp png_ptr;
	png_infop info_ptr;
	FILE* fp = NULL;

	/* Open image file */
	int result = fopen_s(&fp, fullpath.c_str(), "wb");
	if (result != 0)
	{
		return false;
	}

	/* Create a png read struct */
	png_ptr = png_create_write_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
	if (!png_ptr)
	{
		fclose(fp);
		return false;
	}
	/* Create a png info struct */
	info_ptr = png_create_info_struct(png_ptr);
	if (!info_ptr)
	{
		fclose(fp);
		png_destroy_write_struct(&png_ptr, NULL);
		return false;
	}
	/* Initialize the setjmp for returning properly after a libpng error occured */
	if (setjmp(png_jmpbuf(png_ptr)))
	{
		fclose(fp);
		png_free_data(png_ptr, info_ptr, PNG_FREE_ALL, -1);
		png_destroy_write_struct(&png_ptr, nullptr);
		return false;
	}
	/* Setup libpng for using standard C fread() function with our FILE pointer */
	png_init_io(png_ptr, fp);
	png_set_IHDR(png_ptr, info_ptr, detail.getWidth(), detail.getHeight(),
		8, colorType, PNG_INTERLACE_NONE,
		PNG_COMPRESSION_TYPE_BASE, PNG_FILTER_TYPE_BASE);

	png_text title_text;
	title_text.compression = PNG_TEXT_COMPRESSION_NONE;
	title_text.key = "Title";
	title_text.text = (char*)fullpath.c_str();
	png_set_text(png_ptr, info_ptr, &title_text, 1);

	png_write_info(png_ptr, info_ptr);

	int nRowSize = unitSize * detail.getWidth() * sizeof(png_byte);
	png_bytep row = (png_bytep)malloc(nRowSize);

	int x, y;
	for (y = 0; y < detail.getHeight(); y++) {
		memset(row, 0, nRowSize);
		for (x = 0; x < detail.getWidth(); x++) {
			memcpy(row + x * unitSize, detail.getPtr(unitSize * (y * detail.getWidth() + x)), unitSize * sizeof(png_byte));
		}
		png_write_row(png_ptr, row);
	}

	// End write
	png_write_end(png_ptr, NULL);

	fclose(fp);
	png_free_data(png_ptr, info_ptr, PNG_FREE_ALL, -1);
	png_destroy_write_struct(&png_ptr, nullptr);

	return true;
}

bool sys::ImageHelper::saveToJPEG(const ImageDetail& detail, const std::string& fullpath)
{
	int unitSize = getImageUnitSize(detail.getDataFormat());
	if (unitSize == -1)
	{
		return false;
	}

	int colorType = getJPEGColorType(detail.getDataFormat());
	if (colorType == -1)
	{
		return false;
	}

	Directory::deleteFile(fullpath);

	int quality = 255;
	struct jpeg_compress_struct cinfo;
	struct jpeg_error_mgr jerr;

	FILE* outfile;		/* target file */
	JSAMPROW row_pointer[1];	/* pointer to JSAMPLE row[s] */
	int row_stride;		/* physical row width in image buffer */

	cinfo.err = jpeg_std_error(&jerr);
	/* Now we can initialize the JPEG compression object. */
	jpeg_create_compress(&cinfo);

	if ((outfile = fopen(fullpath.c_str(), "wb")) == NULL) {
		return false;
	}
	jpeg_stdio_dest(&cinfo, outfile);

	cinfo.image_width = detail.getWidth(); 	/* image width and height, in pixels */
	cinfo.image_height = detail.getHeight();
	cinfo.input_components = 3;		/* # of color components per pixel */
	cinfo.in_color_space = JCS_RGB; 	/* colorspace of input image */

	jpeg_set_defaults(&cinfo);
	jpeg_set_quality(&cinfo, quality, TRUE /* limit to baseline-JPEG values */);
	jpeg_start_compress(&cinfo, TRUE);

	row_stride = detail.getWidth() * 3;	/* JSAMPLEs per row in image_buffer */

	while (cinfo.next_scanline < cinfo.image_height) {
		row_pointer[0] = detail.getPtr(cinfo.next_scanline * row_stride);
		(void)jpeg_write_scanlines(&cinfo, row_pointer, 1);
	}

	jpeg_finish_compress(&cinfo);
	fclose(outfile);
	jpeg_destroy_compress(&cinfo);

	return true;
}

int sys::ImageHelper::getImageUnitSize(ImageDataFormat dataFormat)
{
	switch (dataFormat)
	{
	case sys::ImageDataFormat::RED:
		return 1;
		break;
	case sys::ImageDataFormat::RG:
		return 2;
		break;
	case sys::ImageDataFormat::RGB:
		return 3;
		break;
	case sys::ImageDataFormat::RGBA:
		return 4;
		break;
	case sys::ImageDataFormat::BGR:
		return 3;
		break;
	case sys::ImageDataFormat::BGRA:
		return 4;
		break;
	default:
		break;
	}

	return -1;
}

int sys::ImageHelper::getPNGColorType(ImageDataFormat dataFormat)
{	
	switch (dataFormat)
	{
	case sys::ImageDataFormat::RED:
		return -1;
		break;
	case sys::ImageDataFormat::RG:
		return -1;
		break;
	case sys::ImageDataFormat::RGB:
		return PNG_COLOR_TYPE_RGB;
		break;
	case sys::ImageDataFormat::RGBA:
		return PNG_COLOR_TYPE_RGB_ALPHA;
		break;
	case sys::ImageDataFormat::BGR:
		return -1;
		break;
	case sys::ImageDataFormat::BGRA:
		return -1;
		break;
	default:
		break;
	}

	return -1;
}

int sys::ImageHelper::getJPEGColorType(ImageDataFormat dataFormat)
{
	switch (dataFormat)
	{
	case sys::ImageDataFormat::RED:
		return -1;
		break;
	case sys::ImageDataFormat::RG:
		return -1;
		break;
	case sys::ImageDataFormat::RGB:
		return JCS_RGB;
		break;
	case sys::ImageDataFormat::RGBA:
		return -1;
		break;
	case sys::ImageDataFormat::BGR:
		return -1;
		break;
	case sys::ImageDataFormat::BGRA:
		return -1;
		break;
	default:
		break;
	}

	return -1;
}
