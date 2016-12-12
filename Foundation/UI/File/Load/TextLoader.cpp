#include "TextLoader.h"

using namespace ui;


#define PROPERTY_TEXT		"Text"
#define PROPERTY_PATH		"Path"
#define PROPERTY_FONTSIZE	"FontSize"
#define PROPERTY_COLOR		"Color"
#define PROPERTY_OPACITY	"Opacity"
#define PROPERTY_BLEND		"Blend"
#define PROPERTY_HORIZONTAL	"Horizontal"
#define PROPERTY_VERTICAL	"Vertical"
#define PROPERTY_DIMENSIONS "Dimensions"


TextLoader::TextLoader()
{

}

TextLoader::~TextLoader()
{

}

void TextLoader::parseAttributes()
{
	NodeLoader::parseAttributes();

	sys::Color4B color;
	std::string str;
	float floatVal;
	int intVal;
	uchar ucVal;
	BlendParam blend;
	sys::Size size;

	LOAD_ATTRIBUTE(PROPERTY_COLOR, setColor, color);
	LOAD_ATTRIBUTE(PROPERTY_OPACITY, setOpacity, ucVal);
	LOAD_ATTRIBUTE(PROPERTY_BLEND, setBlend, blend);

	LOAD_STRING_ATTRIBUTE(PROPERTY_PATH, setFontPath, str);
	LOAD_ATTRIBUTE(PROPERTY_FONTSIZE, setFontSize, floatVal);
	LOAD_CAST_ATTRIBUTE(PROPERTY_HORIZONTAL, setHorizontalAlignment, intVal, render::HorizontalAlignment);
	LOAD_CAST_ATTRIBUTE(PROPERTY_VERTICAL, setVerticalAlignment, intVal, render::VerticalAlignment);

	LOAD_STRING_ATTRIBUTE(PROPERTY_TEXT, setString, str);
	LOAD_ATTRIBUTE(PROPERTY_DIMENSIONS, setDimensions, size);
}

void TextLoader::saveAttributes()
{
	NodeLoader::saveAttributes();

	SAVE_ATTRIBUTE(PROPERTY_COLOR, getColor);
	SAVE_ATTRIBUTE(PROPERTY_OPACITY, getOpacity);
	SAVE_ATTRIBUTE(PROPERTY_BLEND, getBlend);

	SAVE_ATTRIBUTE(PROPERTY_PATH, getFontPath);
	SAVE_ATTRIBUTE(PROPERTY_FONTSIZE, getFontSize);
	SAVE_CAST_ATTRIBUTE(PROPERTY_HORIZONTAL, getHorizontalAlignment, int);
	SAVE_CAST_ATTRIBUTE(PROPERTY_VERTICAL, getVerticalAlignment, int);

	SAVE_ATTRIBUTE(PROPERTY_TEXT, getString);
	SAVE_ATTRIBUTE(PROPERTY_DIMENSIONS, getDimensions);
}
