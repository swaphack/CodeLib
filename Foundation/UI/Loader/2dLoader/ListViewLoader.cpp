#include "ListViewLoader.h"

#define PROPERTY_DIRECTION "direction"
#define PROPERTY_ITEMSIZE "itemSize"

ui::ListViewLoader::ListViewLoader()
{
}

ui::ListViewLoader::~ListViewLoader()
{
}

void ui::ListViewLoader::parseAttributes()
{
	int eDir;
	math::Size itemSize;

	LOAD_WIDGET_CAST_ATTRIBUTE(PROPERTY_DIRECTION, setScrollDirection, eDir, render::ScrollDirection);
	LOAD_WIDGET_ATTRIBUTE(PROPERTY_ITEMSIZE, setItemSize, itemSize);

	ScrollViewLoader::parseAttributes();
}

void ui::ListViewLoader::saveAttributes()
{
	ScrollViewLoader::saveAttributes();

	SAVE_WIDGET_CAST_ATTRIBUTE(PROPERTY_DIRECTION, getScrollDirection, int);
	SAVE_WIDGET_ATTRIBUTE(PROPERTY_ITEMSIZE, getItemSize);
}
