#include "ShaderVariableType.h"

render::ShaderVariableType::ShaderVariableType()
{

}

render::ShaderVariableType::ShaderVariableType(ShaderParamterType type, uint32_t size, const std::string& mark)
	:_type(type), _size(size), _mark(mark)
{

}

render::ShaderVariableType::~ShaderVariableType()
{

}

void render::ShaderVariableType::setType(ShaderParamterType type)
{
	_type = type;
}

render::ShaderParamterType render::ShaderVariableType::getType() const
{
	return _type;
}

void render::ShaderVariableType::setSize(uint32_t size)
{
	_size = size;
}

uint32_t render::ShaderVariableType::getSize() const
{
	return _size;
}

void render::ShaderVariableType::setMark(const std::string& mark)
{
	_mark = mark;
}

const std::string& render::ShaderVariableType::getMark() const
{
	return _mark;
}

