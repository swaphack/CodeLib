#include "ScrollViewLoader.h"

#define PROPERTY_DIRECTION "direction"
#define PROPERTY_ITEMSIZE "itemSize"

ui::ScrollViewLoader::ScrollViewLoader()
{
}

ui::ScrollViewLoader::~ScrollViewLoader()
{
}

void ui::ScrollViewLoader::parseAttributes()
{
	int eDir;
	math::Size itemSize;

	LOAD_WIDGET_CAST_ATTRIBUTE(PROPERTY_DIRECTION, setScrollDirection, eDir, render::ScrollDirection);
	LOAD_WIDGET_ATTRIBUTE(PROPERTY_ITEMSIZE, setItemSize, itemSize);

	WidgetLoader::parseAttributes();
}

void ui::ScrollViewLoader::saveAttributes()
{
	WidgetLoader::saveAttributes();

	SAVE_WIDGET_CAST_ATTRIBUTE(PROPERTY_DIRECTION, getScrollDirection, int);
	SAVE_WIDGET_ATTRIBUTE(PROPERTY_ITEMSIZE, getItemSize);
}
