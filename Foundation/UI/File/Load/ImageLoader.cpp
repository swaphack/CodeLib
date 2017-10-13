#include "ImageLoader.h"

using namespace ui;

#define PROPERTY_COLOR		"color"
#define PROPERTY_OPACITY	"opacity"
#define PROPERTY_BLEND		"blend"
#define PROPERTY_PATH		"path"
#define PROPERTY_FLIPX		"flipX"
#define PROPERTY_FLIPY		"flipY"


ImageLoader::ImageLoader()
{

}

ImageLoader::~ImageLoader()
{

}

void ImageLoader::parseAttributes()
{
	sys::Color4B color;
	std::string str;
	bool boolVal;
	uchar ucVal;
	BlendParam blend;

	LOAD_WDIGET_ATTRIBUTE(PROPERTY_COLOR, setColor, color);
	LOAD_WDIGET_ATTRIBUTE(PROPERTY_OPACITY, setOpacity, ucVal);
	LOAD_WDIGET_ATTRIBUTE(PROPERTY_BLEND, setBlend, blend);
	LOAD_WDIGET_STRING_ATTRIBUTE(PROPERTY_PATH, setImagePath, str);
	LOAD_WDIGET_ATTRIBUTE(PROPERTY_FLIPX, setFlipX, boolVal);
	LOAD_WDIGET_ATTRIBUTE(PROPERTY_FLIPY, setFlipY, boolVal);

	NodeLoader::parseAttributes();
}

void ImageLoader::saveAttributes()
{
	NodeLoader::saveAttributes();

	SAVE_WDIGET_ATTRIBUTE(PROPERTY_COLOR, getColor);
	SAVE_WDIGET_ATTRIBUTE(PROPERTY_OPACITY, getOpacity);
	SAVE_WDIGET_ATTRIBUTE(PROPERTY_BLEND, getBlend);
	SAVE_WDIGET_ATTRIBUTE(PROPERTY_PATH, getImagePath);
	SAVE_WDIGET_ATTRIBUTE(PROPERTY_FLIPX, isFlipX);
	SAVE_WDIGET_ATTRIBUTE(PROPERTY_FLIPY, isFlipY);
}
