#include "ShaderParameter.h"


render::ShaderParameter::ShaderParameter()
{

}

render::ShaderParameter::ShaderParameter(const std::string& name, ShaderParamterType type)
	:_name(name)
	,_type(type)
{

}

render::ShaderParameter::~ShaderParameter()
{

}

void render::ShaderParameter::setName(const std::string& name)
{
	_name = name;
}

const std::string& render::ShaderParameter::getName() const
{
	return _name;
}

void render::ShaderParameter::setType(ShaderParamterType type)
{
	_type = type;
}

render::ShaderParamterType render::ShaderParameter::getType() const
{
	return _type;
}

void render::ShaderParameter::setValue(uint32_t len, const char* value)
{
	_value.init(len, value);
}

const char* render::ShaderParameter::getValue() const
{
	return _value.getValue();
}

