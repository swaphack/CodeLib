#include "ColorConvert.h"
#include "Base/macros.h"
#include "Type/String.h"

bool sys::ColorConvert::convertToColor(const std::string& text, phy::Color3B& color)
{
	if (text.empty())
	{
		return false;
	}

	sys::String val = text;
	std::vector<sys::String> params;

	val.split(",", params);

	if (params.size() != 3)
	{
		return false;
	}

	color = phy::Color3B(atof(params[0].getString()), atof(params[1].getString()), atof(params[2].getString()));

	return true;
}

bool sys::ColorConvert::convertToColor(const std::string& text, phy::Color4B& color)
{
	if (text.empty())
	{
		return false;
	}

	sys::String val = text;
	std::vector<sys::String> params;

	val.split(",", params);

	if (params.size() != 4)
	{
		return false;
	}

	color = phy::Color4B(atof(params[0].getString()), atof(params[1].getString()), atof(params[2].getString()), atof(params[3].getString()));

	return true;
}

bool sys::ColorConvert::convertToColor(const std::string& text, phy::Color3F& color)
{
	if (text.empty())
	{
		return false;
	}

	sys::String val = text;
	std::vector<sys::String> params;

	val.split(",", params);

	if (params.size() != 3)
	{
		return false;
	}

	color = phy::Color3F(atof(params[0].getString()), atof(params[1].getString()), atof(params[2].getString()));

	return true;
}

bool sys::ColorConvert::convertToColor(const std::string& text, phy::Color4F& color)
{
	if (text.empty())
	{
		return false;
	}
	sys::String val = text;
	std::vector<sys::String> params;

	val.split(",", params);

	if (params.size() != 4)
	{
		return false;
	}

	color = phy::Color4F(atof(params[0].getString()), atof(params[1].getString()), atof(params[2].getString()), atof(params[3].getString()));

	return true;
}

void sys::ColorConvert::convertToText(const phy::Color3B& color, std::string& text)
{
	text = getCString("%d,%d,%d", color[0], color[1], color[2]);
}

void sys::ColorConvert::convertToText(const phy::Color4B& color, std::string& text)
{
	text = getCString("%d,%d,%d,%d", color[0], color[1], color[2], color[3]);
}

void sys::ColorConvert::convertToText(const phy::Color3F& color, std::string& text)
{
	text = getCString("%f,%f,%f", color[0], color[1], color[2]);
}

void sys::ColorConvert::convertToText(const phy::Color4F& color, std::string& text)
{
	text = getCString("%f,%f,%f,%f", color[0], color[1], color[2], color[3]);
}
