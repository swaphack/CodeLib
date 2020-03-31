#include "Shader.h"
#include "ext-config.h"
#include "ShaderProgram.h"
#include "Graphic/GLAPI/GLShader.h"


using namespace render;

Shader::Shader()
{
}

Shader::~Shader()
{
	this->releaseShader();
}

int Shader::getShaderID()
{
	return _shaderID;
}

ShaderType Shader::getShaderType()
{
	return _shaderType;
}

void Shader::setShaderType(ShaderType shaderType)
{
	_shaderType = shaderType;
}

void Shader::initShader()
{
	if (_shaderID != 0)
	{
		return;
	}
	_shaderID = GLShader::createShader(_shaderType);
}

void Shader::releaseShader()
{
	detachProgram();
	GLShader::deleteShader(_shaderID);
	_shaderID = 0;
}

void Shader::loadData(const char* data)
{
	if (data == nullptr)
	{
		return;
	}

	GLShader::loadShader(_shaderID, data);
}

void Shader::loadFromFile(const std::string& filepath)
{
	std::string data;
	if (!G_FILEPATH->getFileData(filepath, data))
	{
		return;
	}

	this->loadData(data.c_str());
}

void Shader::attachProgram(ShaderProgram* program)
{
	_program = program;
	if (!_program)
	{
		return;
	}

	GLShader::attachShader(_program->getProgramID(), _shaderID);
}

void Shader::detachProgram()
{
	if (!_program)
	{
		return;
	}
	GLShader::detachShader(_program->getProgramID(), _shaderID);
	_program = nullptr;
}

//////////////////////////////////////////////////////////////////////////

VertexShader::VertexShader()
{
	this->setShaderType(ShaderType::VERTEX_SHADER);
	this->initShader();
}

VertexShader::~VertexShader()
{

}

//////////////////////////////////////////////////////////////////////////
FragmentShader::FragmentShader()
{
	this->setShaderType(ShaderType::FRAGMENT_SHADER);
	this->initShader();
}

FragmentShader::~FragmentShader()
{

}
//////////////////////////////////////////////////////////////////////////
render::GeometryShader::GeometryShader()
{
	this->setShaderType(ShaderType::GEOMETRY_SHADER);
	this->initShader();
}

render::GeometryShader::~GeometryShader()
{

}
