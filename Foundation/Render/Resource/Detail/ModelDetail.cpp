#include "ModelDetail.h"
#include "system.h"
#include "Common/Texture/TextureCache.h"
#include "Common/Texture/Texture.h"

#include "MaterialDetail.h"
#include "MeshDetail.h"
#include "FaceDetail.h"

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

uint32_t ModelDetail::createTexture(const std::string& strFileName, const std::string& dir)
{
	std::string fullpath = dir + "/" + strFileName;

	return createTexture(fullpath);
}

uint32_t ModelDetail::createTexture(const std::string& strFullpath)
{
	if (strFullpath.empty())
	{
		return 0;
	}
	Texture2D* pTexture = G_TEXTURE_CACHE->createTexture2D(strFullpath);
	if (pTexture == nullptr)
	{
		return 0;
	}

	return pTexture->getTextureID();
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

void ModelDetail::addTexture(const std::string& name, int id)
{
	this->removeTexture(name);

	_textures[name] = id;
}

void ModelDetail::removeTexture(const std::string& name)
{
	auto it = _textures.find(name);
	if (it == _textures.end())
	{
		return;
	}

	G_TEXTURE_CACHE->removeTexture(name.c_str());

	_textures.erase(it);
}

void ModelDetail::removeAllTextures()
{
	for (auto item : _textures)
	{
		G_TEXTURE_CACHE->removeTexture(item.first);
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

	return it->second;
}

const std::map<int, MaterialDetail*>& ModelDetail::geMaterials()
{
	return _materials;
}

const std::map<int, MeshDetail*>& ModelDetail::getMeshes()
{
	return _meshes;
}

