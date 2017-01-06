#include "TextLoader.h"

using namespace ui;


#define PROPERTY_TEXT		"text"
#define PROPERTY_PATH		"path"
#define PROPERTY_FONTSIZE	"fontsize"
#define PROPERTY_COLOR		"color"
#define PROPERTY_OPACITY	"opacity"
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
	NodeLoader::parseAttributes();

	sys::Color4B color;
	std::string str;
	float floatVal;
	int intVal;
	uchar ucVal;
	BlendParam blend;
	sys::Size size;

	LOAD_WDIGET_ATTRIBUTE(PROPERTY_COLOR, setColor, color);
	LOAD_WDIGET_ATTRIBUTE(PROPERTY_OPACITY, setOpacity, ucVal);
	LOAD_WDIGET_ATTRIBUTE(PROPERTY_BLEND, setBlend, blend);

	LOAD_WDIGET_STRING_ATTRIBUTE(PROPERTY_PATH, setFontPath, str);
	LOAD_WDIGET_ATTRIBUTE(PROPERTY_FONTSIZE, setFontSize, floatVal);
	LOAD_WDIGET_CAST_ATTRIBUTE(PROPERTY_HORIZONTAL, setHorizontalAlignment, intVal, render::HorizontalAlignment);
	LOAD_WDIGET_CAST_ATTRIBUTE(PROPERTY_VERTICAL, setVerticalAlignment, intVal, render::VerticalAlignment);

	LOAD_WDIGET_STRING_ATTRIBUTE(PROPERTY_TEXT, setString, str);
	LOAD_WDIGET_ATTRIBUTE(PROPERTY_DIMENSIONS, setDimensions, size);
}

void TextLoader::saveAttributes()
{
	NodeLoader::saveAttributes();

	SAVE_WDIGET_ATTRIBUTE(PROPERTY_COLOR, getColor);
	SAVE_WDIGET_ATTRIBUTE(PROPERTY_OPACITY, getOpacity);
	SAVE_WDIGET_ATTRIBUTE(PROPERTY_BLEND, getBlend);

	SAVE_WDIGET_ATTRIBUTE(PROPERTY_PATH, getFontPath);
	SAVE_WDIGET_ATTRIBUTE(PROPERTY_FONTSIZE, getFontSize);
	SAVE_WDIGET_CAST_ATTRIBUTE(PROPERTY_HORIZONTAL, getHorizontalAlignment, int);
	SAVE_WDIGET_CAST_ATTRIBUTE(PROPERTY_VERTICAL, getVerticalAlignment, int);

	SAVE_WDIGET_ATTRIBUTE(PROPERTY_TEXT, getString);
	SAVE_WDIGET_ATTRIBUTE(PROPERTY_DIMENSIONS, getDimensions);
}
