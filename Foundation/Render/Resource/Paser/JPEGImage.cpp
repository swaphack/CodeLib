#include "JPEGImage.h"

using namespace render;


JPEGImage::JPEGImage()
{

}

JPEGImage::~JPEGImage()
{

}

void JPEGImage::load(const char* filename)
{
	struct jpeg_decompress_struct jds;
	struct jpeg_error_mgr jem;
	FILE* fptr;

	fptr = fopen(filename, "rb");
	if (fptr == nullptr)
	{
		return;
	}

	jds.err = jpeg_std_error(&jem);
	jpeg_create_decompress(&jds);
	jpeg_stdio_src(&jds, fptr);
	jpeg_read_header(&jds, true);
	jpeg_start_decompress(&jds);

	
	int internalFormat = jds.output_components;
	this->setWidth(jds.output_width);
	this->setHeight(jds.output_height);
	this->setInternalFormat(internalFormat);
	this->setFormat(GL_RGB);

	uint lineSize = jds.output_width * internalFormat;
	uint totoalSize = this->getWidth()* this->getHeight() * internalFormat;

	uchar* buffer = new uchar[totoalSize];
	memset(buffer, 0, totoalSize);

	JSAMPARRAY tmp = (*jds.mem->alloc_sarray)((j_common_ptr)&jds, JPOOL_IMAGE, lineSize, 1);

	int start = 0;

	while (jds.output_scanline < jds.output_height)
	{
		jpeg_read_scanlines(&jds, tmp, 1);
		LOG("line number %d\n", jds.output_scanline);
		start = lineSize * (jds.output_height - jds.output_scanline);

		memcpy(buffer + start, tmp[0], lineSize);
	}

	jpeg_finish_decompress(&jds);
	jpeg_destroy_decompress(&jds);
	fclose(fptr);

	this->setPixels(buffer);
}
