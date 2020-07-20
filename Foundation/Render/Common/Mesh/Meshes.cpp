#include "Meshes.h"
#include "Common/Buffer/import.h"
#include "Common/Shader/import.h"
#include "Graphic/import.h"
#include "Mesh.h"
#include "Common/Node/Node.h"
#include "Common/Tool/Tool.h"
#include "Common/VAO/import.h"
#include "Common/Material/import.h"
using namespace render;

render::Meshes::Meshes()
{

}

render::Meshes::~Meshes()
{
	this->removeAllMeshes();
}

void render::Meshes::setModelDetail(const sys::ModelDetail* modelDetail)
{
	if (modelDetail == nullptr)
	{
		return;
	}

	this->removeAllMeshes();

	for (auto item : modelDetail->getMeshes())
	{
		this->addMesh(item.first, item.second);
	}
}

void Meshes::addMesh(const std::string& name, sys::MeshDetail* mesh)
{
	if (mesh == nullptr)
	{
		return;
	}

	this->removeMesh(name);

	Mesh* pMesh = CREATE_OBJECT(Mesh);
	SAFE_RETAIN(pMesh);

	pMesh->setMeshDetail(mesh);

	_meshes[name] = pMesh;
}

void Meshes::removeMesh(const std::string& name)
{
	auto it = _meshes.find(name);
	if (it == _meshes.end())
	{
		return;
	}

	SAFE_RELEASE(it->second);
	_meshes.erase(it);
}

void Meshes::removeAllMeshes()
{
	for (auto it : _meshes)
	{
		SAFE_RELEASE(it.second);
	}
	_meshes.clear();
}

Mesh* Meshes::getMesh(const std::string& name)
{
	auto it = _meshes.find(name);
	if (it == _meshes.end())
	{
		return nullptr;
	}

	return it->second;
}

void render::Meshes::updateBufferData()
{
	for (auto item : _meshes)
	{
		auto pMesh = item.second;

		pMesh->updateBufferData();
	}
}

const std::map<std::string, Mesh*>& render::Meshes::getMeshes() const
{
	return _meshes;
}


