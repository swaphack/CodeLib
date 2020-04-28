#include "ImageJPEG.h"

using namespace render;


ImageJPEG::ImageJPEG()
{

}

ImageJPEG::~ImageJPEG()
{

}

void ImageJPEG::load(const std::string& filename)
{
	const std::string& fullpath = G_FILEPATH->getFilePath(filename);
	if (fullpath.empty())
	{
		return;
	}

	struct jpeg_decompress_struct jds;
	struct jpeg_error_mgr jem;
	FILE* fptr = 0;

	int result = fopen_s(&fptr, fullpath.c_str(), "rb");
	if (result != 0)
	{
		return;
	}

	jds.err = jpeg_std_error(&jem);
	jpeg_create_decompress(&jds);
	jpeg_stdio_src(&jds, fptr);
	jpeg_read_header(&jds, true);
	jpeg_start_decompress(&jds);
	
	int internalFormat = jds.output_components;
	this->setInternalFormat((TexImageInternalFormat)internalFormat);
	this->setFormat(TexImageDataFormat::RGB);

	uint32_t lineSize = jds.output_width * internalFormat;
	uint32_t totoalSize = jds.output_width * jds.output_height * internalFormat;

	uint8_t* buffer = (uint8_t*)malloc(totoalSize);
	memset(buffer, 0, totoalSize);

	JSAMPARRAY tmp = (*jds.mem->alloc_sarray)((j_common_ptr)&jds, JPOOL_IMAGE, lineSize, 1);

	int start = 0;

	while (jds.output_scanline < jds.output_height)
	{
		jpeg_read_scanlines(&jds, tmp, 1);
		start = lineSize * (jds.output_height - jds.output_scanline);
		memcpy(buffer + start, tmp[0], lineSize);
	}

	jpeg_finish_decompress(&jds);
	jpeg_destroy_decompress(&jds);
	fclose(fptr);

	this->setPixels(buffer, jds.output_width, jds.output_height, internalFormat);

	free(buffer);
}