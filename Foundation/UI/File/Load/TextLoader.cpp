#include "TextLoader.h"

using namespace ui;


#define PROPERTY_TEXT		"text"
#define PROPERTY_PATH		"path"
#define PROPERTY_FONTSIZE	"fontsize"
#define PROPERTY_COLOR		"color"
#define PROPERTY_BLEND		"blend"
#define PROPERTY_HORIZONTAL	"horizontal"
#define PROPERTY_VERTICAL	"vertical"
#define PROPERTY_DIMENSIONS "dimensions"


TextLoader::TextLoader()
{

}

TextLoader::~TextLoader()
{

}

void TextLoader::parseAttributes()
{
	sys::Color3B color;
	std::string fontpath;
	std::string text;
	float fontSize = 0;
	int horizontal = 1;
	int vertical = 1;
	uint8_t opacity = 255;
	BlendParam blend;
	math::Size size;

	LOAD_WIDGET_ATTRIBUTE(PROPERTY_COLOR, setTextColor, color);
	LOAD_WIDGET_ATTRIBUTE(PROPERTY_BLEND, setBlend, blend);

	LOAD_WIDGET_STRING_ATTRIBUTE(PROPERTY_PATH, setFontPath, fontpath);
	LOAD_WIDGET_ATTRIBUTE(PROPERTY_FONTSIZE, setFontSize, fontSize);
	LOAD_WIDGET_STRING_ATTRIBUTE(PROPERTY_TEXT, setString, text);

	LOAD_WIDGET_CAST_ATTRIBUTE(PROPERTY_HORIZONTAL, setHorizontalAlignment, horizontal, sys::HorizontalAlignment);
	LOAD_WIDGET_CAST_ATTRIBUTE(PROPERTY_VERTICAL, setVerticalAlignment, vertical, sys::VerticalAlignment);
	LOAD_WIDGET_ATTRIBUTE(PROPERTY_DIMENSIONS, setDimensions, size);

	WidgetLoader::parseAttributes();
}

void TextLoader::saveAttributes()
{
	WidgetLoader::saveAttributes();

	SAVE_WIDGET_ATTRIBUTE(PROPERTY_COLOR, getColor);
	SAVE_WIDGET_ATTRIBUTE(PROPERTY_BLEND, getBlend);

	SAVE_WIDGET_ATTRIBUTE(PROPERTY_PATH, getFontPath);
	SAVE_WIDGET_ATTRIBUTE(PROPERTY_FONTSIZE, getFontSize);
	SAVE_WIDGET_ATTRIBUTE(PROPERTY_TEXT, getString);

	SAVE_WIDGET_CAST_ATTRIBUTE(PROPERTY_HORIZONTAL, getHorizontalAlignment, int);
	SAVE_WIDGET_CAST_ATTRIBUTE(PROPERTY_VERTICAL, getVerticalAlignment, int);
	SAVE_WIDGET_ATTRIBUTE(PROPERTY_DIMENSIONS, getDimensions);
}
