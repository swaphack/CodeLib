#include "ImageLoader.h"

using namespace ui;

#define PROPERTY_COLOR		"color"
#define PROPERTY_BLEND		"blend"
#define PROPERTY_PATH		"filepath"
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
	phy::Color4B color;
	std::string filepath;
	bool bFlipX = false;
	bool bFlipY = false;
	uint8_t opacity = 255;
	render::BlendParam blend;

	LOAD_WIDGET_ATTRIBUTE(PROPERTY_COLOR, setColor, color);
	//LOAD_WIDGET_ATTRIBUTE(PROPERTY_BLEND, setBlend, blend);
	LOAD_WIDGET_STRING_ATTRIBUTE(PROPERTY_PATH, setImagePath, filepath);
	LOAD_WIDGET_ATTRIBUTE(PROPERTY_FLIPX, setFlipX, bFlipX);
	LOAD_WIDGET_ATTRIBUTE(PROPERTY_FLIPY, setFlipY, bFlipY);

	WidgetLoader::parseAttributes();
}

void ImageLoader::saveAttributes()
{
	WidgetLoader::saveAttributes();

	SAVE_WIDGET_ATTRIBUTE(PROPERTY_COLOR, getColor);
	//SAVE_WIDGET_ATTRIBUTE(PROPERTY_BLEND, getBlend);
	SAVE_WIDGET_ATTRIBUTE(PROPERTY_PATH, getImagePath);
	SAVE_WIDGET_ATTRIBUTE(PROPERTY_FLIPX, isFlipX);
	SAVE_WIDGET_ATTRIBUTE(PROPERTY_FLIPY, isFlipY);
}
