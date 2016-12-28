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
	LayoutItemLoader::parseAttributes();

	sys::Margin margin;

	LOAD_NAME();
	LOAD_ATTRIBUTE(PROPERTY_MARGIN, setMargin, margin);
}

void LayoutLoader::saveAttributes()
{
	LayoutItemLoader::saveAttributes();

	SAVE_NAME();
	SAVE_ATTRIBUTE(PROPERTY_MARGIN, getMargin);
}