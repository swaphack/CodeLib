#include "MaterialGlobalParameter.h"

render::MaterialGlobalParameter::MaterialGlobalParameter()
{
	this->init();
}

render::MaterialGlobalParameter::~MaterialGlobalParameter()
{

}

void render::MaterialGlobalParameter::init()
{
	this->addUniform(render::MatrixUniformType::PROJECT_MATRIX, "matrix.project");
	this->addUniform(render::MatrixUniformType::VIEW_MATRIX, "matrix.view");
	this->addUniform(render::MatrixUniformType::MODEL_MATRIX, "matrix.model");
	this->addUniform(render::MatrixUniformType::NORMAL_MATRIX, "matrix.normal");

	this->addUniform(render::SingleLightUniformType::LIGHT_ENABLED, "light.isEnabled");
	this->addUniform(render::SingleLightUniformType::LIGHT_LOCAL, "light.isLocal");
	this->addUniform(render::SingleLightUniformType::LIGHT_SPOT, "light.isSpot");
	this->addUniform(render::SingleLightUniformType::LIGHT_POSITION, "light.position");
	this->addUniform(render::SingleLightUniformType::LIGHT_DIRECTION, "light.direction");
	this->addUniform(render::SingleLightUniformType::LIGHT_HALF_VECTOR, "light.halfVector");
	this->addUniform(render::SingleLightUniformType::LIGHT_SPACE_MATRIX, "light.spaceMatrix");
	this->addUniform(render::SingleLightUniformType::LIGHT_COLOR, "light.color");
	this->addUniform(render::SingleLightUniformType::LIGHT_AMBIENT, "light.ambient");
	this->addUniform(render::SingleLightUniformType::LIGHT_SPOT_EXPONENT, "light.spotExponent");
	this->addUniform(render::SingleLightUniformType::LIGHT_SPOT_COST_CUTOFF, "light.spotCostCutoff");
	this->addUniform(render::SingleLightUniformType::LIGHT_CONSTANT_ATTENUATION, "light.constantAttenuation");
	this->addUniform(render::SingleLightUniformType::LIGHT_LINEAR_ATTENUATION, "light.linearAttenuation");
	this->addUniform(render::SingleLightUniformType::LIGHT_QUADRATIC_ATTENUATION, "light.quadraticAttenuation");


	this->addUniform(render::MultiLightsUniformType::MULTI_LIGHT_ENABLED, "lights[%d].isEnabled");
	this->addUniform(render::MultiLightsUniformType::MULTI_LIGHT_LOCAL, "lights[%d].isLocal");
	this->addUniform(render::MultiLightsUniformType::MULTI_LIGHT_SPOT, "lights[%d].isSpot");
	this->addUniform(render::MultiLightsUniformType::MULTI_LIGHT_POSITION, "lights[%d].position");
	this->addUniform(render::MultiLightsUniformType::MULTI_LIGHT_DIRECTION, "lights[%d].direction");
	this->addUniform(render::MultiLightsUniformType::MULTI_LIGHT_HALF_VECTOR, "lights[%d].halfVector");
	this->addUniform(render::MultiLightsUniformType::MULTI_LIGHT_SPACE_MATRIX, "lights[%d].spaceMatrix");
	this->addUniform(render::MultiLightsUniformType::MULTI_LIGHT_COLOR, "lights[%d].color");
	this->addUniform(render::MultiLightsUniformType::MULTI_LIGHT_AMBIENT, "lights[%d].ambient");
	this->addUniform(render::MultiLightsUniformType::MULTI_LIGHT_SPOT_EXPONENT, "lights[%d].spotExponent");
	this->addUniform(render::MultiLightsUniformType::MULTI_LIGHT_SPOT_COST_CUTOFF, "lights[%d].spotCostCutoff");
	this->addUniform(render::MultiLightsUniformType::MULTI_LIGHT_CONSTANT_ATTENUATION, "lights[%d].constantAttenuation");
	this->addUniform(render::MultiLightsUniformType::MULTI_LIGHT_LINEAR_ATTENUATION, "lights[%d].linearAttenuation");
	this->addUniform(render::MultiLightsUniformType::MULTI_LIGHT_QUADRATIC_ATTENUATION, "lights[%d].quadraticAttenuation");

	this->addUniform(render::MaterialUniformType::MATERIAL_EMISSION, "material.emission");
	this->addUniform(render::MaterialUniformType::MATERIAL_COLOR_AMBIENT, "material.ambient");
	this->addUniform(render::MaterialUniformType::MATERIAL_COLOR_DIFFUSE, "material.diffuse");
	this->addUniform(render::MaterialUniformType::MATERIAL_COLOR_SPECULAR, "material.specular");
	this->addUniform(render::MaterialUniformType::MATERIAL_TEXTURE, "material.tex");
	this->addUniform(render::MaterialUniformType::MATERIAL_TEXTURE_NORMAL, "material.texNormal");
	this->addUniform(render::MaterialUniformType::MATERIAL_TEXTURE_ALPHA, "material.texAlpha");
	this->addUniform(render::MaterialUniformType::MATERIAL_TEXTURE_BUMP, "material.texBump");
	this->addUniform(render::MaterialUniformType::MATERIAL_TEXTURE_DIFFUSE, "material.texDiffuse");
	this->addUniform(render::MaterialUniformType::MATERIAL_TEXTURE_SPECULAR, "material.texSpecular");
	this->addUniform(render::MaterialUniformType::MATERIAL_TEXTURE_SHADOW, "material.texShadow");
	this->addUniform(render::MaterialUniformType::MATERIAL_SHININESS, "material.shininess");
	this->addUniform(render::MaterialUniformType::MATERIAL_STRENGTH, "material.strength");

	this->addVertexData(render::VertexDataType::POSITION, "v_position");
	this->addVertexData(render::VertexDataType::COLOR, "v_color");
	this->addVertexData(render::VertexDataType::UV, "v_texcoord");
	this->addVertexData(render::VertexDataType::NORMAL, "v_normal");
	this->addVertexData(render::VertexDataType::TANGENT, "v_tangent");
	this->addVertexData(render::VertexDataType::BITANGENT, "v_bitangent");


	this->addUniform(render::EnvUniformType::VIEW_POSITION, "env.viewPos");
	this->addUniform(render::EnvUniformType::GAMMA, "env.gamma");
	this->addUniform(render::EnvUniformType::LIGHT_COUNT, "env.lightCount");
	this->addUniform(render::EnvUniformType::POINT_SIZE, "env.pointSize");

	this->addUniform(render::TextureUniformType::TEXTURE0, "tex.texture0");
	this->addUniform(render::TextureUniformType::TEXTURE1, "tex.texture1");
	this->addUniform(render::TextureUniformType::TEXTURE2, "tex.texture2");
	this->addUniform(render::TextureUniformType::TEXTURE3, "tex.texture3");
	this->addUniform(render::TextureUniformType::TEXTURE4, "tex.texture4");
	this->addUniform(render::TextureUniformType::TEXTURE5, "tex.texture5");
	this->addUniform(render::TextureUniformType::TEXTURE6, "tex.texture6");
	this->addUniform(render::TextureUniformType::TEXTURE7, "tex.texture7");
}

void render::MaterialGlobalParameter::addVertexData(VertexDataType vat, const std::string& name)
{
	_vertexAttribIndices[vat] = name;
}

std::string render::MaterialGlobalParameter::getVertexName(VertexDataType vat) const
{
	auto it = _vertexAttribIndices.find(vat);
	if (it == _vertexAttribIndices.end())
	{
		return "";
	}

	return it->second;
}

void render::MaterialGlobalParameter::removeVertexDatas()
{
	_vertexAttribIndices.clear();
}

const std::map<render::VertexDataType, std::string>& render::MaterialGlobalParameter::getVertexDataTypes() const
{
	return _vertexAttribIndices;
}

std::string render::MaterialGlobalParameter::getUniformName(MultiLightsUniformType vut) const
{
	auto it = _mapMultiLightsUniforms.find(vut);
	if (it == _mapMultiLightsUniforms.end())
	{
		return "";
	}

	return it->second;
}

std::string render::MaterialGlobalParameter::getUniformName(SingleLightUniformType vut) const
{
	auto it = _mapSingleLightUniforms.find(vut);
	if (it == _mapSingleLightUniforms.end())
	{
		return "";
	}

	return it->second;
}

void render::MaterialGlobalParameter::addUniform(MultiLightsUniformType vut, const std::string& name)
{
	_mapMultiLightsUniforms[vut] = name;
}

std::string render::MaterialGlobalParameter::getUniformName(MaterialUniformType vut) const
{
	auto it = _mapMaterialUniforms.find(vut);
	if (it == _mapMaterialUniforms.end())
	{
		return "";
	}

	return it->second;
}

void render::MaterialGlobalParameter::addUniform(SingleLightUniformType vut, const std::string& name)
{
	_mapSingleLightUniforms[vut] = name;
}

std::string render::MaterialGlobalParameter::getUniformName(TextureUniformType vut) const
{
	auto it = _mapTextureUniforms.find(vut);
	if (it == _mapTextureUniforms.end())
	{
		return "";
	}

	return it->second;
}

void render::MaterialGlobalParameter::addUniform(MaterialUniformType vut, const std::string& name)
{
	_mapMaterialUniforms[vut] = name;
}

std::string render::MaterialGlobalParameter::getUniformName(MatrixUniformType vut) const
{
	auto it = _mapMatrixUniforms.find(vut);
	if (it == _mapMatrixUniforms.end())
	{
		return "";
	}

	return it->second;
}

void render::MaterialGlobalParameter::addUniform(TextureUniformType vut, const std::string& name)
{
	_mapTextureUniforms[vut] = name;
}

std::string render::MaterialGlobalParameter::getUniformName(EnvUniformType vut) const
{
	auto it = _mapEnvUniforms.find(vut);
	if (it == _mapEnvUniforms.end())
	{
		return "";
	}

	return it->second;
}

void render::MaterialGlobalParameter::addUniform(MatrixUniformType vut, const std::string& name)
{
	_mapMatrixUniforms[vut] = name;
}

void render::MaterialGlobalParameter::addUniform(EnvUniformType vut, const std::string& name)
{
	_mapEnvUniforms[vut] = name;
}

void render::MaterialGlobalParameter::removeUniformDatas()
{
	_mapEnvUniforms.clear();
	_mapTextureUniforms.clear();
	_mapMaterialUniforms.clear();
	_mapMatrixUniforms.clear();
	_mapSingleLightUniforms.clear();
	_mapMultiLightsUniforms.clear();
}

const std::map<render::EnvUniformType, std::string>& render::MaterialGlobalParameter::getEnvUniforms() const
{
	return _mapEnvUniforms;
}

const std::map<render::MatrixUniformType, std::string>& render::MaterialGlobalParameter::getMatrixUniforms() const
{
	return _mapMatrixUniforms;
}

const std::map<render::TextureUniformType, std::string>& render::MaterialGlobalParameter::getTextureUniforms() const
{
	return _mapTextureUniforms;
}

const std::map<render::MaterialUniformType, std::string>& render::MaterialGlobalParameter::getMaterialUniforms() const
{
	return _mapMaterialUniforms;
}

const std::map<render::SingleLightUniformType, std::string>& render::MaterialGlobalParameter::getSingleLightUniforms() const
{
	return _mapSingleLightUniforms;
}

const std::map<render::MultiLightsUniformType, std::string>& render::MaterialGlobalParameter::getMultiLightsUniforms() const
{
	return _mapMultiLightsUniforms;
}
