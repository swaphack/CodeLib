#include "ListViewLoader.h"

#define PROPERTY_DIRECTION "direction"
#define PROPERTY_ITEMSIZE "itemSize"
#define PROPERTY_USE_ITEMSIZE "useItemSize"
#define PROPERTY_CENTER "center"

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
	bool useItemSize;
	bool showInCenter;

	LOAD_WIDGET_CAST_ATTRIBUTE(PROPERTY_DIRECTION, setScrollDirection, eDir, ui::ScrollDirection);
	LOAD_WIDGET_ATTRIBUTE(PROPERTY_ITEMSIZE, setItemSize, itemSize);
	LOAD_WIDGET_ATTRIBUTE(PROPERTY_USE_ITEMSIZE, setUseItemSize, useItemSize);
	LOAD_WIDGET_ATTRIBUTE(PROPERTY_CENTER, setShowInCenter, showInCenter);

	ScrollViewLoader::parseAttributes();
}

void ui::ListViewLoader::saveAttributes()
{
	ScrollViewLoader::saveAttributes();

	SAVE_WIDGET_CAST_ATTRIBUTE(PROPERTY_DIRECTION, getScrollDirection, int);
	SAVE_WIDGET_ATTRIBUTE(PROPERTY_ITEMSIZE, getItemSize);
	SAVE_WIDGET_ATTRIBUTE(PROPERTY_USE_ITEMSIZE, isUseItemSize);

	SAVE_WIDGET_ATTRIBUTE(PROPERTY_CENTER, isShowInCenter);
}
