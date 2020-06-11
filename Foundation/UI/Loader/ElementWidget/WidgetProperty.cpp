#include "WidgetProperty.h"
#include "system.h"

using namespace ui;


WidgetProperty::WidgetProperty()
{
}

WidgetProperty::~WidgetProperty()
{

}

void WidgetProperty::Clear()
{
	_attributes.clear();
}

void WidgetProperty::setAttribute(const std::string& name, bool value)
{
	int val = value ? 1 : 0;
	this->setAttribute(name, val);
}

void WidgetProperty::setAttribute(const std::string& name, const std::string& value)
{
	if (!name.empty() && !value.empty())
	{
		_attributes[name] = value;
	}
}

void WidgetProperty::setAttribute(const std::string& name, char value)
{
	if (name.empty())
	{
		return;
	}
	std::string str = getCString("%d", value);
	setAttribute(name, str);
}

void WidgetProperty::setAttribute(const std::string& name, short value)
{
	if (name.empty())
	{
		return;
	}
	std::string str = getCString("%d", value);
	setAttribute(name, str);
}

void WidgetProperty::setAttribute(const std::string& name, int value)
{
	if (name.empty())
	{
		return;
	}
	std::string str = getCString("%d", value);
	setAttribute(name, str);
}

void WidgetProperty::setAttribute(const std::string& name, float value)
{
	if (name.empty())
	{
		return;
	}
	std::string str = getCString("%d", value);
	setAttribute(name, str);
}

void WidgetProperty::setAttribute(const std::string& name, double value)
{
	if (name.empty())
	{
		return;
	}
	std::string str = getCString("%lf", value);
	setAttribute(name, str);
}

void WidgetProperty::setAttribute(const std::string& name, long value)
{
	if (name.empty())
	{
		return;
	}
	std::string str = getCString("%ld", value);
	setAttribute(name, str);
}

void WidgetProperty::setAttribute(const std::string& name, uint8_t value)
{
	if (name.empty())
	{
		return;
	}
	std::string str = getCString("%u", value);
	setAttribute(name, str);
}

void WidgetProperty::setAttribute(const std::string& name, uint16_t value)
{
	if (name.empty())
	{
		return;
	}
	std::string str = getCString("%u", value);
	setAttribute(name, str);
}

void WidgetProperty::setAttribute(const std::string& name, uint32_t value)
{
	if (name.empty())
	{
		return;
	}
	std::string str = getCString("%u", value);
	setAttribute(name, str);
}

void WidgetProperty::setAttribute(const std::string& name, uint64_t value)
{
	if (name.empty())
	{
		return;
	}
	std::string str = getCString("%lu", value);
	setAttribute(name, str);
}

void WidgetProperty::setAttribute(const std::string& name, const math::Vector3& value)
{
	if (name.empty())
	{
		return;
	}
	std::string str = getCString("%f,%f,%f", value.getX(), value.getY(), value.getZ());
	setAttribute(name, str);
}

void WidgetProperty::setAttribute(const std::string& name, const math::Vector2& value)
{
	if (name.empty())
	{
		return;
	}
	std::string str = getCString("%f,%f", value.getX(), value.getY());
	setAttribute(name, str);
}

void WidgetProperty::setAttribute(const std::string& name, const sys::Color4B& value)
{
	if (name.empty())
	{
		return;
	}
	std::string str = getCString("%d,%d,%d,%d", value.red, value.green, value.blue, value.alpha);
	setAttribute(name, str);
}

void WidgetProperty::setAttribute(const std::string& name, const math::Size& value)
{
	if (name.empty())
	{
		return;
	}
	std::string str = getCString("%f,%f", value.getWidth(), value.getHeight());
	setAttribute(name, str);
}

void WidgetProperty::setAttribute(const std::string& name, const math::Rect& value)
{
	if (name.empty())
	{
		return;
	}
	std::string str = getCString("%f,%f,%f,%f", value.getX(), value.getY(), value.getWidth(), value.getHeight());
	setAttribute(name, str);
}

void WidgetProperty::setAttribute(const std::string& name, const render::BlendParam& value)
{
	if (name.empty())
	{
		return;
	}
	std::string str = getCString("%d,%d", value.src, value.dest);
	setAttribute(name, str);
}

void WidgetProperty::setAttribute(const std::string& name, const sys::Margin& value)
{
	if (name.empty())
	{
		return;
	}
	std::string str = getCString("%f,%f,%f,%f", value.left, value.right, value.bottom, value.top);
	setAttribute(name, str);
}

void WidgetProperty::setAttribute(const std::string& name, const SizePolicy& value)
{
	if (name.empty())
	{
		return;
	}
	std::string str = getCString("%d,%d", value.width, value.height);
	setAttribute(name, str);
}

bool WidgetProperty::getAttribute(const std::string& name, bool& defaultValue)
{
	int value = 0;
	if (!getAttribute(name, value))
	{
		return false;
	}

	defaultValue = value == 0 ? false: true;

	return true;
}

bool WidgetProperty::getAttribute(const std::string& name, std::string& defaultValue)
{
	const std::string& value = getAttribute(name);
	if (value.empty())
	{
		return false;
	}

	defaultValue = value;

	return true;
}

bool WidgetProperty::getAttribute(const std::string& name, char& defaultValue)
{
	const std::string& value = getAttribute(name);
	if (value.empty())
	{
		return false;
	}
	
	defaultValue = (char)atoi(value.c_str());

	return true;
}

bool WidgetProperty::getAttribute(const std::string& name, short& defaultValue)
{
	const std::string& value = getAttribute(name);
	if (value.empty())
	{
		return false;
	}

	defaultValue = (short)atoi(value.c_str());

	return true;
}

bool WidgetProperty::getAttribute(const std::string& name, int& defaultValue)
{
	const std::string& value = getAttribute(name);
	if (value.empty())
	{
		return false;
	}

	defaultValue = (int)atoi(value.c_str());

	return true;
}

bool WidgetProperty::getAttribute(const std::string& name, float& defaultValue)
{
	const std::string& value = getAttribute(name);
	if (value.empty())
	{
		return false;
	}

	defaultValue = (float)atof(value.c_str());

	return true;
}

bool WidgetProperty::getAttribute(const std::string& name, double& defaultValue)
{
	const std::string& value = getAttribute(name);
	if (value.empty())
	{
		return false;
	}

	defaultValue = atof(value.c_str());

	return true;
}

bool WidgetProperty::getAttribute(const std::string& name, long& defaultValue)
{
	const std::string& value = getAttribute(name);
	if (value.empty())
	{
		return false;
	}

	defaultValue = atol(value.c_str());

	return true;
}

bool WidgetProperty::getAttribute(const std::string& name, uint8_t& defaultValue)
{
	const std::string& value = getAttribute(name);
	if (value.empty())
	{
		return false;
	}

	defaultValue = (uint8_t)atoi(value.c_str());

	return true;
}

bool WidgetProperty::getAttribute(const std::string& name, uint16_t& defaultValue)
{
	const std::string& value = getAttribute(name);
	if (value.empty())
	{
		return false;
	}

	defaultValue = (uint16_t)atoi(value.c_str());

	return true;
}

bool WidgetProperty::getAttribute(const std::string& name, uint32_t& defaultValue)
{
	const std::string& value = getAttribute(name);
	if (value.empty())
	{
		return false;
	}

	defaultValue = (uint32_t)atoi(value.c_str());

	return true;
}

bool WidgetProperty::getAttribute(const std::string& name, uint64_t& defaultValue)
{
	const std::string& value = getAttribute(name);
	if (value.empty())
	{
		return false;
	}

	defaultValue = (uint64_t)atol(value.c_str());

	return true;
}

bool WidgetProperty::getAttribute(const std::string& name, math::Vector3& defaultValue)
{
	const std::string& value = getAttribute(name);
	if (value.empty())
	{
		return false;
	}

	sys::String val = value;
	std::vector<sys::String> params;

	val.split(",", params);

	if (params.size() != 3)
	{
		return false;
	}

	defaultValue = math::Vector3(atof(params[0].getString()), atof(params[1].getString()), atof(params[2].getString()));

	return true;
}

bool WidgetProperty::getAttribute(const std::string& name, math::Vector2& defaultValue)
{
	const std::string& value = getAttribute(name);
	if (value.empty())
	{
		return false;
	}

	sys::String val = value;
	std::vector<sys::String> params;
	
	val.split(",", params);

	if (params.size() != 2)
	{
		return false;
	}

	defaultValue = math::Vector2(atof(params[0].getString()), atof(params[1].getString()));

	return true;
}

bool WidgetProperty::getAttribute(const std::string& name, sys::Color4B& defaultValue)
{
	const std::string& value = getAttribute(name);
	if (value.empty())
	{
		return false;
	}

	sys::String val = value;
	std::vector<sys::String> params;

	val.split(",", params);

	if (params.size() != 4)
	{
		return false;
	}

	defaultValue = sys::Color4B(atof(params[0].getString()), atof(params[1].getString()), atof(params[2].getString()), atof(params[3].getString()));

	return true;
}

bool WidgetProperty::getAttribute(const std::string& name, math::Size& defaultValue)
{
	const std::string& value = getAttribute(name);
	if (value.empty())
	{
		return false;
	}

	sys::String val = value;
	std::vector<sys::String> params;

	val.split(",", params);

	if (params.size() != 2)
	{
		return false;
	}

	defaultValue = math::Size(atof(params[0].getString()), atof(params[1].getString()));

	return true;
}

bool WidgetProperty::getAttribute(const std::string& name, math::Rect& defaultValue)
{
	const std::string& value = getAttribute(name);
	if (value.empty())
	{
		return false;
	}

	sys::String val = value;
	std::vector<sys::String> params;

	val.split(",", params);

	if (params.size() != 4)
	{
		return false;
	}

	defaultValue = math::Rect(atof(params[0].getString()), atof(params[1].getString()), atof(params[2].getString()), atof(params[3].getString()));

	return true;
}

bool WidgetProperty::getAttribute(const std::string& name, sys::Margin& defaultValue)
{
	const std::string& value = getAttribute(name);
	if (value.empty())
	{
		return false;
	}

	sys::String val = value;
	std::vector<sys::String> params;

	val.split(",", params);

	if (params.size() != 4)
	{
		return false;
	}

	defaultValue = sys::Margin(atof(params[0].getString()), atof(params[1].getString()), atof(params[2].getString()), atof(params[3].getString()));

	return true;
}

bool WidgetProperty::getAttribute(const std::string& name, render::BlendParam& defaultValue)
{
	const std::string& value = getAttribute(name);
	if (value.empty())
	{
		return false;
	}

	sys::String val = value;
	std::vector<sys::String> params;

	val.split(",", params);

	if (params.size() != 2)
	{
		return false;
	}

	int src = atoi(params[0].getString());
	int dest = atoi(params[1].getString());

	defaultValue = render::BlendParam((BlendingFactorSrc)src, (BlendingFactorDest)dest);

	return true;
}

bool WidgetProperty::getAttribute(const std::string& name, SizePolicy& defaultValue)
{
	const std::string& value = getAttribute(name);
	if (value.empty())
	{
		return false;
	}

	sys::String val = value;
	std::vector<sys::String> params;

	val.split(",", params);

	if (params.size() != 2)
	{
		return false;
	}

	defaultValue = SizePolicy((SizeType)atoi(params[0].getString()), (SizeType)atoi(params[1].getString()));

	return true;
}

Attributes::const_iterator WidgetProperty::getAttributeBegin()
{
	return _attributes.begin();
}

Attributes::const_iterator WidgetProperty::getAttributeEnd()
{
	return _attributes.end();
}

std::string WidgetProperty::getAttribute(const std::string& name)
{
	if (name.empty())
	{
		return "";
	}

	if (_attributes.find(name) == _attributes.end())
	{
		return "";
	}

	return _attributes[name];
}

bool ui::WidgetProperty::getAttribute(const std::string& name, sys::Color3B& defaultValue)
{
	const std::string& value = getAttribute(name);
	if (value.empty())
	{
		return false;
	}

	sys::String val = value;
	std::vector<sys::String> params;

	val.split(",", params);

	if (params.size() != 3)
	{
		return false;
	}

	defaultValue = sys::Color3B(atof(params[0].getString()), atof(params[1].getString()), atof(params[2].getString()));

	return true;
}

void ui::WidgetProperty::setAttribute(const std::string& name, const sys::Color3B& value)
{
	if (name.empty())
	{
		return;
	}
	std::string str = getCString("%d,%d,%d", value.red, value.green, value.blue);
	setAttribute(name, str);
}