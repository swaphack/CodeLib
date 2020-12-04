#include "Scale9ImageLoader.h"

#define PROPERTY_SCALE9_MARGIN		"scale9Margin"

ui::Scale9ImageLoader::Scale9ImageLoader()
{
}

ui::Scale9ImageLoader::~Scale9ImageLoader()
{
}

void ui::Scale9ImageLoader::parseAttributes()
{
	sys::CSSMargin margin;

	LOAD_WIDGET_ATTRIBUTE(PROPERTY_SCALE9_MARGIN, setMargin, margin);

	ImageLoader::parseAttributes();
}

void ui::Scale9ImageLoader::saveAttributes()
{
	SAVE_WIDGET_ATTRIBUTE(PROPERTY_SCALE9_MARGIN, getMargin);

	ImageLoader::saveAttributes();
}
