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

	LOAD_NAME();
	LOAD_ATTRIBUTE(PROPERTY_POSTION, setPosition, vec);
	LOAD_ATTRIBUTE(PROPERTY_SCALE, setScale, vec);
	LOAD_ATTRIBUTE(PROPERTY_ROTATION, setRotation, vec);
	LOAD_ATTRIBUTE(PROPERTY_SIZE, setSize, size);
	LOAD_ATTRIBUTE(PROPERTY_ANCHORPOINT, setAnchorPoint, vec);
}

void NodeLoader::saveAttributes()
{
	SAVE_NAME();
	SAVE_ATTRIBUTE(PROPERTY_POSTION, getPosition);
	SAVE_ATTRIBUTE(PROPERTY_SCALE, getScale);
	SAVE_ATTRIBUTE(PROPERTY_ROTATION, getRotation);
	SAVE_ATTRIBUTE(PROPERTY_SIZE, getSize);
	SAVE_ATTRIBUTE(PROPERTY_ANCHORPOINT, getAnchorPoint);
}
