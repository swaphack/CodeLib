#include "ButtonLoader.h"

#define PROPERTY_TEXT		"text"
#define PROPERTY_FONTPATH	"fontPath"
#define PROPERTY_FONTSIZE	"fontSize"
#define PROPERTY_TEXTCOLOR		"textColor"

#define PROPERTY_NORMAL_IMAGE		"normalImage"
#define PROPERTY_SELECTED_IMAGE		"selectedImage"
#define PROPERTY_DISABLED_IMAGE		"disabledImage"

ui::ButtonLoader::ButtonLoader()
{
}

ui::ButtonLoader::~ButtonLoader()
{
}

void ui::ButtonLoader::parseAttributes()
{
	std::string text;
	sys::Color3B color;
	std::string fontpath;
	float fontSize = 0;

	std::string normalImage;
	std::string selectedImage;
	std::string disabledImage;

	LOAD_WIDGET_ATTRIBUTE(PROPERTY_TEXT, setString, text);

	LOAD_WIDGET_ATTRIBUTE(PROPERTY_TEXTCOLOR, setTextColor, color);
	LOAD_WIDGET_STRING_ATTRIBUTE(PROPERTY_FONTPATH, setFontPath, fontpath);
	LOAD_WIDGET_ATTRIBUTE(PROPERTY_FONTSIZE, setFontSize, fontSize);

	LOAD_WIDGET_ATTRIBUTE(PROPERTY_NORMAL_IMAGE, setNormalImage, normalImage);
	LOAD_WIDGET_ATTRIBUTE(PROPERTY_SELECTED_IMAGE, setSelectedImage, selectedImage);
	LOAD_WIDGET_ATTRIBUTE(PROPERTY_DISABLED_IMAGE, setDisabledImage, disabledImage);

	WidgetLoader::parseAttributes();
}

void ui::ButtonLoader::saveAttributes()
{
	WidgetLoader::saveAttributes();

	SAVE_WIDGET_ATTRIBUTE(PROPERTY_TEXT, getString);

	SAVE_WIDGET_ATTRIBUTE(PROPERTY_TEXTCOLOR, getTextColor);
	SAVE_WIDGET_ATTRIBUTE(PROPERTY_FONTPATH, getFontPath);
	SAVE_WIDGET_ATTRIBUTE(PROPERTY_FONTSIZE, getFontSize);

	SAVE_WIDGET_ATTRIBUTE(PROPERTY_NORMAL_IMAGE, getNormalImage);
	SAVE_WIDGET_ATTRIBUTE(PROPERTY_SELECTED_IMAGE, getSelectedImage);
	SAVE_WIDGET_ATTRIBUTE(PROPERTY_DISABLED_IMAGE, getDisabledImage);
}
