#include "ShaderProperty.h"
#include "ShaderProgram.h"
#include "Common/Material/MaterialGlobalParameter.h"

render::ShaderProperty::ShaderProperty()
{
}

render::ShaderProperty::~ShaderProperty()
{
}

void render::ShaderProperty::initShaderProgram(ShaderProgram* program)
{
	removeAllUniforms();
	if (program == nullptr) return;
	program->use();

	MaterialGlobalParameter* pInstance = G_MATERIALGLOBALPARAMETER;
	if (pInstance != nullptr)
	{
		for (auto item : pInstance->getEnvUniforms())
		{
			auto pUniform = program->getUniform(item.second);
			if (pUniform != nullptr)
			{
				_mapEnvUniforms[(uint8_t)item.first] = item.second;
			}
		}
		for (auto item : pInstance->getMatrixUniforms())
		{
			auto pUniform = program->getUniform(item.second);
			if (pUniform != nullptr)
			{
				_mapMatrixUniforms[(uint8_t)item.first] = item.second;
			}
		}
		for (auto item : pInstance->getTextureUniforms())
		{
			auto pUniform = program->getUniform(item.second);
			if (pUniform != nullptr)
			{
				_mapTextureUniforms[(uint8_t)item.first] = item.second;
			}
		}
		for (auto item : pInstance->getMaterialUniforms())
		{
			auto pUniform = program->getUniform(item.second);
			if (pUniform != nullptr)
			{
				_mapMaterialUniforms[(uint8_t)item.first] = item.second;
			}
		}
		for (auto item : pInstance->getSingleLightUniforms())
		{
			auto pUniform = program->getUniform(item.second);
			if (pUniform != nullptr)
			{
				_mapSingleLightUniforms[(uint8_t)item.first] = item.second;
			}
		}
		for (auto item : pInstance->getMultiLightsUniforms())
		{
			auto pUniform = program->getUniform(item.second);
			if (pUniform != nullptr)
			{
				_mapMultiLightsUniforms[(uint8_t)item.first] = item.second;
			}
		}

		for (auto item : pInstance->getVertexDataTypes())
		{
			auto pUniform = program->getAttrib(item.second);
			if (pUniform != nullptr)
			{
				_mapAttribs[(uint8_t)item.first] = item.second;
			}
		}
	}
	program->unuse();
}

void render::ShaderProperty::removeAllUniforms()
{
	_mapEnvUniforms.clear();
	_mapMatrixUniforms.clear();
	_mapTextureUniforms.clear();
	_mapMaterialUniforms.clear();
	_mapSingleLightUniforms.clear();
	_mapMultiLightsUniforms.clear();

	_mapAttribs.clear();
}
