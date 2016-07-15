#include "ImageLoader.h"

using namespace ui;

#define PROPERTY_COLOR		"Color"
#define PROPERTY_PATH		"Path"
#define PROPERTY_FLIPX		"FlipX"
#define PROPERTY_FLIPY		"FlipY"


ImageLoader::ImageLoader()
{

}

ImageLoader::~ImageLoader()
{

}

void ImageLoader::parseAttribute()
{
	NodeLoader::parseAttribute();

	sys::Color4B color;
	std::string str;
	bool boolVal;

	if (getAttributeLoader()->getAttribute(PROPERTY_COLOR, color))
	{
		GET_NODE->setColor(color);
	}

	if (getAttributeLoader()->getAttribute(PROPERTY_PATH, str))
	{
		GET_NODE->setImagePath(str.c_str());
	}

	if (getAttributeLoader()->getAttribute(PROPERTY_FLIPX, boolVal))
	{
		GET_NODE->setFlipX(boolVal);
	}

	if (getAttributeLoader()->getAttribute(PROPERTY_FLIPY, boolVal))
	{
		GET_NODE->setFlipY(boolVal);
	}
}

void ImageLoader::saveAttributes()
{
	NodeLoader::saveAttributes();

	this->getAttributeLoader()->setAttribute(PROPERTY_COLOR, GET_NODE->getColor());
	this->getAttributeLoader()->setAttribute(PROPERTY_PATH, GET_NODE->getImagePath());
	this->getAttributeLoader()->setAttribute(PROPERTY_FLIPX, GET_NODE->isFlipX());
	this->getAttributeLoader()->setAttribute(PROPERTY_FLIPY, GET_NODE->isFlipY());
}
