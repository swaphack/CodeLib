#include "Shader.h"
#include "ext-config.h"
#include "ShaderProgram.h"

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

int Shader::getShaderType()
{
	return _shaderType;
}

void Shader::setShaderType(int shaderType)
{
	_shaderType = shaderType;
}

void Shader::initShader()
{
	if (_shaderID != 0)
	{
		return;
	}
	_shaderID = glCreateShader(_shaderType);
}

void Shader::releaseShader()
{
	detachProgram();
	glDeleteShader (_shaderID);
	_shaderID = 0;
}

void Shader::loadData(const char* data)
{
	if (data == nullptr)
	{
		return;
	}
	glShaderSource(_shaderID, 1, &data, nullptr);
	glCompileShader(_shaderID);
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

void Shader::showLog()
{
	GLint state;
	glGetShaderiv(_shaderID, GL_COMPILE_STATUS, &state);
	if (state == GL_TRUE)
	{
		return;
	}
	GLsizei bufferSize = 0;
	glGetShaderiv(_shaderID, GL_INFO_LOG_LENGTH, &bufferSize);
	if (bufferSize > 0)
	{
		GLchar* buffer = new char[bufferSize];
		glGetShaderInfoLog(_shaderID, bufferSize, NULL, buffer);
		PRINT("%s", buffer);
		delete[] buffer;
	}
}

void Shader::attachProgram(ShaderProgram* program)
{
	_program = program;
	if (!_program)
	{
		return;
	}

	glAttachShader(_program->getProgramID(), _shaderID);
}

void Shader::detachProgram()
{
	if (!_program)
	{
		return;
	}
	glDetachShader(_program->getProgramID(), _shaderID);
	_program = nullptr;
}

//////////////////////////////////////////////////////////////////////////

VertexShader::VertexShader()
{
	this->setShaderType(GL_VERTEX_SHADER);
	this->initShader();
}

VertexShader::~VertexShader()
{

}

//////////////////////////////////////////////////////////////////////////
FragmentShader::FragmentShader()
{
	this->setShaderType(GL_FRAGMENT_SHADER);
	this->initShader();
}

FragmentShader::~FragmentShader()
{

}
//////////////////////////////////////////////////////////////////////////
render::GeometryShader::GeometryShader()
{
	this->setShaderType(GL_GEOMETRY_SHADER);
	this->initShader();
}

render::GeometryShader::~GeometryShader()
{

}
