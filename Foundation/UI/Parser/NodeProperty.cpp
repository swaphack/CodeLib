#include "NodeProperty.h"

using namespace ui;


NodeProperty::NodeProperty()
{
	_name = "";
}

NodeProperty::~NodeProperty()
{

}

void NodeProperty::Clear()
{
	_attributes.clear();
}

void NodeProperty::setAttribute(const char* name, bool value)
{
	int val = value ? 1 : 0;
	this->setAttribute(name, val);
}

void NodeProperty::setAttribute(const char* name, const char* value)
{
	if (name && value)
	{
		_attributes[name] = value;
	}
}

void NodeProperty::setAttribute(const char* name, char value)
{
	if (name == nullptr)
	{
		return;
	}

	setAttribute(name, getCString("%d", value));
}

void NodeProperty::setAttribute(const char* name, short value)
{
	if (name == nullptr)
	{
		return;
	}

	setAttribute(name, getCString("%d", value));
}

void NodeProperty::setAttribute(const char* name, int value)
{
	if (name == nullptr)
	{
		return;
	}

	setAttribute(name, getCString("%d", value));
}

void NodeProperty::setAttribute(const char* name, float value)
{
	if (name == nullptr)
	{
		return;
	}

	setAttribute(name, getCString("%f", value));
}

void NodeProperty::setAttribute(const char* name, double value)
{
	if (name == nullptr)
	{
		return;
	}

	setAttribute(name, getCString("%lf", value));
}

void NodeProperty::setAttribute(const char* name, long value)
{
	if (name == nullptr)
	{
		return;
	}

	setAttribute(name, getCString("%ld", value));
}

void NodeProperty::setAttribute(const char* name, uchar value)
{
	if (name == nullptr)
	{
		return;
	}

	setAttribute(name, getCString("%u", value));
}

void NodeProperty::setAttribute(const char* name, ushort value)
{
	if (name == nullptr)
	{
		return;
	}

	setAttribute(name, getCString("%u", value));
}

void NodeProperty::setAttribute(const char* name, uint value)
{
	if (name == nullptr)
	{
		return;
	}

	setAttribute(name, getCString("%u", value));
}

void NodeProperty::setAttribute(const char* name, ulong value)
{
	if (name == nullptr)
	{
		return;
	}

	setAttribute(name, getCString("%lu", value));
}

void NodeProperty::setAttribute(const char* name, const sys::Vector& value)
{
	if (name == nullptr)
	{
		return;
	}

	setAttribute(name, getCString("%f,%f,%f", value.x, value.y, value.z));
}

void NodeProperty::setAttribute(const char* name, const sys::Point& value)
{
	if (name == nullptr)
	{
		return;
	}

	setAttribute(name, getCString("%f,%f", value.x, value.y));
}

void NodeProperty::setAttribute(const char* name, const sys::Color4B& value)
{
	if (name == nullptr)
	{
		return;
	}

	setAttribute(name, getCString("%d,%d,%d,%d", value.red, value.green, value.blue, value.alpha));
}

void NodeProperty::setAttribute(const char* name, const sys::Size& value)
{
	if (name == nullptr)
	{
		return;
	}

	setAttribute(name, getCString("%f,%f", value.width, value.height));
}

void NodeProperty::setAttribute(const char* name, const sys::Rect& value)
{
	if (name == nullptr)
	{
		return;
	}

	setAttribute(name, getCString("%d,%d,%d,%d", value.x, value.y, value.width, value.height));
}

bool NodeProperty::getAttribute(const char* name, bool& defaultValue)
{
	int value = 0;
	if (!getAttribute(name, value))
	{
		return false;
	}

	defaultValue = value == 0 ? false: true;

	return true;
}

bool NodeProperty::getAttribute(const char* name, std::string& defaultValue)
{
	const char* value = getAttribute(name);
	if (value == nullptr)
	{
		return false;
	}

	defaultValue = value;

	return true;
}

bool NodeProperty::getAttribute(const char* name, char& defaultValue)
{
	const char* value = getAttribute(name);
	if (value == nullptr)
	{
		return false;
	}
	
	defaultValue = (char)atoi(value);

	return true;
}

bool NodeProperty::getAttribute(const char* name, short& defaultValue)
{
	const char* value = getAttribute(name);
	if (value == nullptr)
	{
		return false;
	}

	defaultValue = (short)atoi(value);

	return true;
}

bool NodeProperty::getAttribute(const char* name, int& defaultValue)
{
	const char* value = getAttribute(name);
	if (value == nullptr)
	{
		return false;
	}

	defaultValue = (int)atoi(value);

	return true;
}

bool NodeProperty::getAttribute(const char* name, float& defaultValue)
{
	const char* value = getAttribute(name);
	if (value == nullptr)
	{
		return false;
	}

	defaultValue = (float)atof(value);

	return true;
}

bool NodeProperty::getAttribute(const char* name, double& defaultValue)
{
	const char* value = getAttribute(name);
	if (value == nullptr)
	{
		return false;
	}

	defaultValue = atof(value);

	return true;
}

bool NodeProperty::getAttribute(const char* name, long& defaultValue)
{
	const char* value = getAttribute(name);
	if (value == nullptr)
	{
		return false;
	}

	defaultValue = atol(value);

	return true;
}

bool NodeProperty::getAttribute(const char* name, uchar& defaultValue)
{
	const char* value = getAttribute(name);
	if (value == nullptr)
	{
		return false;
	}

	defaultValue = (uchar)atoi(value);

	return true;
}

bool NodeProperty::getAttribute(const char* name, ushort& defaultValue)
{
	const char* value = getAttribute(name);
	if (value == nullptr)
	{
		return false;
	}

	defaultValue = (ushort)atoi(value);

	return true;
}

bool NodeProperty::getAttribute(const char* name, uint& defaultValue)
{
	const char* value = getAttribute(name);
	if (value == nullptr)
	{
		return false;
	}

	defaultValue = (uint)atoi(value);

	return true;
}

bool NodeProperty::getAttribute(const char* name, ulong& defaultValue)
{
	const char* value = getAttribute(name);
	if (value == nullptr)
	{
		return false;
	}

	defaultValue = (ulong)atol(value);

	return true;
}

bool NodeProperty::getAttribute(const char* name, sys::Vector& defaultValue)
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

	defaultValue = sys::Vector(atof(params[0].getString()), atof(params[1].getString()), atof(params[2].getString()));

	return true;
}

bool NodeProperty::getAttribute(const char* name, sys::Point& defaultValue)
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

	defaultValue = sys::Point(atof(params[0].getString()), atof(params[1].getString()));

	return true;
}

bool NodeProperty::getAttribute(const char* name, sys::Color4B& defaultValue)
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

bool NodeProperty::getAttribute(const char* name, sys::Size& defaultValue)
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

	defaultValue = sys::Size(atof(params[0].getString()), atof(params[1].getString()));

	return true;
}

bool NodeProperty::getAttribute(const char* name, sys::Rect& defaultValue)
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

	defaultValue = sys::Rect(atof(params[0].getString()), atof(params[1].getString()), atof(params[2].getString()), atof(params[3].getString()));

	return true;
}

Attributes::const_iterator NodeProperty::getAttributeFirst()
{
	return _attributes.begin();
}

Attributes::const_iterator NodeProperty::getAttributeEnd()
{
	return _attributes.end();
}

const char* NodeProperty::getAttribute(const char* name)
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