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

	if (getAttributeLoader()->getAttribute(PROPERTY_TEXT, str))
	{
		GET_NODE->setString(str.c_str());
	}

	if (getAttributeLoader()->getAttribute(PROPERTY_PATH, str))
	{
		GET_NODE->setFontPath(str.c_str());
	}

	if (getAttributeLoader()->getAttribute(PROPERTY_FONTSIZE, floatVal))
	{
		GET_NODE->setFontSize(floatVal);
	}

	if (getAttributeLoader()->getAttribute(PROPERTY_COLOR, color))
	{
		GET_NODE->setColor(color);
	}

	if (getAttributeLoader()->getAttribute(PROPERTY_HORIZONTAL, intVal))
	{
		GET_NODE->setHorizontalAlignment((render::HorizontalAlignment)intVal);
	}

	if (getAttributeLoader()->getAttribute(PROPERTY_VERTICAL, intVal))
	{
		GET_NODE->setVerticalAlignment((render::VerticalAlignment)intVal);
	}
}

void TextLoader::saveAttributes()
{
	NodeLoader::saveAttributes();

	this->getAttributeLoader()->setAttribute(PROPERTY_TEXT, GET_NODE->getString());
	this->getAttributeLoader()->setAttribute(PROPERTY_PATH, GET_NODE->getFontPath());
	this->getAttributeLoader()->setAttribute(PROPERTY_FONTSIZE, GET_NODE->getFontSize());
	this->getAttributeLoader()->setAttribute(PROPERTY_COLOR, GET_NODE->getColor());
	this->getAttributeLoader()->setAttribute(PROPERTY_HORIZONTAL, (int)GET_NODE->getHorizontalAlignment());
	this->getAttributeLoader()->setAttribute(PROPERTY_VERTICAL, (int)GET_NODE->getVerticalAlignment());
}
