#include "Scale9ImageLoader.h"

#define PROPERTY_SCALE9_MARGIN	"scale9Margin"
#define PROPERTY_COLOR			"color"
#define PROPERTY_BLEND			"blend"
#define PROPERTY_PATH			"filepath"

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
	render::BlendParam blend;

	LOAD_WIDGET_ATTRIBUTE(PROPERTY_SCALE9_MARGIN, setMargin, margin);
	LOAD_WIDGET_ATTRIBUTE(PROPERTY_COLOR, setImageColor, color);
	LOAD_WIDGET_ATTRIBUTE(PROPERTY_BLEND, setImageBlend, blend);
	LOAD_WIDGET_STRING_ATTRIBUTE(PROPERTY_PATH, setImagePath, filepath);

	WidgetLoader::parseAttributes();
}

void ui::Scale9ImageLoader::saveAttributes()
{
	SAVE_WIDGET_ATTRIBUTE(PROPERTY_SCALE9_MARGIN, getMargin);
	SAVE_WIDGET_ATTRIBUTE(PROPERTY_COLOR, getImageColor);
	SAVE_WIDGET_ATTRIBUTE(PROPERTY_BLEND, getImageBlend);
	SAVE_WIDGET_ATTRIBUTE(PROPERTY_PATH, getImagePath);

	WidgetLoader::saveAttributes();
}
