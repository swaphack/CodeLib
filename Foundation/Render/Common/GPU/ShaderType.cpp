#include "ShaderType.h"

render::ShaderType::ShaderType()
{

}

render::ShaderType::ShaderType(ShaderParamterType type, uint32_t size, const std::string& mark)
	:_type(type), _size(size), _mark(mark)
{

}

render::ShaderType::~ShaderType()
{

}

void render::ShaderType::setType(ShaderParamterType type)
{
	_type = type;
}

render::ShaderParamterType render::ShaderType::getType() const
{
	return _type;
}

void render::ShaderType::setSize(uint32_t size)
{
	_size = size;
}

uint32_t render::ShaderType::getSize() const
{
	return _size;
}

void render::ShaderType::setMark(const std::string& mark)
{
	_mark = mark;
}

const std::string& render::ShaderType::getMark() const
{
	return _mark;
}

