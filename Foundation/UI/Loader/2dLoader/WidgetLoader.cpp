#include "WidgetLoader.h"

using namespace ui;

#define PROPERTY_NAME			"name"
#define PROPERTY_ANCHOR			"anchorPoint"
#define PROPERTY_SIZE			"size"
#define PROPERTY_SCALE			"scale"
#define PROPERTY_ROTATION		"rotation"
#define PROPERTY_MARGIN			"margin"
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
	math::Vector3 anchor;
	math::Vector3 scale;
	math::Vector3 rotation;

	sys::CSSMargin margin;
	sys::CSSSize size;

	MarginState marginState;

	getWidget()->setAnchorPoint(0, 0);

	LOAD_LAYOUTITEM_ATTRIBUTE(PROPERTY_NAME, setName, name);
	LOAD_LAYOUTITEM_ATTRIBUTE(PROPERTY_MARGIN, setMargin, margin);
	LOAD_LAYOUTITEM_ATTRIBUTE(PROPERTY_SIZE, setSize, size);
	LOAD_LAYOUTITEM_ATTRIBUTE(PROPERTY_MARGIN_STATE, setMarginState, marginState);

	LOAD_WIDGET_ATTRIBUTE(PROPERTY_NAME, setName, name);
	LOAD_WIDGET_ATTRIBUTE(PROPERTY_ANCHOR, setAnchorPoint, anchor);
	LOAD_WIDGET_ATTRIBUTE(PROPERTY_SCALE, setScale, scale);
	LOAD_WIDGET_ATTRIBUTE(PROPERTY_ROTATION, setRotation, rotation);
}

void WidgetLoader::saveAttributes()
{
	SAVE_LAYOUTITEM_NAME();
	SAVE_LAYOUTITEM_ATTRIBUTE(PROPERTY_NAME, getName);
	SAVE_LAYOUTITEM_ATTRIBUTE(PROPERTY_MARGIN, getMargin);
	SAVE_LAYOUTITEM_ATTRIBUTE(PROPERTY_SIZE, getSize);
	SAVE_LAYOUTITEM_ATTRIBUTE(PROPERTY_MARGIN_STATE, getMarginState);

	SAVE_WIDGET_ATTRIBUTE(PROPERTY_NAME, getName);
	SAVE_WIDGET_ATTRIBUTE(PROPERTY_ANCHOR, getAnchorPoint);
	SAVE_WIDGET_ATTRIBUTE(PROPERTY_SCALE, getScale);
	SAVE_WIDGET_ATTRIBUTE(PROPERTY_ROTATION, getRotation);


}