#include "Shader.h"
#include "ext-config.h"
#include "ShaderProgram.h"
#include "Graphic/import.h"
#include "system.h"

using namespace render;

Shader::Shader()
{
}

Shader::~Shader()
{
	this->releaseShader();
}

uint32_t Shader::getShaderID() const
{
	return _shaderID;
}

ShaderType Shader::getShaderType() const
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

bool Shader::loadData(const char* data)
{
	if (data == nullptr)
	{
		return false;
	}

	GLShader::setShaderSource(_shaderID, 1, &data, nullptr);
	GLDebug::showError();
	GLShader::compileShader(_shaderID);
	GLDebug::showError();
	int compiled = 0;
	GLShader::getShader(_shaderID, ShaderParameter::COMPILE_STATUS, &compiled);
	if (compiled != GL_TRUE)
	{
		GLShader::showShaderError(_shaderID);
		return false;
	}

	return true;
}

bool Shader::loadFromFile(const std::string& filepath)
{
	PRINT("INFO : Load Shader From File [%s]\n", filepath.c_str());

	std::string data;
	if (!G_FILEPATH->getFileData(filepath, data))
	{
		return false;
	}

	return this->loadData(data.c_str());
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

render::Shader* render::Shader::create(ShaderType type, const std::string& filepath)
{
	auto pShader = Shader::create(type);
	if (pShader == nullptr)
	{
		return nullptr;
	}

	if (!pShader->loadFromFile(filepath))
	{
		SAFE_DELETE(pShader);
	}

	return pShader;
}

bool render::Shader::loadFromBindary(const void* binary, int length)
{
	return false; 
	//GLShader::setShaderBinary(1, &_shaderID, GL_SHADER_BINARY_FORMAT_SPIR_V, binary, length);
}

bool render::Shader::isValid() const
{
	return GLShader::isShader(_shaderID);
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
