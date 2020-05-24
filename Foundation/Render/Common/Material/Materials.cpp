#include "Materials.h"
#include "Graphic/import.h"
#include "Common/Shader/import.h"
#include "Common/Buffer/import.h"
#include "Common/View/import.h"
#include "Common/Texture/import.h"
#include "Common/BufferObject/import.h"
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

void Materials::addMaterial(int id, sys::MaterialDetail* material)
{
	if (material == nullptr)
	{
		return;
	}

	this->removeMaterial(id);

	Material* pMat = CREATE_OBJECT(Material);
	SAFE_RETAIN(pMat);


	pMat->setMaterialDetail(material);

	_materials[id] = pMat;
}

void Materials::removeMaterial(int id)
{
	auto it = _materials.find(id);
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

Material* Materials::getMaterial(int id)
{
	auto it = _materials.find(id);
	if (it == _materials.end())
	{
		return nullptr;
	}

	return it->second;
}

const std::map<int, Material*>& render::Materials::getMaterials() const
{
	return _materials;
}

void render::Materials::updateMatTexture()
{
	if (_texturePaths.empty())
	{
		return;
	}
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

void Materials::addTexture(const std::string& name, const Texture2D* id)
{
	if (id == nullptr)
	{
		return;
	}
	this->removeTexture(name);

	Texture2D* pid = (Texture2D*)id;
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

Texture2D* Materials::getTexture(const std::string& name) const
{
	auto it = _textures.find(name);
	if (it == _textures.end())
	{
		return 0;
	}

	return it->second;
}

Texture2D* Materials::createTexture(const std::string& strFullpath)
{
	if (strFullpath.empty())
	{
		return nullptr;
	}
	Texture2D* pTexture = G_TEXTURE_CACHE->createTexture2D(strFullpath);
	return pTexture;
}