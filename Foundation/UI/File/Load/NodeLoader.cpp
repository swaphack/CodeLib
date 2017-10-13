#include "NodeLoader.h"

using namespace ui;

#define PROPERTY_NAME			"name"
#define PROPERTY_RECT			"rect"
#define PROPERTY_BOX_COLOR		"boxcolor"
#define PROPERTY_BOX_VISIBLE	"boxvisible"

/*
#define PROPERTY_MINSIZE		"minsize"
#define PROPERTY_MAXSIZE		"maxsize"
#define PROPERTY_SIZEPOLICY		"sizepolicy"
*/

NodeLoader::NodeLoader()
{

}

NodeLoader::~NodeLoader()
{
}

void NodeLoader::parseAttributes()
{
	std::string name;
	sys::Rect rect;
	sys::Color4B color;
	bool visible;

	LOAD_LAYOUTITEM_ATTRIBUTE(PROPERTY_NAME, setName, name);
	LOAD_LAYOUTITEM_ATTRIBUTE(PROPERTY_RECT, setGeometry, rect);
	LOAD_LAYOUTITEM_ATTRIBUTE(PROPERTY_BOX_COLOR, setBoxColor, color);
	LOAD_LAYOUTITEM_ATTRIBUTE(PROPERTY_BOX_VISIBLE, setBoxVisible, visible);

	getCastWidget()->setAnchorPoint(sys::Vector3::Zero);
}

void NodeLoader::saveAttributes()
{
	SAVE_LAYOUTITEM_NAME();
	SAVE_LAYOUTITEM_ATTRIBUTE(PROPERTY_RECT, getGeometry);
	SAVE_LAYOUTITEM_ATTRIBUTE(PROPERTY_BOX_COLOR, getBoxColor);
	SAVE_LAYOUTITEM_ATTRIBUTE(PROPERTY_BOX_VISIBLE, isBoxVisible);
}