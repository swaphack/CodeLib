#include "ModelDetail.h"
#include "system.h"
#include "Common/Texture/TextureCache.h"
#include "Common/Texture/Texture.h"

#include "MaterialDetail.h"
#include "MeshDetail.h"

using namespace render;


ModelDetail::ModelDetail()
{

}

ModelDetail::~ModelDetail()
{
	this->removeAllMaterials();
	this->removeAllMeshes();
	this->removeAllTextures();
}

ModelResourceFormat ModelDetail::getModelFormat()
{
	return _format;
}

void ModelDetail::setModelFormat(ModelResourceFormat format)
{
	_format = format;
}

Texture2D* ModelDetail::createTexture(const std::string& strFileName, const std::string& dir)
{
	std::string fullpath = dir + "/" + strFileName;

	return createTexture(fullpath);
}

Texture2D* ModelDetail::createTexture(const std::string& strFullpath)
{
	if (strFullpath.empty())
	{
		return nullptr;
	}
	Texture2D* pTexture = G_TEXTURE_CACHE->createTexture2D(strFullpath);
	return pTexture;
}

void ModelDetail::addMaterial(int id, MaterialDetail* material)
{
	if (material == nullptr)
	{
		return;
	}

	this->removeMaterial(id);

	SAFE_RETAIN(material);

	_materials[id] = material;
}

void ModelDetail::removeMaterial(int id)
{
	auto it = _materials.find(id);
	if (it == _materials.end())
	{
		return;
	}

	SAFE_RELEASE(it->second);
	_materials.erase(it);
}

void ModelDetail::removeAllMaterials()
{
	for (auto it : _materials)
	{
		SAFE_RELEASE(it.second);
	}
	_materials.clear();
}

MaterialDetail* ModelDetail::getMaterial(int id)
{
	auto it = _materials.find(id);
	if (it == _materials.end())
	{
		return nullptr;
	}

	return it->second;
}

void ModelDetail::addMesh(int id, MeshDetail* mesh)
{
	if (mesh == nullptr)
	{
		return;
	}

	this->removeMesh(id);

	SAFE_RETAIN(mesh);

	_meshes[id] = mesh;
}

void ModelDetail::removeMesh(int id)
{
	auto it = _meshes.find(id);
	if (it == _meshes.end())
	{
		return;
	}

	SAFE_RELEASE(it->second);
	_meshes.erase(it);
}

void ModelDetail::removeAllMeshes()
{
	for (auto it : _meshes)
	{
		SAFE_RELEASE(it.second);
	}
	_meshes.clear();
}

MeshDetail* ModelDetail::getMesh(int id)
{
	auto it = _meshes.find(id);
	if (it == _meshes.end())
	{
		return nullptr;
	}

	return it->second;
}

void ModelDetail::addTexture(const std::string& name, Texture2D* id)
{
	if (id == nullptr)
	{
		return;
	}
	this->removeTexture(name);

	SAFE_RETAIN(id);

	_textures[name] = id;
}

void ModelDetail::removeTexture(const std::string& name)
{
	auto it = _textures.find(name);
	if (it == _textures.end())
	{
		return;
	}

	SAFE_RELEASE(it->second);

	_textures.erase(it);
}

void ModelDetail::removeAllTextures()
{
	for (auto item : _textures)
	{
		SAFE_RELEASE(item.second);
	}
	_textures.clear();
}

int ModelDetail::getTexture(const std::string& name)
{
	auto it = _textures.find(name);
	if (it == _textures.end())
	{
		return 0;
	}

	return it->second->getTextureID();
}

const std::map<int, MaterialDetail*>& ModelDetail::geMaterials()
{
	return _materials;
}

const std::map<int, MeshDetail*>& ModelDetail::getMeshes()
{
	return _meshes;
}

