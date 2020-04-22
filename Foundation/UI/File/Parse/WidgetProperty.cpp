#include "WidgetProperty.h"
#include "ui_common.h"
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

void WidgetProperty::setAttribute(const char* name, bool value)
{
	int val = value ? 1 : 0;
	this->setAttribute(name, val);
}

void WidgetProperty::setAttribute(const char* name, const char* value)
{
	if (name && value != nullptr)
	{
		_attributes[name] = value;
	}
}

void WidgetProperty::setAttribute(const char* name, const std::string& value)
{
	if (name && !value.empty())
	{
		_attributes[name] = value;
	}
}

void WidgetProperty::setAttribute(const char* name, char value)
{
	if (name == nullptr)
	{
		return;
	}

	setAttribute(name, getCString("%d", value));
}

void WidgetProperty::setAttribute(const char* name, short value)
{
	if (name == nullptr)
	{
		return;
	}

	setAttribute(name, getCString("%d", value));
}

void WidgetProperty::setAttribute(const char* name, int value)
{
	if (name == nullptr)
	{
		return;
	}

	setAttribute(name, getCString("%d", value));
}

void WidgetProperty::setAttribute(const char* name, float value)
{
	if (name == nullptr)
	{
		return;
	}

	setAttribute(name, getCString("%f", value));
}

void WidgetProperty::setAttribute(const char* name, double value)
{
	if (name == nullptr)
	{
		return;
	}

	setAttribute(name, getCString("%lf", value));
}

void WidgetProperty::setAttribute(const char* name, long value)
{
	if (name == nullptr)
	{
		return;
	}

	setAttribute(name, getCString("%ld", value));
}

void WidgetProperty::setAttribute(const char* name, uint8_t value)
{
	if (name == nullptr)
	{
		return;
	}

	setAttribute(name, getCString("%u", value));
}

void WidgetProperty::setAttribute(const char* name, uint16_t value)
{
	if (name == nullptr)
	{
		return;
	}

	setAttribute(name, getCString("%u", value));
}

void WidgetProperty::setAttribute(const char* name, uint32_t value)
{
	if (name == nullptr)
	{
		return;
	}

	setAttribute(name, getCString("%u", value));
}

void WidgetProperty::setAttribute(const char* name, uint64_t value)
{
	if (name == nullptr)
	{
		return;
	}

	setAttribute(name, getCString("%lu", value));
}

void WidgetProperty::setAttribute(const char* name, const math::Vector3& value)
{
	if (name == nullptr)
	{
		return;
	}

	setAttribute(name, getCString("%f,%f,%f", value.getX(), value.getY(), value.getZ()));
}

void WidgetProperty::setAttribute(const char* name, const math::Vector2& value)
{
	if (name == nullptr)
	{
		return;
	}

	setAttribute(name, getCString("%f,%f", value.getX(), value.getY()));
}

void WidgetProperty::setAttribute(const char* name, const sys::Color4B& value)
{
	if (name == nullptr)
	{
		return;
	}

	setAttribute(name, getCString("%d,%d,%d,%d", value.red, value.green, value.blue, value.alpha));
}

void WidgetProperty::setAttribute(const char* name, const math::Size& value)
{
	if (name == nullptr)
	{
		return;
	}

	setAttribute(name, getCString("%f,%f", value.getWidth(), value.getHeight()));
}

void WidgetProperty::setAttribute(const char* name, const math::Rect& value)
{
	if (name == nullptr)
	{
		return;
	}

	setAttribute(name, getCString("%f,%f,%f,%f", value.getX(), value.getY(), value.getWidth(), value.getHeight()));
}

void WidgetProperty::setAttribute(const char* name, const render::BlendParam& value)
{
	if (name == nullptr)
	{
		return;
	}

	setAttribute(name, getCString("%d,%d", value.src, value.dest));
}

void WidgetProperty::setAttribute(const char* name, const sys::Margin& value)
{
	if (name == nullptr)
	{
		return;
	}

	setAttribute(name, getCString("%f,%f,%f,%f", value.left, value.right, value.bottom, value.top));
}

void WidgetProperty::setAttribute(const char* name, const SizePolicy& value)
{
	if (name == nullptr)
	{
		return;
	}

	setAttribute(name, getCString("%d,%d", value.width, value.height));
}

bool WidgetProperty::getAttribute(const char* name, bool& defaultValue)
{
	int value = 0;
	if (!getAttribute(name, value))
	{
		return false;
	}

	defaultValue = value == 0 ? false: true;

	return true;
}

bool WidgetProperty::getAttribute(const char* name, std::string& defaultValue)
{
	const char* value = getAttribute(name);
	if (value == nullptr)
	{
		return false;
	}

	defaultValue = value;

	return true;
}

bool WidgetProperty::getAttribute(const char* name, char& defaultValue)
{
	const char* value = getAttribute(name);
	if (value == nullptr)
	{
		return false;
	}
	
	defaultValue = (char)atoi(value);

	return true;
}

bool WidgetProperty::getAttribute(const char* name, short& defaultValue)
{
	const char* value = getAttribute(name);
	if (value == nullptr)
	{
		return false;
	}

	defaultValue = (short)atoi(value);

	return true;
}

bool WidgetProperty::getAttribute(const char* name, int& defaultValue)
{
	const char* value = getAttribute(name);
	if (value == nullptr)
	{
		return false;
	}

	defaultValue = (int)atoi(value);

	return true;
}

bool WidgetProperty::getAttribute(const char* name, float& defaultValue)
{
	const char* value = getAttribute(name);
	if (value == nullptr)
	{
		return false;
	}

	defaultValue = (float)atof(value);

	return true;
}

bool WidgetProperty::getAttribute(const char* name, double& defaultValue)
{
	const char* value = getAttribute(name);
	if (value == nullptr)
	{
		return false;
	}

	defaultValue = atof(value);

	return true;
}

bool WidgetProperty::getAttribute(const char* name, long& defaultValue)
{
	const char* value = getAttribute(name);
	if (value == nullptr)
	{
		return false;
	}

	defaultValue = atol(value);

	return true;
}

bool WidgetProperty::getAttribute(const char* name, uint8_t& defaultValue)
{
	const char* value = getAttribute(name);
	if (value == nullptr)
	{
		return false;
	}

	defaultValue = (uint8_t)atoi(value);

	return true;
}

bool WidgetProperty::getAttribute(const char* name, uint16_t& defaultValue)
{
	const char* value = getAttribute(name);
	if (value == nullptr)
	{
		return false;
	}

	defaultValue = (uint16_t)atoi(value);

	return true;
}

bool WidgetProperty::getAttribute(const char* name, uint32_t& defaultValue)
{
	const char* value = getAttribute(name);
	if (value == nullptr)
	{
		return false;
	}

	defaultValue = (uint32_t)atoi(value);

	return true;
}

bool WidgetProperty::getAttribute(const char* name, uint64_t& defaultValue)
{
	const char* value = getAttribute(name);
	if (value == nullptr)
	{
		return false;
	}

	defaultValue = (uint64_t)atol(value);

	return true;
}

bool WidgetProperty::getAttribute(const char* name, math::Vector3& defaultValue)
{
	const char* value = getAttribute(name);
	if (value == nullptr)
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

bool WidgetProperty::getAttribute(const char* name, math::Vector2& defaultValue)
{
	const char* value = getAttribute(name);
	if (value == nullptr)
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

bool WidgetProperty::getAttribute(const char* name, sys::Color4B& defaultValue)
{
	const char* value = getAttribute(name);
	if (value == nullptr)
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

bool WidgetProperty::getAttribute(const char* name, math::Size& defaultValue)
{
	const char* value = getAttribute(name);
	if (value == nullptr)
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

bool WidgetProperty::getAttribute(const char* name, math::Rect& defaultValue)
{
	const char* value = getAttribute(name);
	if (value == nullptr)
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

bool WidgetProperty::getAttribute(const char* name, sys::Margin& defaultValue)
{
	const char* value = getAttribute(name);
	if (value == nullptr)
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

bool WidgetProperty::getAttribute(const char* name, render::BlendParam& defaultValue)
{
	const char* value = getAttribute(name);
	if (value == nullptr)
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

bool WidgetProperty::getAttribute(const char* name, SizePolicy& defaultValue)
{
	const char* value = getAttribute(name);
	if (value == nullptr)
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

const char* WidgetProperty::getAttribute(const char* name)
{

	if (name == nullptr)
	{
		return nullptr;
	}

	if (_attributes.find(name) == _attributes.end())
	{
		return nullptr;
	}

	return _attributes[name].c_str();
}
