#include "NodeLoader.h"

using namespace ui;

#define PROPERTY_POSTION			"Position"
#define PROPERTY_SCALE				"Scale"
#define PROPERTY_ROTATION			"Rotation"
#define PROPERTY_SIZE				"Size"
#define PROPERTY_ANCHORPOINT		"Anchor"

NodeLoader::NodeLoader()
{

}

NodeLoader::~NodeLoader()
{

}

void NodeLoader::parseAttribute()
{
	sys::Vector vec;
	sys::Size size;

	GET_NODE->setName(getAttributeLoader()->getName());

	if (getAttributeLoader()->getAttribute(PROPERTY_POSTION, vec))
	{
		GET_NODE->setPosition(vec);
	}

	if (getAttributeLoader()->getAttribute(PROPERTY_SCALE, vec))
	{
		GET_NODE->setScale(vec);
	}

	if (getAttributeLoader()->getAttribute(PROPERTY_ROTATION, vec))
	{
		GET_NODE->setRotation(vec);
	}

	if (getAttributeLoader()->getAttribute(PROPERTY_SIZE, size))
	{
		GET_NODE->setSize(size);
	}

	if (getAttributeLoader()->getAttribute(PROPERTY_ANCHORPOINT, vec))
	{
		GET_NODE->setAnchorPoint(vec);
	}
}

void NodeLoader::saveAttributes()
{
	this->getAttributeLoader()->setName(GET_NODE->getName());
	this->getAttributeLoader()->setAttribute(PROPERTY_POSTION, GET_NODE->getPosition());
	this->getAttributeLoader()->setAttribute(PROPERTY_SCALE, GET_NODE->getScale());
	this->getAttributeLoader()->setAttribute(PROPERTY_ROTATION, GET_NODE->getRotation());
	this->getAttributeLoader()->setAttribute(PROPERTY_SIZE, GET_NODE->getSize());
	this->getAttributeLoader()->setAttribute(PROPERTY_ANCHORPOINT, GET_NODE->getAnchorPoint());
}
