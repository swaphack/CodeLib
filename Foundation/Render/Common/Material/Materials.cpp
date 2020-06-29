#include "Materials.h"
#include "Graphic/import.h"
#include "Common/Shader/import.h"
#include "Common/Buffer/import.h"
#include "Common/View/import.h"
#include "Common/Texture/import.h"
#include "Common/VAO/import.h"
#include "Material.h"

using namespace render;

render::Materials::Materials()
{

}

render::Materials::~Materials()
{
	this->removeAllTextures();
}

void render::Materials::setModelDetail(const sys::ModelDetail* modelDetail)
{
	if (modelDetail == nullptr)
	{
		return;
	}

	this->removeAllMaterials();

	this->_texturePaths = modelDetail->getTexturePaths();
	for (auto item : modelDetail->getMaterials())
	{
		this->addMaterial(item.first, item.second);
	}
}

void Materials::addMaterial(const std::string& name, sys::MaterialDetail* material)
{
	if (material == nullptr)
	{
		return;
	}

	this->removeMaterial(name);

	Material* pMat = CREATE_OBJECT(Material);
	SAFE_RETAIN(pMat);


	pMat->setMaterialDetail(material);

	_materials[name] = pMat;
}

void Materials::removeMaterial(const std::string& name)
{
	auto it = _materials.find(name);
	if (it == _materials.end())
	{
		return;
	}

	SAFE_RELEASE(it->second);
	_materials.erase(it);
}

void Materials::removeAllMaterials()
{
	for (auto it : _materials)
	{
		SAFE_RELEASE(it.second);
	}
	_materials.clear();
}

Material* Materials::getMaterial(const std::string& name)
{
	auto it = _materials.find(name);
	if (it == _materials.end())
	{
		return nullptr;
	}

	return it->second;
}

const std::map<std::string, Material*>& render::Materials::getMaterials() const
{
	return _materials;
}

int render::Materials::getMaterialCount() const
{
	return _materials.size();
}

void render::Materials::addTexture(const std::string& name, const std::string& fullpath)
{
	if (fullpath.empty())
	{
		return;
	}
	Texture2D* pTexture = G_TEXTURE_CACHE->createTexture2D(fullpath);
	if (!pTexture)
	{
		return;
	}

	this->addTexture(name, pTexture);
}

void render::Materials::setMaterialTexture(const std::string& matName, const std::string& textureName)
{
	auto it = _materials.find(matName);
	if (it != _materials.end())
	{
		it->second->getMaterialDetail()->setAmbientTextureMap(textureName);
	}
}

void render::Materials::setMaterialShaderProgram(const std::string& matName, ShaderProgram* program)
{
	auto it = _materials.find(matName);
	if (it != _materials.end())
	{
		it->second->setShaderProgram(program);
	}
}

void render::Materials::setMaterialShaderProgramFunc(const std::string& matName, const ShaderProgramFunc& func)
{
	auto it = _materials.find(matName);
	if (it != _materials.end())
	{
		it->second->setProgramFunc(func);
	}
}

void render::Materials::updateMatTexture()
{
	if (_texturePaths.empty())
	{
		return;
	}
	for (auto item : _texturePaths)
	{
		this->addTexture(item.first, item.second);
	}
	_texturePaths.clear();
}

void Materials::addTexture(const std::string& name, const Texture* id)
{
	if (id == nullptr)
	{
		return;
	}
	this->removeTexture(name);

	Texture* pid = (Texture*)id;
	SAFE_RETAIN(pid);

	_textures[name] = pid;
}

void Materials::removeTexture(const std::string& name)
{
	auto it = _textures.find(name);
	if (it == _textures.end())
	{
		return;
	}

	SAFE_RELEASE(it->second);

	_textures.erase(it);
}

void Materials::removeAllTextures()
{
	for (auto item : _textures)
	{
		SAFE_RELEASE(item.second);
	}
	_textures.clear();
}

Texture* Materials::getTexture(const std::string& name) const
{
	auto it = _textures.find(name);
	if (it == _textures.end())
	{
		return nullptr;
	}

	return it->second;
}