#include "ImageLoader.h"

using namespace ui;

#define PROPERTY_COLOR		"Color"
#define PROPERTY_OPACITY	"Opacity"
#define PROPERTY_BLEND		"Blend"
#define PROPERTY_PATH		"Path"
#define PROPERTY_FLIPX		"FlipX"
#define PROPERTY_FLIPY		"FlipY"


ImageLoader::ImageLoader()
{

}

ImageLoader::~ImageLoader()
{

}

void ImageLoader::parseAttributes()
{
	NodeLoader::parseAttributes();

	sys::Color4B color;
	std::string str;
	bool boolVal;
	uchar ucVal;
	BlendParam blend;

	LOAD_ATTRIBUTE(PROPERTY_COLOR, setColor, color);
	LOAD_ATTRIBUTE(PROPERTY_OPACITY, setOpacity, ucVal);
	LOAD_ATTRIBUTE(PROPERTY_BLEND, setBlend, blend);
	LOAD_STRING_ATTRIBUTE(PROPERTY_PATH, setImagePath, str);
	LOAD_ATTRIBUTE(PROPERTY_FLIPX, setFlipX, boolVal);
	LOAD_ATTRIBUTE(PROPERTY_FLIPY, setFlipY, boolVal);
}

void ImageLoader::saveAttributes()
{
	NodeLoader::saveAttributes();

	SAVE_ATTRIBUTE(PROPERTY_COLOR, getColor);
	SAVE_ATTRIBUTE(PROPERTY_OPACITY, getOpacity);
	SAVE_ATTRIBUTE(PROPERTY_BLEND, getBlend);
	SAVE_ATTRIBUTE(PROPERTY_COLOR, getImagePath);
	SAVE_ATTRIBUTE(PROPERTY_COLOR, isFlipX);
	SAVE_ATTRIBUTE(PROPERTY_COLOR, isFlipY);
}