#include "LayoutLoader.h"

using namespace ui;

#define PROPERTY_IMAGE_SHOW		"showImage"
#define PROPERTY_MASK_SHOW		"showMask"
#define PROPERTY_MASK_COLOR		"maskColor"
#define PROPERTY_IMAGE_PATH		"imagePath"

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
	phy::Color4B bgMaskColor = phy::Color4B(255, 255, 255,255);

	LOAD_WIDGET_ATTRIBUTE(PROPERTY_IMAGE_SHOW, setBackgroudImageVisible, showBgImage);
	LOAD_WIDGET_ATTRIBUTE(PROPERTY_MASK_SHOW, setBackgroudMaskVisible, showBgMask);
	LOAD_WIDGET_STRING_ATTRIBUTE(PROPERTY_IMAGE_PATH, setBackgroundImagePath, bgImagePath);
	LOAD_WIDGET_ATTRIBUTE(PROPERTY_MASK_COLOR, setBackgroundColor, bgMaskColor);

	WidgetLoader::parseAttributes();
}

void LayoutLoader::saveAttributes()
{
	WidgetLoader::saveAttributes();

	SAVE_WIDGET_ATTRIBUTE(PROPERTY_IMAGE_SHOW, isBackgroudImageVisible);
	SAVE_WIDGET_ATTRIBUTE(PROPERTY_MASK_SHOW, isBackgroudMaskVisible);
	SAVE_WIDGET_ATTRIBUTE(PROPERTY_IMAGE_PATH, getBackgroundImage);
	SAVE_WIDGET_ATTRIBUTE(PROPERTY_MASK_COLOR, getBackgroundColor);
}