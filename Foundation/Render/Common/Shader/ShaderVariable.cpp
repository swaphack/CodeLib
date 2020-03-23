#include "ShaderVariable.h"

#include "ShaderProgram.h"

using namespace render;

ShaderVariable::ShaderVariable()
{

}

ShaderVariable::~ShaderVariable()
{

}

void ShaderVariable::setVarID(int id)
{
	_varID = id;
}

int ShaderVariable::getVarID()
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
