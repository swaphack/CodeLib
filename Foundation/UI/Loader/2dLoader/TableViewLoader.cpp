#include "TableViewLoader.h"


#define PROPERTY_ITEMSIZE "itemSize"
#define PROPERTY_USE_ITEMSIZE "useItemSize"
#define PROPERTY_CENTER "center"

ui::TableViewLoader::TableViewLoader()
{
}

ui::TableViewLoader::~TableViewLoader()
{
}

void ui::TableViewLoader::parseAttributes()
{
	ScrollViewLoader::parseAttributes();
}

void ui::TableViewLoader::saveAttributes()
{
	ScrollViewLoader::saveAttributes();
}
