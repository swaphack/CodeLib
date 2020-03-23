#include "ShaderProgram.h"
#include "Shader.h"
#include "ShaderAttrib.h"
#include "ShaderUniform.h"
#include "ext-config.h"

using namespace render;


ShaderProgram::ShaderProgram()
{
	this->initProgram();
}

ShaderProgram::~ShaderProgram()
{
	this->releaseProgram();
}

int ShaderProgram::getProgramID()
{
	return _programID;
}

void ShaderProgram::attachShader(Shader* shader)
{
	if (shader == nullptr)
	{
		return;
	}

	this->detachShader(shader);

	SAFE_RETAIN(shader);
	_shaders[shader->getShaderID()] = shader;
	shader->attachProgram(this);
}

void ShaderProgram::detachShader(Shader* shader)
{
	if (shader == nullptr)
	{
		return;
	}
	
	auto it = _shaders.find(shader->getShaderID());
	if (it != _shaders.end())
	{
		_shaders.erase(it);
		shader->detachProgram();
		SAFE_RELEASE(shader);
	}
}

void ShaderProgram::detachAllShaders()
{
	for (auto item : _shaders)
	{
		glDetachShader(_programID, item.first);
		SAFE_RELEASE(item.second);
	}

	_shaders.clear();
}

void ShaderProgram::initProgram()
{
	_programID = glCreateProgram();
}

void ShaderProgram::link()
{
	glLinkProgram(_programID);
}

void ShaderProgram::use()
{
	glUseProgram(_programID);
}

void ShaderProgram::releaseProgram()
{
	detachAllShaders();
	removeAllAttributes();
	removeAllUniforms();

	if (_programID != 0)
	{
		glDeleteProgram(_programID);
		_programID = 0;
	}
}

ShaderAttrib* ShaderProgram::getAttriubte(const std::string& name)
{
	auto it = _attributes.find(name);
	if (it != _attributes.end())
	{
		return it->second;
	}

	GLint id = glGetAttribLocation(_programID, name.c_str());
	if (id <= 0)
	{
		return nullptr;
	}

	auto pAtt = CREATE_OBJECT(ShaderAttrib);
	pAtt->setVarID(id);
	pAtt->setName(name);
	pAtt->setProgram(this);
	this->addAttriubte(name, pAtt);

	return pAtt;
}

void ShaderProgram::removeAllAttributes()
{
	for (auto item : _attributes)
	{
		SAFE_RELEASE(item.second);
	}
	_attributes.clear();
}

void ShaderProgram::addAttriubte(const std::string& name, ShaderAttrib* attrib)
{
	if (name.empty() || attrib == nullptr)
	{
		return;
	}
	SAFE_RETAIN(attrib);
	_attributes[name] = attrib;
}

void ShaderProgram::showLog()
{
	GLint state;
	glGetProgramiv(_programID, GL_LINK_STATUS, &state);
	if (state == GL_TRUE)
	{
		return;
	}
	GLsizei bufferSize = 0;
	glGetProgramiv(_programID, GL_INFO_LOG_LENGTH, &bufferSize);
	if (bufferSize > 0)
	{
		GLchar* buffer = new char[bufferSize];
		glGetProgramInfoLog(_programID, bufferSize, NULL, buffer);
		PRINT("%s", buffer);
		delete[] buffer;
	}
}

ShaderUniform* ShaderProgram::getUniform(const std::string& name)
{
	auto it = _uniforms.find(name);
	if (it != _uniforms.end())
	{
		return it->second;
	}

	GLint id = glGetUniformLocation(_programID, name.c_str());
	if (id <= 0)
	{
		return nullptr;
	}

	auto pUniform = CREATE_OBJECT(ShaderUniform);
	pUniform->setVarID(id);
	pUniform->setName(name);
	pUniform->setProgram(this);
	this->addUniform(name, pUniform);

	return pUniform;
}

void ShaderProgram::addUniform(const std::string& name, ShaderUniform* uniform)
{
	if (name.empty() || uniform == nullptr)
	{
		return;
	}
	SAFE_RETAIN(uniform);
	_uniforms[name] = uniform;
}

void ShaderProgram::removeAllUniforms()
{
	for (auto item : _attributes)
	{
		SAFE_RELEASE(item.second);
	}
	_attributes.clear();
}

void ShaderProgram::load(const std::string& vpath, const std::string& fpath)
{
	VertexShader* pVertex = CREATE_OBJECT(VertexShader);
	pVertex->loadFromFile(vpath);
	this->attachShader(pVertex);

	FragmentShader* pFragment = CREATE_OBJECT(FragmentShader);
	pFragment->loadFromFile(fpath);
	this->attachShader(pFragment);
}

void ShaderProgram::useNone()
{
	//glUseProgram(0);
}
