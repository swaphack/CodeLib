#include "ShaderProgram.h"
#include "Shader.h"
#include "ShaderAttrib.h"
#include "ShaderUniform.h"
#include "ShaderUniformBlock.h"
#include "ShaderSubroutineUniform.h"
#include "Graphic/import.h"

using namespace render;


ShaderProgram::ShaderProgram()
{
	this->initProgram();
}

ShaderProgram::~ShaderProgram()
{
	this->releaseProgram();
}

uint32_t ShaderProgram::getProgramID()
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
		item.second->detachProgram();
		SAFE_RELEASE(item.second);
	}

	_shaders.clear();
}

void ShaderProgram::initProgram()
{
	_programID = GLShader::createProgram();
}

void ShaderProgram::link()
{
	GLShader::linkProgram(_programID);
}

void ShaderProgram::use()
{
	GLShader::useProgram(_programID);
}

void ShaderProgram::useNone()
{
	//GLShader::useProgram(0);
}

void ShaderProgram::releaseProgram()
{
	detachAllShaders();
	removeAllAttributes();
	removeAllUniforms();
	removeAllUniformBlocks();
	removeAllSubroutineUniforms();

	if (_programID != 0)
	{
		GLShader::deleteProgram(_programID);
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

	int32_t id = GLShader::getAttribLocation(_programID, name.c_str());
	GLDebug::showError();
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

ShaderUniform* ShaderProgram::getUniform(const std::string& name)
{
	auto it = _uniforms.find(name);
	if (it != _uniforms.end())
	{
		return it->second;
	}

	int id = GLShader::getUniformLocation(_programID, name.c_str());
	GLDebug::showError();
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

void ShaderProgram::loadVertexAndFragmentShader(const std::string& vpath, const std::string& fpath)
{
	this->loadFromFile<VertexShader>(vpath);
	this->loadFromFile<FragmentShader>(fpath);
}

void render::ShaderProgram::loadFromFile(ShaderType type, const std::string& path)
{
	Shader* pVertex = Shader::create(type);
	pVertex->loadFromFile(path);
	this->attachShader(pVertex);
}

render::ShaderUniformBlock* render::ShaderProgram::getUniformBlock(const std::string& name)
{
	auto it = _uniformBlocks.find(name);
	if (it != _uniformBlocks.end())
	{
		return it->second;
	}

	uint32_t id = GLShader::getUniformBlockIndex(_programID, name.c_str());
	GLDebug::showError();
	auto pUniformBlock = CREATE_OBJECT(ShaderUniformBlock);
	pUniformBlock->setVarID(id);
	pUniformBlock->setName(name);
	pUniformBlock->setProgram(this);
	this->addUniformBlock(name, pUniformBlock);

	return pUniformBlock;
}

void render::ShaderProgram::addUniformBlock(const std::string& name, ShaderUniformBlock* uniform)
{
	if (name.empty() || uniform == nullptr)
	{
		return;
	}
	SAFE_RETAIN(uniform);
	_uniformBlocks[name] = uniform;
}

void render::ShaderProgram::removeAllUniformBlocks()
{
	for (auto item : _uniformBlocks)
	{
		SAFE_RELEASE(item.second);
	}
	_uniformBlocks.clear();
}

ShaderSubroutineUniform* render::ShaderProgram::getSubroutineUniform(ShaderType shaderType, const std::string& name)
{
	auto it = _subroutineUniforms.find(name);
	if (it != _subroutineUniforms.end())
	{
		return it->second;
	}

	uint32_t id = GLShader::getSubroutineUniformLocation(_programID, shaderType, name.c_str());
	GLDebug::showError();
	auto pSubroutineUniform = CREATE_OBJECT(ShaderSubroutineUniform);
	pSubroutineUniform->setVarID(id);
	pSubroutineUniform->setName(name);
	pSubroutineUniform->setShaderType(shaderType);
	pSubroutineUniform->setProgram(this);
	this->addSubroutineUniform(name, pSubroutineUniform);

	return pSubroutineUniform;
}

void render::ShaderProgram::addSubroutineUniform(const std::string& name, ShaderSubroutineUniform* uniform)
{
	if (name.empty() || uniform == nullptr)
	{
		return;
	}
	SAFE_RETAIN(uniform);
	_subroutineUniforms[name] = uniform;
}

void render::ShaderProgram::removeAllSubroutineUniforms()
{
	for (auto item : _subroutineUniforms)
	{
		SAFE_RELEASE(item.second);
	}
	_subroutineUniforms.clear();
}


