#include "Mesh.h"
#include "Common/Buffer/import.h"
#include "Common/Shader/import.h"
#include "Resource/Detail/ModelDetail.h"
#include "Resource/Detail/MeshDetail.h"
#include "Graphic/import.h"
#include "Material.h"
#include "Node.h"

using namespace render;

render::Mesh::Mesh()
{

}

render::Mesh::~Mesh()
{
	this->removeAllMeshes();
	this->removeAllBufferObjects();
}

void render::Mesh::setModelDetail(const ModelDetail* modelDetail)
{
	if (modelDetail == nullptr)
	{
		return;
	}

	this->removeAllMeshes();
	this->removeAllBufferObjects();

	for (auto item : modelDetail->getMeshes())
	{
		this->addMesh(item.first, item.second);
	}
}

void Mesh::addMesh(int id, MeshDetail* mesh)
{
	if (mesh == nullptr)
	{
		return;
	}

	this->removeMesh(id);

	SAFE_RETAIN(mesh);

	_meshes[id] = mesh;
}

void Mesh::removeMesh(int id)
{
	auto it = _meshes.find(id);
	if (it == _meshes.end())
	{
		return;
	}

	SAFE_RELEASE(it->second);
	_meshes.erase(it);
}

void Mesh::removeAllMeshes()
{
	for (auto it : _meshes)
	{
		SAFE_RELEASE(it.second);
	}
	_meshes.clear();
}

MeshDetail* Mesh::getMesh(int id)
{
	auto it = _meshes.find(id);
	if (it == _meshes.end())
	{
		return nullptr;
	}

	return it->second;
}


void render::Mesh::removeAllBufferObjects()
{
	for (auto item : _indiceObjects)
	{
		SAFE_RELEASE(item.second);
	}

	for (auto item : _vertexObjects)
	{
		SAFE_RELEASE(item.second);
	}

	for (auto item : _vertexArrayObjects)
	{
		SAFE_RELEASE(item.second);
	}

	_indiceObjects.clear();
	_vertexObjects.clear();
	_vertexArrayObjects.clear();
}

void render::Mesh::draw(Node* node, Material* mat)
{
	for (auto item : _meshes)
	{
		auto pMesh = item.second;

		uint32_t id = item.first;

		VertexArrayObject* pVertexArrayObject = _vertexArrayObjects[id];
		if (pVertexArrayObject == nullptr)
		{
			continue;
		}

		NoNamedBufferObject* pIndiceObject = _indiceObjects[id];
		if (pIndiceObject == nullptr)
		{
			continue;
		}

		GLDebug::showError();

		mat->startUpdateShaderUniformValue(node);
		mat->startUpdateShaderVertexValue(pVertexArrayObject, pMesh);

		auto nMatID = pMesh->getMaterial();
		mat->applyMat(nMatID);

		GLDebug::showError();

		pIndiceObject->bindBuffer();
		uint32_t nIndiceLength = pMesh->getIndices().getLength();
		GLBufferObjects::drawElements(DrawMode::TRIANGLES, nIndiceLength, IndexDataType::UNSIGNED_INT, (void*)0);

		GLDebug::showError();
		
		mat->endUpdateShaderVertexValue(pVertexArrayObject);
		mat->endUpdateShaderUniformValue();

		GLState::disable(EnableModel::TEXTURE_2D);

		GLDebug::showError();
	}
}

void render::Mesh::updateBufferData()
{
	for (auto item : _meshes)
	{
		auto pMesh = item.second;

		uint32_t id = item.first;

		auto it0 = _vertexArrayObjects.find(id);
		if (it0 == _vertexArrayObjects.end())
		{
			VertexArrayObject* obj = CREATE_OBJECT(VertexArrayObject);
			SAFE_RETAIN(obj);
			_vertexArrayObjects[id] = obj;
		}

		auto it1 = _indiceObjects.find(id);
		if (it1 == _indiceObjects.end())
		{
			NoNamedBufferObject* obj = CREATE_OBJECT(NoNamedBufferObject);
			SAFE_RETAIN(obj);
			obj->setBufferTarget(BufferTarget::ELEMENT_ARRAY_BUFFER);
			_indiceObjects[id] = obj;
		}

		NoNamedBufferObject* pIndiceObject = _indiceObjects[id];
		if (pIndiceObject)
		{
			pIndiceObject->bindBuffer();

			uint32_t nIndiceSize = pMesh->getIndices().getSize();
			pIndiceObject->setBufferData(nIndiceSize, pMesh->getIndices().getValue(), BufferDataUsage::STATIC_DRAW);
		}

		auto it2 = _vertexObjects.find(id);
		if (it2 == _vertexObjects.end())
		{
			NoNamedBufferObject* obj = CREATE_OBJECT(NoNamedBufferObject);
			SAFE_RETAIN(obj);
			obj->setBufferTarget(BufferTarget::ARRAY_BUFFER);

			auto pVertexArrayObject = _vertexArrayObjects[id];
			pVertexArrayObject->setBufferObject(obj);

			_vertexObjects[id] = obj;
		}

		NoNamedBufferObject* pVertexObject = _vertexObjects[id];
		if (pVertexObject)
		{
			uint32_t nVerticeSize = pMesh->getVertices().getSize();
			uint32_t nColorSize = pMesh->getColors().getSize();
			uint32_t nUVSize = pMesh->getUVs().getSize();
			uint32_t nNormalSize = pMesh->getNormals().getSize();

			uint32_t nTotalSize = nVerticeSize + nColorSize + nUVSize + nNormalSize;
			pVertexObject->bindBuffer();
			pVertexObject->setBufferData(nTotalSize, nullptr, BufferDataUsage::STATIC_DRAW);
			if (nVerticeSize > 0)
			{
				pVertexObject->setBufferSubData(0, nVerticeSize, pMesh->getVertices().getPtr());
			}
			GLDebug::showError();
			if (nColorSize > 0)
			{
				pVertexObject->setBufferSubData(nVerticeSize, nColorSize, pMesh->getColors().getPtr());
			}
			GLDebug::showError();
			if (nUVSize > 0)
			{
				pVertexObject->setBufferSubData(nVerticeSize + nColorSize, nUVSize, pMesh->getUVs().getPtr());
			}
			GLDebug::showError();
			if (nNormalSize > 0)
			{
				pVertexObject->setBufferSubData(nVerticeSize + nColorSize + nUVSize, nNormalSize, pMesh->getNormals().getPtr());
			}
			GLDebug::showError();
		}

		GLDebug::showError();
	}
	GLDebug::showError();
}

const std::map<int, MeshDetail*>& render::Mesh::getMeshes() const
{
	return _meshes;
}


