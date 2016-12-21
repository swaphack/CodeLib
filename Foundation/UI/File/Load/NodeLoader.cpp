#include "NodeLoader.h"

using namespace ui;

#define PROPERTY_POSTION			"Position"
#define PROPERTY_SIZE				"Size"

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

	LOAD_NAME();
	LOAD_ATTRIBUTE(PROPERTY_POSTION, setPosition, pos);
	LOAD_ATTRIBUTE(PROPERTY_SIZE, setSize, size);
}

void NodeLoader::saveAttributes()
{
	SAVE_NAME();
	SAVE_ATTRIBUTE(PROPERTY_POSTION, getPosition);
	SAVE_ATTRIBUTE(PROPERTY_SIZE, getSize);
}