#include "ShaderSubroutineUniform.h"
#include "ShaderProgram.h"
#include "Graphic/import.h"

using namespace render;

ShaderSubroutineUniform::ShaderSubroutineUniform()
{

}

render::ShaderSubroutineUniform::~ShaderSubroutineUniform()
{

}

void render::ShaderSubroutineUniform::setSubUniformID(uint32_t id)
{
	_subUniformID = id;
}

uint32_t render::ShaderSubroutineUniform::getSubUniformID()
{
	return _subUniformID;
}

void render::ShaderSubroutineUniform::setShaderType(ShaderType shaderType)
{
	_shaderType = shaderType;
}

ShaderType render::ShaderSubroutineUniform::getShaderType()
{
	return _shaderType;
}

uint32_t render::ShaderSubroutineUniform::getSubroutineIndex(const std::string& name)
{
	return GLShader::getSubroutineIndex(getProgramID(), _shaderType, name.c_str());
}

void render::ShaderSubroutineUniform::setSubroutineIndex(uint32_t index)
{
	int n = 0;
	GLState::getInt(GL_MAX_SUBROUTINE_UNIFORM_LOCATIONS, &n);

	uint32_t* indices = new uint32_t[n];
	GLShader::getUniformSubroutine(_shaderType, n, indices);

	indices[getSubUniformID()] = index;
	GLShader::setUniformSubroutines(_shaderType, n, indices);
	delete[] indices;
}

