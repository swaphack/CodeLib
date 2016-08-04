#include "TextLoader.h"

using namespace ui;


#define PROPERTY_TEXT		"Text"
#define PROPERTY_PATH		"Path"
#define PROPERTY_FONTSIZE	"FontSize"
#define PROPERTY_COLOR		"Color"
#define PROPERTY_HORIZONTAL	"Horizontal"
#define PROPERTY_VERTICAL	"Vertical"


TextLoader::TextLoader()
{

}

TextLoader::~TextLoader()
{

}

void TextLoader::parseAttribute()
{
	NodeLoader::parseAttribute();

	sys::Color4B color;
	std::string str;
	float floatVal;
	int intVal;

	LOAD_STRING_ATTRIBUTE(PROPERTY_TEXT, setString, str);
	LOAD_STRING_ATTRIBUTE(PROPERTY_PATH, setString, str);
	LOAD_ATTRIBUTE(PROPERTY_FONTSIZE, setFontSize, floatVal);
	LOAD_ATTRIBUTE(PROPERTY_COLOR, setColor, color);
	LOAD_CAST_ATTRIBUTE(PROPERTY_HORIZONTAL, setHorizontalAlignment, intVal, render::HorizontalAlignment);
	LOAD_CAST_ATTRIBUTE(PROPERTY_VERTICAL, setVerticalAlignment, intVal, render::VerticalAlignment);
}

void TextLoader::saveAttributes()
{
	NodeLoader::saveAttributes();

	SAVE_ATTRIBUTE(PROPERTY_TEXT, getString);
	SAVE_ATTRIBUTE(PROPERTY_PATH, getFontPath);
	SAVE_ATTRIBUTE(PROPERTY_FONTSIZE, getFontSize);
	SAVE_ATTRIBUTE(PROPERTY_COLOR, getColor);
	SAVE_CAST_ATTRIBUTE(PROPERTY_HORIZONTAL, getHorizontalAlignment, int);
	SAVE_CAST_ATTRIBUTE(PROPERTY_VERTICAL, getVerticalAlignment, int);
}
