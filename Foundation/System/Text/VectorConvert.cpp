#include "VectorConvert.h"
#include "Base/macros.h"
#include "Type/String.h"

bool sys::VectorConvert::convertToVector(const std::string& text, math::Vector2& value)
{
	if (text.empty())
	{
		return false;
	}
	sys::String val = text;
	std::vector<sys::String> params;

	val.split(",", params);

	if (params.size() != 2)
	{
		return false;
	}

	value = math::Vector2(atof(params[0].getString()), atof(params[1].getString()));

	return true;
}

bool sys::VectorConvert::convertToVector(const std::string& text, math::Vector3& value)
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

	value = math::Vector3(atof(params[0].getString()), atof(params[1].getString()), atof(params[2].getString()));

	return true;
}

void sys::VectorConvert::convertToText(const math::Vector2& value, std::string& text)
{
	text = getCString("%f,%f", value.getX(), value.getY());
}

void sys::VectorConvert::convertToText(const math::Vector3& value, std::string& text)
{
	text = getCString("%f,%f,%f", value.getX(), value.getY(), value.getZ());
}
