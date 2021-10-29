#include "ModelDetail.h"
#include "system.h"


#include "MaterialDetail.h"
#include "MeshDetail.h"

using namespace sys;


ModelDetail::ModelDetail()
{

}

ModelDetail::~ModelDetail()
{
	this->removeAllMaterials();
	this->removeAllMeshes();
	this->removeAllTexturePaths();
}

void ModelDetail::addMaterial(const std::string& name, MaterialDetail* material)
{
	if (material == nullptr)
	{
		return;
	}

	SAFE_RETAIN(material);

	this->removeMaterial(name);

	_materials[name] = material;
}

void ModelDetail::removeMaterial(const std::string& name)
{
	auto it = _materials.find(name);
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

MaterialDetail* ModelDetail::getMaterial(const std::string& name) const
{
	auto it = _materials.find(name);
	if (it == _materials.end())
	{
		return nullptr;
	}

	return it->second;
}

void ModelDetail::addMesh(const std::string& name, MeshDetail* mesh)
{
	if (mesh == nullptr)
	{
		return;
	}

	SAFE_RETAIN(mesh);

	this->removeMesh(name);

	_meshes[name] = mesh;
}

void ModelDetail::removeMesh(const std::string& name)
{
	auto it = _meshes.find(name);
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

MeshDetail* ModelDetail::getMesh(const std::string& name) const
{
	auto it = _meshes.find(name);
	if (it == _meshes.end())
	{
		return nullptr;
	}

	return it->second;
}

const std::map<std::string, MaterialDetail*>& ModelDetail::getMaterials() const
{
	return _materials;
}

const std::map<std::string, MeshDetail*>& ModelDetail::getMeshes() const
{
	return _meshes;
}

void ModelDetail::addTexturePath(const std::string& name, const std::string& path)
{
	_texturePaths[name] = path;
}

void ModelDetail::removeAllTexturePaths()
{
	_texturePaths.clear();
}

std::string ModelDetail::getTexturePath(const std::string& name)
{
	auto it = _texturePaths.find(name);
	if (it == _texturePaths.end())
	{
		return "";
	}

	return it->second;
}

const std::map<std::string, std::string>& ModelDetail::getTexturePaths() const
{
	return _texturePaths;
}

std::string ModelDetail::getTextureFullPath(const std::string& strFileName, const std::string& dir)
{
	std::string fullpath = dir + "/" + strFileName;

	return fullpath;
}

