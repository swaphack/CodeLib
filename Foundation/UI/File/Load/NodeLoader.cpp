#include "NodeLoader.h"

using namespace ui;

#define PROPERTY_POSTION			"position"
#define PROPERTY_SIZE				"size"

NodeLoader::NodeLoader()
{

}

NodeLoader::~NodeLoader()
{
}

void NodeLoader::parseAttributes()
{
	sys::Point pos;
	sys::Size size;

	LOAD_WDIGET_NAME();
	LOAD_WDIGET_ATTRIBUTE(PROPERTY_POSTION, setPosition, pos);
	LOAD_WDIGET_ATTRIBUTE(PROPERTY_SIZE, setVolume, size);
}

void NodeLoader::saveAttributes()
{
	SAVE_WDIGET_NAME();
	SAVE_WDIGET_ATTRIBUTE(PROPERTY_POSTION, getPosition);
	SAVE_WDIGET_ATTRIBUTE(PROPERTY_SIZE, getSize);
}