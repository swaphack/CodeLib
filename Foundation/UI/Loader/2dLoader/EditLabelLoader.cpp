#include "EditLabelLoader.h"

#define PROPERTY_TEXT "text"
#define PROPERTY_PLACEHOLDER "placeholder"

ui::EditLabelLoader::EditLabelLoader()
{
}

ui::EditLabelLoader::~EditLabelLoader()
{
}

void ui::EditLabelLoader::parseAttributes()
{
	std::string text;
	std::string tips;

	LOAD_WIDGET_ATTRIBUTE(PROPERTY_TEXT, setString, text);
	LOAD_WIDGET_ATTRIBUTE(PROPERTY_PLACEHOLDER, setPlaceholder, tips);

	WidgetLoader::parseAttributes();
}

void ui::EditLabelLoader::saveAttributes()
{
	WidgetLoader::saveAttributes();

	SAVE_WIDGET_ATTRIBUTE(PROPERTY_TEXT, getString);
	SAVE_WIDGET_ATTRIBUTE(PROPERTY_PLACEHOLDER, getPlaceholder);
}
