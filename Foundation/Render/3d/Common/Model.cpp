#include "Model.h"

using namespace render;


Model::Model()
{
}

Model::~Model()
{
	this->removeAllMaterials();
	this->removeAllMeshes();
	this->removeAllTextures();
}

void Model::draw()
{
	for (auto mesh : _meshes)
	{
		mesh.second->apply(0, getColor(), getOpacity(), getBlend());
		int matID = mesh.second->getMaterial();
		auto pMat = this->getMatrial(matID);
		if (pMat)
		{
			pMat->apply();
		}
	}
}

void Model::addMaterial(int id, Material* material)
{
	if (material == nullptr)
	{
		return;
	}

	this->removeMaterial(id);

	SAFE_RETAIN(material);

	_materials[id] = material;
}

void Model::removeMaterial(int id)
{
	auto it = _materials.find(id);
	if (it == _materials.end())
	{
		return;
	}

	SAFE_RELEASE(it->second);
	_materials.erase(it);
}

void Model::removeAllMaterials()
{
	for (auto it : _materials)
	{
		SAFE_RELEASE(it.second);
	}
	_materials.clear();
}

Material* Model::getMatrial(int id)
{
	auto it = _materials.find(id);
	if (it == _materials.end())
	{
		return nullptr;
	}

	return it->second;
}

void Model::addMesh(int id, Mesh* mesh)
{
	if (mesh == nullptr)
	{
		return;
	}

	this->removeMesh(id);

	SAFE_RETAIN(mesh);

	_meshes[id] = mesh;
}

void Model::removeMesh(int id)
{
	auto it = _meshes.find(id);
	if (it == _meshes.end())
	{
		return;
	}

	SAFE_RELEASE(it->second);
	_meshes.erase(it);
}

void Model::removeAllMeshes()
{
	for (auto it : _meshes)
	{
		SAFE_RELEASE(it.second);
	}
	_meshes.clear();
}

Mesh* Model::getMesh(int id)
{
	auto it = _meshes.find(id);
	if (it == _meshes.end())
	{
		return nullptr;
	}

	return it->second;
}

void Model::addTexture(const std::string& name, int id)
{
	this->removeTexture(name);

	_textures[name] = id;
}

void Model::removeTexture(const std::string& name)
{
	auto it = _textures.find(name);
	if (it == _textures.end())
	{
		return;
	}

	G_TEXTURE_CACHE->removeTexture(name.c_str());

	_textures.erase(it);
}

void Model::removeAllTextures()
{
	for (auto item : _textures)
	{
		G_TEXTURE_CACHE->removeTexture(item.first);
	}
	_textures.clear();
}

int Model::getTexture(const std::string& name)
{
	auto it = _textures.find(name);
	if (it == _textures.end())
	{
		return 0;
	}

	return it->second;
}
