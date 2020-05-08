#include "Material.h"
#include "Resource/Detail/ModelDetail.h"
#include "Resource/Detail/MaterialDetail.h"
#include "Graphic/import.h"
#include "Common/Shader/import.h"
#include "Common/Buffer/import.h"
#include "Common/View/import.h"
#include "Common/Texture/import.h"

using namespace render;

render::Material::Material()
{

}

render::Material::~Material()
{
	this->removeAllTextures();

	SAFE_RELEASE(_shaderProgram);
}

void render::Material::setModelDetail(const ModelDetail* modelDetail)
{
	if (modelDetail == nullptr)
	{
		return;
	}

	this->_texturePaths = modelDetail->getTexturePaths();
	this->_materials = modelDetail->getMaterials();
}
void render::Material::setShaderProgram(ShaderProgram* shaderProgram)
{
	SAFE_RELEASE(_shaderProgram);
	SAFE_RETAIN(shaderProgram);

	_shaderProgram = shaderProgram;
}

render::ShaderProgram* render::Material::getShaderProgram()
{
	return _shaderProgram;
}

void Material::addMaterial(int id, MaterialDetail* material)
{
	if (material == nullptr)
	{
		return;
	}

	this->removeMaterial(id);

	SAFE_RETAIN(material);

	_materials[id] = material;
}

void Material::removeMaterial(int id)
{
	auto it = _materials.find(id);
	if (it == _materials.end())
	{
		return;
	}

	SAFE_RELEASE(it->second);
	_materials.erase(it);
}

void Material::removeAllMaterials()
{
	for (auto it : _materials)
	{
		SAFE_RELEASE(it.second);
	}
	_materials.clear();
}

MaterialDetail* Material::getMaterial(int id)
{
	auto it = _materials.find(id);
	if (it == _materials.end())
	{
		return nullptr;
	}

	return it->second;
}

void render::Material::addAttrib(VertexAttribType vat, const std::string& name)
{
	_vertexAttribIndices[vat] = name;
}

std::string render::Material::getAttribIndex(VertexAttribType vat) const
{
	auto it = _vertexAttribIndices.find(vat);
	if (it == _vertexAttribIndices.end())
	{
		return "";
	}

	return it->second;
}

void render::Material::removeAttribIndices()
{
	_vertexAttribIndices.clear();
}

void render::Material::addUniform(VertexUniformType vut, const std::string& name)
{
	_vertexUniformIndices[vut] = name;
}

std::string render::Material::getUniformIndex(VertexUniformType vut) const
{
	auto it = _vertexUniformIndices.find(vut);
	if (it == _vertexUniformIndices.end())
	{
		return "";
	}

	return it->second;
}

void render::Material::removeUniformIndices()
{
	_vertexUniformIndices.clear();
}

void render::Material::startUpdateShaderUniformValue(const math::Matrix44& projMat, const math::Matrix44& viewMat, const math::Matrix44& modelMat)
{
	if (_shaderProgram == nullptr)
	{
		return; 
	}

	_shaderProgram->use();

	for (auto item : _vertexUniformIndices)
	{
		if (item.first == VertexUniformType::PROJECT_MATRIX)
		{
			auto pUniform = _shaderProgram->getUniform(item.second);
			if (pUniform) pUniform->setMatrix4(1, false, projMat.getValue());
		}
		else if (item.first == VertexUniformType::VIEW_MATRIX)
		{
			auto pUniform = _shaderProgram->getUniform(item.second);
			if (pUniform) pUniform->setMatrix4(1, false, viewMat.getValue());
		}
		else if (item.first == VertexUniformType::MODEL_VIEW)
		{
			auto pUniform = _shaderProgram->getUniform(item.second);
			if (pUniform) pUniform->setMatrix4(1, false, modelMat.getValue());
		}

		GLDebug::showError();
	}
}

void render::Material::startUpdateShaderVertexValue(VertexArrayObject* data)
{
	if (data == nullptr)
	{
		return;
	}

	if (_shaderProgram == nullptr)
	{
		return;
	}

	_shaderProgram->use();

	for (auto item : _vertexAttribIndices)
	{
		auto pAttrib = _shaderProgram->getAttrib(item.second);
		if (!pAttrib) continue;
		VertexAttribPointer* pointer = data->getVertexAttrib<VertexAttribPointer>(pAttrib->getAttribID());
		pointer->enableVertexArrayAttrib();

		if (item.first == VertexAttribType::POSITION)
		{
			pointer->setVertexAttribPointer(3, VertexAttribPointerType::FLOAT, 0);
		}
		else if (item.first == VertexAttribType::COLOR)
		{
			pointer->setVertexAttribPointer(4, VertexAttribPointerType::FLOAT, 0);
		}
		else if (item.first == VertexAttribType::UV)
		{
			pointer->setVertexAttribPointer(2, VertexAttribPointerType::FLOAT, 0);
		}

		GLDebug::showError();
	}

	GLDebug::showError();
}

void render::Material::applyMat(uint32_t nMatID) const
{
	auto it = _materials.find(nMatID);
	if (it == _materials.end())
	{
		return;
	}
	auto pMat = it->second;

	pMat->apply();

	auto nTextureID1 = this->getTexture(pMat->getAmbientTextureMap());
	auto nTextureID2 = this->getTexture(pMat->getDiffuseTextureMap());
	if (nTextureID1 || nTextureID2)
	{
		GLState::enable(EnableModel::TEXTURE_2D);
		if (nTextureID1) GLTexture::bindTexture2D(nTextureID1);
		else if (nTextureID2) GLTexture::bindTexture2D(nTextureID2);
	}
}

void render::Material::updateMatTexture()
{
	for (auto item : _texturePaths)
	{
		Texture2D* pTexture = this->createTexture(item.second);
		if (pTexture)
		{
			this->addTexture(item.first, pTexture);
		}
	}
	_texturePaths.clear();
}

void render::Material::endUpdateShaderVertexValue(VertexArrayObject* data)
{
	for (auto item : _vertexAttribIndices)
	{
		auto pAttrib = _shaderProgram->getAttrib(item.second);
		if (!pAttrib) continue;
		VertexAttribPointer* pointer = data->getVertexAttrib<VertexAttribPointer>(pAttrib->getAttribID());
		pointer->disableVertexArrayAttrib();
	}
}

void render::Material::endUpdateShaderUniformValue()
{
	ShaderProgram::useNone();

	GLDebug::showError();
}

void Material::addTexture(const std::string& name, Texture2D* id)
{
	if (id == nullptr)
	{
		return;
	}
	this->removeTexture(name);

	SAFE_RETAIN(id);

	_textures[name] = id;
}

void Material::removeTexture(const std::string& name)
{
	auto it = _textures.find(name);
	if (it == _textures.end())
	{
		return;
	}

	SAFE_RELEASE(it->second);

	_textures.erase(it);
}

void Material::removeAllTextures()
{
	for (auto item : _textures)
	{
		SAFE_RELEASE(item.second);
	}
	_textures.clear();
}

int Material::getTexture(const std::string& name) const
{
	auto it = _textures.find(name);
	if (it == _textures.end())
	{
		return 0;
	}

	return it->second->getTextureID();
}

Texture2D* Material::createTexture(const std::string& strFullpath)
{
	if (strFullpath.empty())
	{
		return nullptr;
	}
	Texture2D* pTexture = G_TEXTURE_CACHE->createTexture2D(strFullpath);
	return pTexture;
}