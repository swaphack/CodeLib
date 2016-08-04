#include "ImageLoader.h"

using namespace ui;

#define PROPERTY_COLOR		"Color"
#define PROPERTY_PATH		"Path"
#define PROPERTY_FLIPX		"FlipX"
#define PROPERTY_FLIPY		"FlipY"


ImageLoader::ImageLoader()
{

}

ImageLoader::~ImageLoader()
{

}

void ImageLoader::parseAttribute()
{
	NodeLoader::parseAttribute();

	sys::Color4B color;
	std::string str;
	bool boolVal;

	LOAD_ATTRIBUTE(PROPERTY_COLOR, setColor, color);
	LOAD_STRING_ATTRIBUTE(PROPERTY_PATH, setImagePath, str);
	LOAD_ATTRIBUTE(PROPERTY_FLIPX, setFlipX, boolVal);
	LOAD_ATTRIBUTE(PROPERTY_FLIPY, setFlipY, boolVal);
}

void ImageLoader::saveAttributes()
{
	NodeLoader::saveAttributes();

	SAVE_ATTRIBUTE(PROPERTY_COLOR, getColor);
	SAVE_ATTRIBUTE(PROPERTY_COLOR, getImagePath);
	SAVE_ATTRIBUTE(PROPERTY_COLOR, isFlipX);
	SAVE_ATTRIBUTE(PROPERTY_COLOR, isFlipY);
}
