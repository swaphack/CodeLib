#include "ShaderVariable.h"

#include "ShaderProgram.h"

using namespace render;

ShaderVariable::ShaderVariable()
{

}

ShaderVariable::~ShaderVariable()
{

}

void ShaderVariable::setName(const std::string& name)
{
	_name = name;
}

const std::string& ShaderVariable::getName()
{
	return _name;
}

void ShaderVariable::setProgram(ShaderProgram* program)
{
	_program = program;
}

ShaderProgram* ShaderVariable::getProgram()
{
	return _program;
}

uint32_t render::ShaderVariable::getProgramID()
{
	if (_program == nullptr)
	{
		return 0;
	}

	return _program->getProgramID();
}
