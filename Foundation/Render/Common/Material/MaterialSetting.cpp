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
}

void render::MaterialSetting::addSelfDefineUniform(const std::string& name, UniformType type, uint32_t size, void* value)
{
	UniformParameter parameter(name, type, size, value);
	_mapSelfDefinedUniforms[name] = parameter;
}

void render::MaterialSetting::removeAllSelfDefineUniforms()
{
	_mapSelfDefinedUniforms.clear();
}

bool render::MaterialSetting::equalsSelfDefinedUniforms(const MaterialSetting& ms) const
{
	if (ms.getSelfDefinedUniforms().size() != _mapSelfDefinedUniforms.size())
	{
		return false;
	}
	for (auto& item : ms.getSelfDefinedUniforms())
	{
		auto it = _mapSelfDefinedUniforms.find(item.first);
		if (it != _mapSelfDefinedUniforms.end()) return false;
		if (!it->second.equals(item.second)) return false;
	}
	return true;
}