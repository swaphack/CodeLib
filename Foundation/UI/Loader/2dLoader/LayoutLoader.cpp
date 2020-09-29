#include "LayoutLoader.h"

using namespace ui;

#define PROPERTY_MARGIN			"margin"
#define PROPERTY_IMAGE_SHOW		"showimage"
#define PROPERTY_MASK_SHOW		"showmask"
#define PROPERTY_MASK_COLOR		"maskcolor"
#define PROPERTY_IMAGE_PATH		"imagepath"

LayoutLoader::LayoutLoader()
{

}

LayoutLoader::~LayoutLoader()
{
}

void LayoutLoader::parseAttributes()
{
	sys::CSSMargin margin;
	bool showBgImage = false;
	bool showBgMask = false;
	std::string bgImagePath;
	sys::Color4B bgMaskColor = sys::Color4B(0,0,0,255);

	LOAD_LAYOUTITEM_ATTRIBUTE(PROPERTY_MARGIN, setMargin, margin);
	LOAD_WIDGET_ATTRIBUTE(PROPERTY_IMAGE_SHOW, setBackgroudImageVisible, showBgImage);
	LOAD_WIDGET_ATTRIBUTE(PROPERTY_MASK_SHOW, setBackgroudMaskVisible, showBgMask);
	LOAD_WIDGET_STRING_ATTRIBUTE(PROPERTY_IMAGE_PATH, setBackgroundImagePath, bgImagePath);
	LOAD_WIDGET_ATTRIBUTE(PROPERTY_MASK_COLOR, setBackgroundColor, bgMaskColor);

	WidgetLoader::parseAttributes();
}

void LayoutLoader::saveAttributes()
{
	WidgetLoader::saveAttributes();

	SAVE_LAYOUTITEM_ATTRIBUTE(PROPERTY_MARGIN, getMargin);
	SAVE_WIDGET_ATTRIBUTE(PROPERTY_IMAGE_SHOW, isBackgroudImageVisible);
	SAVE_WIDGET_ATTRIBUTE(PROPERTY_MASK_SHOW, isBackgroudMaskVisible);
	SAVE_WIDGET_ATTRIBUTE(PROPERTY_IMAGE_PATH, getBackgroundImage);
	SAVE_WIDGET_ATTRIBUTE(PROPERTY_MASK_COLOR, getBackgroundColor);
}