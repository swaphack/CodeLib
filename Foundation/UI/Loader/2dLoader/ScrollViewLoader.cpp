#include "ScrollViewLoader.h"

#define PROPERTY_HORIZONTALSCROLL	"horizontalScroll"
#define PROPERTY_VERTICALSCROLL		"verticalScroll"

ui::ScrollViewLoader::ScrollViewLoader()
{
}

ui::ScrollViewLoader::~ScrollViewLoader()
{
}

void ui::ScrollViewLoader::parseAttributes()
{

	bool bHorizontalScroll = false;
	bool bVerticalScroll = false;

	LOAD_WIDGET_ATTRIBUTE(PROPERTY_HORIZONTALSCROLL, setHorizontalScroll, bHorizontalScroll);
	LOAD_WIDGET_ATTRIBUTE(PROPERTY_VERTICALSCROLL, setVerticalScroll, bVerticalScroll);

	LayoutLoader::parseAttributes();
}

void ui::ScrollViewLoader::saveAttributes()
{
	SAVE_WIDGET_ATTRIBUTE(PROPERTY_HORIZONTALSCROLL, isHorizontalScroll);
	SAVE_WIDGET_ATTRIBUTE(PROPERTY_HORIZONTALSCROLL, isVerticalScroll);

	LayoutLoader::saveAttributes();
}
