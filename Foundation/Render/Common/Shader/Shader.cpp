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

uint32_t Shader::getShaderID()
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

Shader* render::Shader::create(ShaderType type)
{
	switch (type)
	{
	case ShaderType::VERTEX_SHADER:
		return CREATE_OBJECT(VertexShader);
		break;
	case ShaderType::TESS_CONTROL_SHADER:
		return CREATE_OBJECT(TessControlShader);
		break;
	case ShaderType::TESS_EVALUATION_SHADER:
		return CREATE_OBJECT(TessEvaluationShader);
		break;
	case ShaderType::GEOMETRY_SHADER:
		return CREATE_OBJECT(GeometryShader);
		break;
	case ShaderType::FRAGMENT_SHADER:
		return CREATE_OBJECT(FragmentShader);
		break;
	case ShaderType::COMPUTE_SHADER:
		return CREATE_OBJECT(ComputeShader);
		break;
	default:
		return nullptr;
		break;
	}	
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
//////////////////////////////////////////////////////////////////////////
render::TessControlShader::TessControlShader()
{
	this->setShaderType(ShaderType::TESS_CONTROL_SHADER);
	this->initShader();
}

render::TessControlShader::~TessControlShader()
{

}

//////////////////////////////////////////////////////////////////////////
render::TessEvaluationShader::TessEvaluationShader()
{
	this->setShaderType(ShaderType::TESS_EVALUATION_SHADER);
	this->initShader();
}

render::TessEvaluationShader::~TessEvaluationShader()
{

}

//////////////////////////////////////////////////////////////////////////
render::ComputeShader::ComputeShader()
{
	this->setShaderType(ShaderType::COMPUTE_SHADER);
	this->initShader();
}

render::ComputeShader::~ComputeShader()
{

}
