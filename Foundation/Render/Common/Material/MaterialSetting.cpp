#include "MaterialSetting.h"
#include "Common/Shader/ShaderProgram.h"
#include "MaterialGlobalParameter.h"

render::MaterialSetting::MaterialSetting()
{
}

render::MaterialSetting::~MaterialSetting()
{
}

void render::MaterialSetting::setShaderProgram(ShaderProgram* shaderProgram)
{
	_shaderProgram = shaderProgram;
	initParameters(shaderProgram);
}

void render::MaterialSetting::removeAllUniforms(bool bContainSelfDefined)
{
	_mapEnvUniforms.clear();
	_mapMatrixUniforms.clear();
	_mapTextureUniforms.clear();
	_mapMaterialUniforms.clear();
	_mapSingleLightUniforms.clear();
	_mapMultiLightsUniforms.clear();

	_mapAttribs.clear();

	if (bContainSelfDefined)
	{
		removeAllSelfDefineUniforms();
	}
}

void render::MaterialSetting::addSelfDefineUniform(const std::string& name, UniformType type, void* value)
{
	UniformParameter parameter(name, type, value);
	_mapSelfDefinedUniforms[name] = parameter;
}


void render::MaterialSetting::removeAllSelfDefineUniforms()
{
	_mapSelfDefinedUniforms.clear();
}

void render::MaterialSetting::initParameters(ShaderProgram* shaderProgram)
{
	removeAllUniforms();
	if (shaderProgram == nullptr) return;
	shaderProgram->use();

	MaterialGlobalParameter* pInstance = G_MATERIALGLOBALPARAMETER;
	if (pInstance != nullptr)
	{
		for (auto item : pInstance->getEnvUniforms())
		{
			auto pUniform = _shaderProgram->getUniform(item.second);
			if (pUniform != nullptr)
			{
				_mapEnvUniforms[item.first] = item.second;
			}
		}
		for (auto item : pInstance->getMatrixUniforms())
		{
			auto pUniform = _shaderProgram->getUniform(item.second);
			if (pUniform != nullptr)
			{
				_mapMatrixUniforms[item.first] = item.second;
			}
		}
		for (auto item : pInstance->getTextureUniforms())
		{
			auto pUniform = _shaderProgram->getUniform(item.second);
			if (pUniform != nullptr)
			{
				_mapTextureUniforms[item.first] = item.second;
			}
		}
		for (auto item : pInstance->getMaterialUniforms())
		{
			auto pUniform = _shaderProgram->getUniform(item.second);
			if (pUniform != nullptr)
			{
				_mapMaterialUniforms[item.first] = item.second;
			}
		}
		for (auto item : pInstance->getSingleLightUniforms())
		{
			auto pUniform = _shaderProgram->getUniform(item.second);
			if (pUniform != nullptr)
			{
				_mapSingleLightUniforms[item.first] = item.second;
			}
		}
		for (auto item : pInstance->getMultiLightsUniforms())
		{
			auto pUniform = _shaderProgram->getUniform(item.second);
			if (pUniform != nullptr)
			{
				_mapMultiLightsUniforms[item.first] = item.second;
			}
		}

		for (auto item : pInstance->getVertexDataTypes())
		{
			auto pUniform = _shaderProgram->getAttrib(item.second);
			if (pUniform != nullptr)
			{
				_mapAttribs[item.first] = item.second;
			}
		}
	}

	shaderProgram->unuse();
}