#include "Scale9ImageLoader.h"

#define PROPERTY_SCALE9_MARGIN		"scale9Margin"
#define PROPERTY_COLOR		"color"
#define PROPERTY_PATH		"filepath"

ui::Scale9ImageLoader::Scale9ImageLoader()
{
}

ui::Scale9ImageLoader::~Scale9ImageLoader()
{
}

void ui::Scale9ImageLoader::parseAttributes()
{
	sys::CSSMargin margin;
	std::string filepath;
	phy::Color4B color;

	LOAD_WIDGET_ATTRIBUTE(PROPERTY_SCALE9_MARGIN, setMargin, margin);
	//LOAD_WIDGET_ATTRIBUTE(PROPERTY_COLOR, setColor, color);
	//LOAD_WIDGET_ATTRIBUTE(PROPERTY_BLEND, setBlend, blend);
	LOAD_WIDGET_STRING_ATTRIBUTE(PROPERTY_PATH, setImagePath, filepath);

	WidgetLoader::parseAttributes();
}

void ui::Scale9ImageLoader::saveAttributes()
{
	SAVE_WIDGET_ATTRIBUTE(PROPERTY_SCALE9_MARGIN, getMargin);
	//SAVE_WIDGET_ATTRIBUTE(PROPERTY_COLOR, getColor);
	//SAVE_WIDGET_ATTRIBUTE(PROPERTY_BLEND, getBlend);
	SAVE_WIDGET_ATTRIBUTE(PROPERTY_PATH, getImagePath);

	WidgetLoader::saveAttributes();
}
