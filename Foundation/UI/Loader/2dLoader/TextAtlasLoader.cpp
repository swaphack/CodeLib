#include "TextAtlasLoader.h"
#include "Display/UIProxy.h"

using namespace ui;


#define PROPERTY_TEXT		"text"
#define PROPERTY_IMAGEPATH	"imagePath"
#define PROPERTY_TEXTCOLOR	"textColor"
#define PROPERTY_BLEND		"blend"
#define PROPERTY_HORIZONTAL	"horizontal"
#define PROPERTY_VERTICAL	"vertical"
#define PROPERTY_DIMENSIONS "dimensions"


TextAtlasLoader::TextAtlasLoader()
{

}

TextAtlasLoader::~TextAtlasLoader()
{

}

void TextAtlasLoader::parseAttributes()
{
	phy::Color3B color;
	std::string imagePath;
	std::string text;
	float fontSize = 0;
	int horizontal = 1;
	int vertical = 1;
	uint8_t opacity = 255;
	render::BlendParam blend;
	math::Size size;

	LOAD_WIDGET_ATTRIBUTE(PROPERTY_TEXTCOLOR, setTextColor, color);
	//LOAD_WIDGET_ATTRIBUTE(PROPERTY_BLEND, setBlend, blend);

	LOAD_WIDGET_STRING_ATTRIBUTE(PROPERTY_IMAGEPATH, setImagePath, imagePath);
	LOAD_WIDGET_STRING_ATTRIBUTE(PROPERTY_TEXT, setString, text);

	LOAD_WIDGET_CAST_ATTRIBUTE(PROPERTY_HORIZONTAL, setTextHorizontalAlignment, horizontal, sys::HorizontalAlignment);
	LOAD_WIDGET_CAST_ATTRIBUTE(PROPERTY_VERTICAL, setTextVerticalAlignment, vertical, sys::VerticalAlignment);
	LOAD_WIDGET_ATTRIBUTE(PROPERTY_DIMENSIONS, setDimensions, size);

	if (imagePath.empty())
	{
		getCastWidget()->setImagePath(getFontImagePath());
	}

	WidgetLoader::parseAttributes();
}

void TextAtlasLoader::saveAttributes()
{
	WidgetLoader::saveAttributes();

	SAVE_WIDGET_ATTRIBUTE(PROPERTY_TEXTCOLOR, getTextColor);
	//SAVE_WIDGET_ATTRIBUTE(PROPERTY_BLEND, getBlend);

	SAVE_WIDGET_ATTRIBUTE(PROPERTY_IMAGEPATH, getImagePath);
	SAVE_WIDGET_ATTRIBUTE(PROPERTY_TEXT, getString);

	SAVE_WIDGET_CAST_ATTRIBUTE(PROPERTY_HORIZONTAL, getTextHorizontalAlignment, int);
	SAVE_WIDGET_CAST_ATTRIBUTE(PROPERTY_VERTICAL, getTextVerticalAlignment, int);
	SAVE_WIDGET_ATTRIBUTE(PROPERTY_DIMENSIONS, getDimensions);
}
