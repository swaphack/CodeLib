#include "LayoutItemLoader.h"

using namespace ui;

#define PROPERTY_RECT			"rect"
#define PROPERTY_MINSIZE		"minsize"
#define PROPERTY_MAXSIZE		"maxsize"
#define PROPERTY_SIZETYPE		"sizetype"

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

	LOAD_NAME();
	LOAD_ATTRIBUTE(PROPERTY_RECT, setGeometry, rect);
	LOAD_ATTRIBUTE(PROPERTY_MINSIZE, setMinSize, size);
	LOAD_ATTRIBUTE(PROPERTY_MAXSIZE, setMaxSize, size);
	LOAD_ATTRIBUTE(PROPERTY_SIZETYPE, setSizePolicy, policy);
}

void LayoutItemLoader::saveAttributes()
{
	SAVE_NAME();
	SAVE_ATTRIBUTE(PROPERTY_RECT, getGeometry);
	SAVE_ATTRIBUTE(PROPERTY_MINSIZE, getMinSize);
	SAVE_ATTRIBUTE(PROPERTY_MAXSIZE, getMaxSize);
	SAVE_ATTRIBUTE(PROPERTY_SIZETYPE, getSizePolicy);
}