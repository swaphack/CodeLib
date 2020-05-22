#include "Meshes.h"
#include "Common/Buffer/import.h"
#include "Common/Shader/import.h"
#include "Graphic/import.h"
#include "Mesh.h"
#include "Common/Node/Node.h"
#include "Common/Tool/Tool.h"
#include "Common/BufferObject/import.h"
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

void Meshes::addMesh(int id, sys::MeshDetail* mesh)
{
	if (mesh == nullptr)
	{
		return;
	}

	this->removeMesh(id);

	Mesh* pMesh = CREATE_OBJECT(Mesh);
	SAFE_RETAIN(pMesh);

	pMesh->setMeshDetail(mesh);

	_meshes[id] = pMesh;
}

void Meshes::removeMesh(int id)
{
	auto it = _meshes.find(id);
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

Mesh* Meshes::getMesh(int id)
{
	auto it = _meshes.find(id);
	if (it == _meshes.end())
	{
		return nullptr;
	}

	return it->second;
}

void render::Meshes::drawWithBufferObject(Node* node, Materials* mats)
{
	if (mats == nullptr)
	{
		return;
	}
	for (auto item : _meshes)
	{
		auto pMesh = item.second;
		auto nMatID = pMesh->getMeshDetail()->getMaterial();
		auto pMat = mats->getMaterial(nMatID);

		GLState::enable(EnableMode::TEXTURE_2D);

		pMat->beginApplyWithShader(node, pMesh, mats);

		pMesh->drawWithBufferObject();

		pMat->endApplyWithShader(pMesh);

		GLState::disable(EnableMode::TEXTURE_2D);

		GLTexture::bindTexture2D(0);
	}

	GLDebug::showError();
}

void render::Meshes::drawWithClientArray(Node* node, Materials* mats)
{
	if (mats == nullptr)
	{
		return;
	}
	for (auto item : _meshes)
	{
		auto pMesh = item.second;
		auto nMatID = pMesh->getMeshDetail()->getMaterial();
		auto pMat = mats->getMaterial(nMatID);

		GLState::enable(EnableMode::TEXTURE_2D);
		pMat->apply(mats);

		pMesh->drawWithClientArray();
		
		GLState::disable(EnableMode::TEXTURE_2D);

		GLTexture::bindTexture2D(0);
	}
}

void render::Meshes::updateBufferData()
{
	for (auto item : _meshes)
	{
		auto pMesh = item.second;

		pMesh->updateBufferData();
	}
}

const std::map<int, Mesh*>& render::Meshes::getMeshes() const
{
	return _meshes;
}


