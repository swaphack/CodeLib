#include "ListViewLoader.h"

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
	sys::CSSSize itemSize;
	bool useItemSize = false;
	bool showInCenter = false;

	LOAD_WIDGET_ATTRIBUTE(PROPERTY_ITEMSIZE, setItemSize, itemSize);
	LOAD_WIDGET_ATTRIBUTE(PROPERTY_USE_ITEMSIZE, setUseItemSize, useItemSize);
	LOAD_WIDGET_ATTRIBUTE(PROPERTY_CENTER, setShowInCenter, showInCenter);

	ScrollViewLoader::parseAttributes();
}

void ui::ListViewLoader::saveAttributes()
{
	ScrollViewLoader::saveAttributes();

	SAVE_WIDGET_ATTRIBUTE(PROPERTY_ITEMSIZE, getItemSize);
	SAVE_WIDGET_ATTRIBUTE(PROPERTY_USE_ITEMSIZE, isUseItemSize);

	SAVE_WIDGET_ATTRIBUTE(PROPERTY_CENTER, isShowInCenter);
}
