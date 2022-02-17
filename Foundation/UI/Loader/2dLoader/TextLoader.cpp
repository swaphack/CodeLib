#include "TextLoader.h"
#include "Display/UIProxy.h"

using namespace ui;


#define PROPERTY_TEXT		"text"
#define PROPERTY_FONTPATH	"fontPath"
#define PROPERTY_FONTSIZE	"fontSize"
#define PROPERTY_TEXTCOLOR	"textColor"
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
	phy::Color3B color;
	std::string fontpath;
	std::string text;
	float fontSize = 0;
	int horizontal = 1;
	int vertical = 1;
	uint8_t opacity = 255;
	render::BlendParam blend;
	math::Size size;

	LOAD_WIDGET_ATTRIBUTE(PROPERTY_TEXTCOLOR, setTextColor, color);
	//LOAD_WIDGET_ATTRIBUTE(PROPERTY_BLEND, setBlend, blend);

	LOAD_WIDGET_STRING_ATTRIBUTE(PROPERTY_FONTPATH, setFontPath, fontpath);
	LOAD_WIDGET_ATTRIBUTE(PROPERTY_FONTSIZE, setFontSize, fontSize);
	LOAD_WIDGET_STRING_ATTRIBUTE(PROPERTY_TEXT, setString, text);

	LOAD_WIDGET_CAST_ATTRIBUTE(PROPERTY_HORIZONTAL, setTextHorizontalAlignment, horizontal, sys::HorizontalAlignment);
	LOAD_WIDGET_CAST_ATTRIBUTE(PROPERTY_VERTICAL, setTextVerticalAlignment, vertical, sys::VerticalAlignment);
	LOAD_WIDGET_ATTRIBUTE(PROPERTY_DIMENSIONS, setTextDimensions, size);

	if (fontpath.empty())
	{
		getCastWidget()->setFontPath(getFontPath());
	}

	WidgetLoader::parseAttributes();
}

void TextLoader::saveAttributes()
{
	WidgetLoader::saveAttributes();

	SAVE_WIDGET_ATTRIBUTE(PROPERTY_TEXTCOLOR, getTextColor);
	//SAVE_WIDGET_ATTRIBUTE(PROPERTY_BLEND, getBlend);

	SAVE_WIDGET_ATTRIBUTE(PROPERTY_FONTPATH, getFontPath);
	SAVE_WIDGET_ATTRIBUTE(PROPERTY_FONTSIZE, getFontSize);
	SAVE_WIDGET_ATTRIBUTE(PROPERTY_TEXT, getString);

	SAVE_WIDGET_CAST_ATTRIBUTE(PROPERTY_HORIZONTAL, getTextHorizontalAlignment, int);
	SAVE_WIDGET_CAST_ATTRIBUTE(PROPERTY_VERTICAL, getTextVerticalAlignment, int);
	SAVE_WIDGET_ATTRIBUTE(PROPERTY_DIMENSIONS, getTextDimensions);
}
