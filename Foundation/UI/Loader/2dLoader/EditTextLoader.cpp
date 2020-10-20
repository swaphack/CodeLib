#include "EditTextLoader.h"

#define PROPERTY_TEXT "text"
#define PROPERTY_PLACEHOLDER "placeholder"

#define PROPERTY_FONTPATH	"fontPath"
#define PROPERTY_FONTSIZE	"fontSize"
#define PROPERTY_TEXTCOLOR	"textColor"
#define PROPERTY_PLACEHOLDERCOLOR	"placeholderColor"

#define PROPERTY_MULTILINE	"multiLine"

ui::EditTextLoader::EditTextLoader()
{
}

ui::EditTextLoader::~EditTextLoader()
{
}

void ui::EditTextLoader::parseAttributes()
{
	std::string text;
	std::string tips;

	sys::Color3B color;
	sys::Color3B tipsColor;
	std::string fontpath;
	float fontSize = 0;
	bool multiLine = false;

	LOAD_WIDGET_ATTRIBUTE(PROPERTY_TEXT, setString, text);
	LOAD_WIDGET_ATTRIBUTE(PROPERTY_PLACEHOLDER, setPlaceholder, tips);

	LOAD_WIDGET_ATTRIBUTE(PROPERTY_TEXTCOLOR, setTextColor, color);
	LOAD_WIDGET_ATTRIBUTE(PROPERTY_PLACEHOLDERCOLOR, setPlaceholderTextColor, tipsColor);

	LOAD_WIDGET_STRING_ATTRIBUTE(PROPERTY_FONTPATH, setFontPath, fontpath);
	LOAD_WIDGET_ATTRIBUTE(PROPERTY_FONTSIZE, setFontSize, fontSize);

	LOAD_WIDGET_ATTRIBUTE(PROPERTY_MULTILINE, setMultiLine, multiLine);

	WidgetLoader::parseAttributes();
}

void ui::EditTextLoader::saveAttributes()
{
	WidgetLoader::saveAttributes();

	SAVE_WIDGET_ATTRIBUTE(PROPERTY_TEXT, getString);
	SAVE_WIDGET_ATTRIBUTE(PROPERTY_PLACEHOLDER, getPlaceholder);

	SAVE_WIDGET_ATTRIBUTE(PROPERTY_TEXTCOLOR, getTextColor);
	SAVE_WIDGET_ATTRIBUTE(PROPERTY_PLACEHOLDERCOLOR, getPlaceholderTextColor);

	SAVE_WIDGET_ATTRIBUTE(PROPERTY_FONTPATH, getFontPath);
	SAVE_WIDGET_ATTRIBUTE(PROPERTY_FONTSIZE, getFontSize);

	SAVE_WIDGET_ATTRIBUTE(PROPERTY_MULTILINE, isMultiLine);
}
