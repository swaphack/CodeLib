#include "FileLoader.h"

#define PROPERTY_FILE_PATH "filepath"

ui::FileLoader::FileLoader()
{
}

ui::FileLoader::~FileLoader()
{
}

void ui::FileLoader::parseAttributes()
{
	std::string filepath;

	WidgetLoader::parseAttributes();

	LOAD_WIDGET_ATTRIBUTE(PROPERTY_FILE_PATH, setFilePath, filepath);
}

void ui::FileLoader::saveAttributes()
{
	WidgetLoader::saveAttributes();

	SAVE_WIDGET_ATTRIBUTE(PROPERTY_FILE_PATH, getFilePath);
}
