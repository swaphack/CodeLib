#include "ModelDetail.h"
#include "system.h"


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
	this->removeAllTexturePaths();
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

const std::map<int, MaterialDetail*>& ModelDetail::getMaterials() const
{
	return _materials;
}

const std::map<int, MeshDetail*>& ModelDetail::getMeshes() const
{
	return _meshes;
}

void render::ModelDetail::addTexturePath(const std::string& name, const std::string& path)
{
	_texturePaths[name] = path;
}

void render::ModelDetail::removeAllTexturePaths()
{
	_texturePaths.clear();
}

std::string render::ModelDetail::getTexturePath(const std::string& name)
{
	auto it = _texturePaths.find(name);
	if (it == _texturePaths.end())
	{
		return "";
	}

	return it->second;
}

const std::map<std::string, std::string>& render::ModelDetail::getTexturePaths() const
{
	return _texturePaths;
}

std::string render::ModelDetail::getTextureFullPath(const std::string& strFileName, const std::string& dir)
{
	std::string fullpath = dir + "/" + strFileName;

	return fullpath;
}

