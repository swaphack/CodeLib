#include "ShaderVariable.h"

#include "ShaderProgram.h"

using namespace render;

ShaderVariable::ShaderVariable()
{

}

ShaderVariable::~ShaderVariable()
{

}

void ShaderVariable::setVarID(uint32_t id)
{
	_varID = id;
}

uint32_t ShaderVariable::getVarID()
{
	return _varID;
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
