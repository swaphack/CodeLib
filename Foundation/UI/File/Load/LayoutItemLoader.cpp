#include "LayoutItemLoader.h"

using namespace ui;

#define PROPERTY_RECT			"rect"
#define PROPERTY_MINSIZE		"minsize"
#define PROPERTY_MAXSIZE		"maxsize"
#define PROPERTY_BOX_COLOR		"boxcolor"
#define PROPERTY_BOX_VISIBLE	"boxvisible"
#define PROPERTY_SIZEPOLICY		"sizepolicy"

LayoutItemLoader::LayoutItemLoader()
{

}

LayoutItemLoader::~LayoutItemLoader()
{
}

void LayoutItemLoader::parseAttributes()
{
	sys::Rect rect;
	sys::Size size;
	SizePolicy policy;
	sys::Margin margin;
	sys::Color4B color;
	bool visible;

	LOAD_LAYOUTITEM_NAME();
	LOAD_LAYOUTITEM_ATTRIBUTE(PROPERTY_RECT, setGeometry, rect);
	LOAD_LAYOUTITEM_ATTRIBUTE(PROPERTY_MINSIZE, setMinSize, size);
	LOAD_LAYOUTITEM_ATTRIBUTE(PROPERTY_MAXSIZE, setMaxSize, size);
	LOAD_LAYOUTITEM_ATTRIBUTE(PROPERTY_BOX_COLOR, setBoxColor, color);
	LOAD_LAYOUTITEM_ATTRIBUTE(PROPERTY_BOX_VISIBLE, setBoxVisible, visible);
	LOAD_LAYOUTITEM_ATTRIBUTE(PROPERTY_SIZEPOLICY, setSizePolicy, policy);
}

void LayoutItemLoader::saveAttributes()
{
	SAVE_LAYOUTITEM_NAME();
	SAVE_LAYOUTITEM_ATTRIBUTE(PROPERTY_RECT, getGeometry);
	SAVE_LAYOUTITEM_ATTRIBUTE(PROPERTY_MINSIZE, getMinSize);
	SAVE_LAYOUTITEM_ATTRIBUTE(PROPERTY_MAXSIZE, getMaxSize);
	SAVE_LAYOUTITEM_ATTRIBUTE(PROPERTY_BOX_COLOR, getBoxColor);
	SAVE_LAYOUTITEM_ATTRIBUTE(PROPERTY_BOX_VISIBLE, isBoxVisible);
	SAVE_LAYOUTITEM_ATTRIBUTE(PROPERTY_SIZEPOLICY, getSizePolicy);
}