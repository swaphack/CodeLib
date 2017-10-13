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
	NodeLoader::parseAttributes();

	sys::Margin margin;

	LOAD_LAYOUTITEM_ATTRIBUTE(PROPERTY_MARGIN, setMargin, margin);
}

void LayoutLoader::saveAttributes()
{
	NodeLoader::saveAttributes();

	SAVE_LAYOUTITEM_ATTRIBUTE(PROPERTY_MARGIN, getMargin);
}