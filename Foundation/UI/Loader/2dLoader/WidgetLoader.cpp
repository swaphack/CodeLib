#include "WidgetLoader.h"

using namespace ui;

#define PROPERTY_NAME			"name"
#define PROPERTY_BOX_COLOR		"boxColor"
#define PROPERTY_BOX_VISIBLE	"boxVisible"
#define PROPERTY_ANCHOR			"anchorPoint"
#define PROPERTY_MARGIN			"margin"
#define PROPERTY_SIZE			"size"
#define PROPERTY_MARGIN_STATE	"marginState"

/*
#define PROPERTY_MINSIZE		"minsize"
#define PROPERTY_MAXSIZE		"maxsize"
#define PROPERTY_SIZEPOLICY		"sizepolicy"
*/

WidgetLoader::WidgetLoader()
{

}

WidgetLoader::~WidgetLoader()
{
}

void WidgetLoader::parseAttributes()
{
	std::string name;
	sys::Color4B color;
	bool visible = false;
	math::Vector2 anchor;

	sys::CSSMargin margin;
	sys::CSSSize size;

	MarginState marginState;

	getWidget()->setAnchorPoint(0, 0);

	LOAD_LAYOUTITEM_ATTRIBUTE(PROPERTY_NAME, setName, name);
	LOAD_LAYOUTITEM_ATTRIBUTE(PROPERTY_BOX_COLOR, setBoxColor, color);
	LOAD_LAYOUTITEM_ATTRIBUTE(PROPERTY_BOX_VISIBLE, setBoxVisible, visible);
	LOAD_LAYOUTITEM_ATTRIBUTE(PROPERTY_MARGIN, setMargin, margin);
	LOAD_LAYOUTITEM_ATTRIBUTE(PROPERTY_SIZE, setSize, size);
	LOAD_LAYOUTITEM_ATTRIBUTE(PROPERTY_MARGIN_STATE, setMarginState, marginState);

	LOAD_WIDGET_ATTRIBUTE(PROPERTY_NAME, setName, name);
	LOAD_WIDGET_ATTRIBUTE(PROPERTY_ANCHOR, setAnchorPoint, anchor);
}

void WidgetLoader::saveAttributes()
{
	SAVE_LAYOUTITEM_NAME();
	SAVE_LAYOUTITEM_ATTRIBUTE(PROPERTY_MARGIN, getMargin);
	SAVE_LAYOUTITEM_ATTRIBUTE(PROPERTY_BOX_COLOR, getBoxColor);
	SAVE_LAYOUTITEM_ATTRIBUTE(PROPERTY_BOX_VISIBLE, isBoxVisible);
	SAVE_LAYOUTITEM_ATTRIBUTE(PROPERTY_MARGIN, getMargin);
	SAVE_LAYOUTITEM_ATTRIBUTE(PROPERTY_SIZE, getSize);
	SAVE_LAYOUTITEM_ATTRIBUTE(PROPERTY_MARGIN_STATE, getMarginState);

	SAVE_WIDGET_ATTRIBUTE(PROPERTY_NAME, getName);
	SAVE_WIDGET_ATTRIBUTE(PROPERTY_ANCHOR, getAnchorPoint);


}