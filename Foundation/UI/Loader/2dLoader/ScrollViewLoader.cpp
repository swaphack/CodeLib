#include "ScrollViewLoader.h"

#define PROPERTY_HORIZONTALSCROLL	"horizontalScroll"
#define PROPERTY_VERTICALSCROLL		"verticalScroll"
#define PROPERTY_MOVINGMULTIPLE		"moveMultiple"

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
	float movingMultiple = 1;

	LOAD_WIDGET_ATTRIBUTE(PROPERTY_HORIZONTALSCROLL, setHorizontalScroll, bHorizontalScroll);
	LOAD_WIDGET_ATTRIBUTE(PROPERTY_VERTICALSCROLL, setVerticalScroll, bVerticalScroll);
	LOAD_WIDGET_ATTRIBUTE(PROPERTY_MOVINGMULTIPLE, setMovingMultiple, movingMultiple);

	LayoutLoader::parseAttributes();
}

void ui::ScrollViewLoader::saveAttributes()
{
	SAVE_WIDGET_ATTRIBUTE(PROPERTY_HORIZONTALSCROLL, isHorizontalScroll);
	SAVE_WIDGET_ATTRIBUTE(PROPERTY_HORIZONTALSCROLL, isVerticalScroll);
	SAVE_WIDGET_ATTRIBUTE(PROPERTY_MOVINGMULTIPLE, getMovingMultiple);

	LayoutLoader::saveAttributes();
}
