#include "ShaderProgram.h"
#include "Shader.h"
#include "ShaderAttrib.h"
#include "ShaderUniform.h"
#include "ShaderUniformBlock.h"
#include "ShaderSubroutineUniform.h"
#include "Graphic/import.h"
#include "ShaderProgramPipeline.h"
#include "ShaderProgramUniform.h"
#include "Common/VAO/VertexArrayObject.h"
#include "Common/VAO/VertexArrayBufferObject.h"

using namespace render;


ShaderProgram::ShaderProgram()
{
	this->initProgram();
}

ShaderProgram::~ShaderProgram()
{
	this->releaseProgram();
}

uint32_t ShaderProgram::getProgramID() const
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

bool ShaderProgram::link()
{
	GLShader::linkProgram(_programID);
	GLDebug::showError();

	int nStatus = 0;
	GLShader::getProgram(_programID, GetProgramParameter::LINK_STATUS, &nStatus);
	bool ret = nStatus == GL_TRUE;
	if (!ret)
	{
		PRINT("Link Program Error:\n");
		GLShader::showProgramError(_programID);
	}

	detachAllShaders();

	GLDebug::showError();

	return ret;
}

void ShaderProgram::use()
{
	GLShader::useProgram(_programID);
	GLShader::showProgramError(_programID);
	GLDebug::showError();
}

void ShaderProgram::unuse()
{
	GLShader::useProgram(0);
}

void ShaderProgram::releaseProgram()
{
	detachAllShaders();
	removeAllAttribs();
	removeAllUniforms();
	removeAllUniformBlocks();
	removeAllSubroutineUniforms();
	removeAllProgramPipelines();
	removeAllProgramUniforms();

	if (_programID != 0)
	{
		GLShader::deleteProgram(_programID);
		_programID = 0;
	}
}

void render::ShaderProgram::bindAttrib(uint32_t index, const std::string& name)
{
	GLShader::bindAttributeLocation(_programID, index, name.c_str());
}

ShaderAttrib* ShaderProgram::getAttrib(const std::string& name)
{
	auto it = _attributes.find(name);
	if (it != _attributes.end())
	{
		return it->second;
	}

	int32_t id = GLShader::getAttribLocation(_programID, name.c_str());
	if (id < 0)
	{
		return nullptr;
	}

	auto pAtt = CREATE_OBJECT(ShaderAttrib);
	pAtt->setAttribID(id);
	pAtt->setName(name);
	pAtt->setProgram(this);
	this->addAttrib(name, pAtt);

	return pAtt;
}

void ShaderProgram::removeAllAttribs()
{
	for (auto item : _attributes)
	{
		SAFE_RELEASE(item.second);
	}
	_attributes.clear();
}

void ShaderProgram::addAttrib(const std::string& name, ShaderAttrib* attrib)
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
	if (id < 0)
	{
		return nullptr;
	}

	auto pUniform = CREATE_OBJECT(ShaderUniform);
	pUniform->setUniformID(id);
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

void render::ShaderProgram::bindFragDataLocation(uint32_t colorNumber, const char* name)
{
	GLShader::bindFragDataLocation(getProgramID(), colorNumber, name);
}

void render::ShaderProgram::bindFragDataLocationIndexed(uint32_t colorNumber, uint32_t index, const char* name)
{
	GLShader::bindFragDataLocationIndexed(getProgramID(), colorNumber, index, name);
}

bool render::ShaderProgram::isValid() const
{
	return GLShader::isProgram(_programID);
}

bool render::ShaderProgram::validate()
{
	GLShader::validateProgram(_programID);
	int status = GL_TRUE;
	GLShader::getProgram(_programID, GetProgramParameter::VALIDATE_STATUS, &status);
	if (status != GL_TRUE)
	{
		GLShader::showProgramError(_programID);
	}

	return status == GL_TRUE;
}

bool render::ShaderProgram::loadShaderFromFile(ShaderType type, const std::string& path)
{
	Shader* pShader = Shader::createFromFile(type, path);
	if (pShader == nullptr)
	{
		return false;
	}
	this->attachShader(pShader);
	GLDebug::showError();
	return true;
}

void render::ShaderProgram::setSeparable(bool value)
{
	GLShader::setProgramParameter(_programID, ModifyProgramParameter::PROGRAM_SEPARABLE, value ? GL_TRUE : GL_FALSE);
}

render::ShaderProgramPipeline* render::ShaderProgram::getShaderProgramPipeline(uint32_t tags, const std::string& name)
{
	auto it = _programPipelines.find(name);
	if (it != _programPipelines.end())
	{
		return it->second;
	}
	auto pProgramPipeline = CREATE_OBJECT(ShaderProgramPipeline);
	pProgramPipeline->setName(name);
	pProgramPipeline->setProgram(this);
	pProgramPipeline->bind();
	this->addShaderProgramPipeline(name, pProgramPipeline);

	GLShader::useProgramStages(pProgramPipeline->getProgramPipelineID(), tags, _programID);

	return pProgramPipeline;
}

void render::ShaderProgram::addShaderProgramPipeline(const std::string& name, ShaderProgramPipeline* pipeline)
{
	if (name.empty() || pipeline == nullptr)
	{
		return;
	}
	SAFE_RETAIN(pipeline);
	_programPipelines[name] = pipeline;
}

void render::ShaderProgram::removeAllProgramPipelines()
{
	for (auto item : _subroutineUniforms)
	{
		SAFE_RELEASE(item.second);
	}
	_subroutineUniforms.clear();
}

render::ShaderProgramUniform* render::ShaderProgram::getProgramUniform(const std::string& name)
{
	auto it = _programUniforms.find(name);
	if (it != _programUniforms.end())
	{
		return it->second;
	}

	int id = GLShader::getUniformLocation(_programID, name.c_str());
	GLDebug::showError();
	if (id < 0)
	{
		return nullptr;
	}

	auto pUniform = CREATE_OBJECT(ShaderProgramUniform);
	pUniform->setProgramUniformID(id);
	pUniform->setName(name);
	pUniform->setProgram(this);
	this->addProgramUniform(name, pUniform);

	return pUniform;
}



void render::ShaderProgram::addProgramUniform(const std::string& name, ShaderProgramUniform* uniform)
{
	if (name.empty() || uniform == nullptr)
	{
		return;
	}
	SAFE_RETAIN(uniform);
	_programUniforms[name] = uniform;
}

void render::ShaderProgram::removeAllProgramUniforms()
{
	for (auto item : _programUniforms)
	{
		SAFE_RELEASE(item.second);
	}
	_programUniforms.clear();

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
	pUniformBlock->setUniformBlockID(id);
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

	int32_t id = GLShader::getSubroutineUniformLocation(_programID, shaderType, name.c_str());
	GLDebug::showError();
	if (id <= 0)
	{
		return nullptr;
	}
	
	auto pSubroutineUniform = CREATE_OBJECT(ShaderSubroutineUniform);
	pSubroutineUniform->setSubUniformID(id);
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

void render::ShaderProgram::setUniformValue(const std::string& name, int value)
{
	auto pUniform = getUniform(name);
	if (pUniform == nullptr) return;
	pUniform->setValue(value);
}

void render::ShaderProgram::setUniformValue(const std::string& name, float value)
{
	auto pUniform = getUniform(name);
	if (pUniform == nullptr) return;
	pUniform->setValue(value);
}

void render::ShaderProgram::setUniformValue(const std::string& name, const math::Vector2& value)
{
	auto pUniform = getUniform(name);
	if (pUniform == nullptr) return;
	pUniform->setValue2(1, value.getValue());
}

void render::ShaderProgram::setUniformValue(const std::string& name, const math::Vector3& value)
{
	auto pUniform = getUniform(name);
	if (pUniform == nullptr) return;
	pUniform->setValue3(1, value.getValue());
}

void render::ShaderProgram::setUniformValue(const std::string& name, const math::Vector4& value)
{
	auto pUniform = getUniform(name);
	if (pUniform == nullptr) return;
	pUniform->setValue4(1, value.getValue());
}

void render::ShaderProgram::setUniformValue(const std::string& name, const math::Matrix2x2& value)
{
	auto pUniform = getUniform(name);
	if (pUniform == nullptr) return;
	pUniform->setMatrix2x2(value);
}

void render::ShaderProgram::setUniformValue(const std::string& name, const math::Matrix3x3& value)
{
	auto pUniform = getUniform(name);
	if (pUniform == nullptr) return;
	pUniform->setMatrix3x3(value);
}

void render::ShaderProgram::setUniformValue(const std::string& name, const math::Matrix4x4& value)
{
	auto pUniform = getUniform(name);
	if (pUniform == nullptr) return;
	pUniform->setMatrix4x4(value);
}

void render::ShaderProgram::enableAttrib(VertexArrayBufferObject* vabo, const std::string& name)
{
	if (vabo == nullptr) return;
	auto attrib = getAttrib(name);
	if (attrib)
	{
		vabo->enableVertexArrayAttrib(attrib->getAttribID());
	}
}

void render::ShaderProgram::disableAttrib(VertexArrayBufferObject* vabo, const std::string& name)
{
	if (vabo == nullptr) return;
	auto attrib = getAttrib(name);
	if (attrib)
	{
		vabo->disableVertexArrayAttrib(attrib->getAttribID());
	}
}

void render::ShaderProgram::enableAttrib(VertexArrayObject* vao, const std::string& name)
{
	if (vao == nullptr) return;
	auto attrib = getAttrib(name);
	if (attrib)
	{
		vao->enableVertexArrayAttrib(attrib->getAttribID());
	}
}

void render::ShaderProgram::disableAttrib(VertexArrayObject* vao, const std::string& name)
{
	if (vao == nullptr) return;
	auto attrib = getAttrib(name);
	if (attrib)
	{
		vao->disableVertexArrayAttrib(attrib->getAttribID());
	}
}

void render::ShaderProgram::bindAttribPointer(VertexArrayObject* vao, const std::string& name, int size, VertexAttribPointerType type, uint32_t offset)
{
	if (vao == nullptr) return;
	auto attrib = getAttrib(name);
	if (attrib)
	{
		vao->setVertexAttribPointer(attrib->getAttribID(), size, type, 0, offset);
	}
}
