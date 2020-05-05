#include "LayoutLoader.h"

using namespace ui;

#define PROPERTY_MARGIN			"margin"

LayoutLoader::LayoutLoader()
{

}

LayoutLoader::~LayoutLoader()
{
}

void LayoutLoader::parseAttributes()
{
	sys::Margin margin;

	LOAD_LAYOUTITEM_ATTRIBUTE(PROPERTY_MARGIN, setMargin, margin);

	WidgetLoader::parseAttributes();
}

void LayoutLoader::saveAttributes()
{
	WidgetLoader::saveAttributes();

	SAVE_LAYOUTITEM_ATTRIBUTE(PROPERTY_MARGIN, getMargin);
}