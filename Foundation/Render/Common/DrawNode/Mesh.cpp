#include "Mesh.h"
#include "Common/Buffer/import.h"
#include "Common/Shader/import.h"
#include "Graphic/import.h"
#include "Material.h"
#include "Common/Node/Node.h"
#include "Common/Tool/Tool.h"
#include "Common/VAO/import.h"
using namespace render;

render::Mesh::Mesh()
{

}

render::Mesh::~Mesh()
{
	this->removeAllMeshes();
	this->removeAllBufferObjects();
}

void render::Mesh::setModelDetail(const sys::ModelDetail* modelDetail)
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

void Mesh::addMesh(int id, sys::MeshDetail* mesh)
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

sys::MeshDetail* Mesh::getMesh(int id)
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

void render::Mesh::drawWithBufferObject(Node* node, Material* mat)
{
	if (mat == nullptr)
	{
		return;
	}
	for (auto item : _meshes)
	{
		auto pMesh = item.second;

		uint32_t id = item.first;

		VertexArrayObject* pVertexArrayObject = _vertexArrayObjects[id];
		if (!pVertexArrayObject)
		{
			continue;
		}

		ArrayBufferObject* pVertexObject = _vertexObjects[id];
		if (!pVertexObject)
		{
			continue;
		}

		uint32_t nVerticeSize = pMesh->getVertices().getSize();
		uint32_t nColorSize = pMesh->getColors().getSize();
		uint32_t nUVSize = pMesh->getUVs().getSize();
		uint32_t nNormalSize = pMesh->getNormals().getSize();

		if (nVerticeSize == 0)
		{
			PRINT("Mesh Vertice is NULL\n");
			continue;
		}
		if (nColorSize == 0 && nUVSize == 0)
		{
			PRINT("Mesh Color or UI is NULL\n");
			continue;
		}
		if (mat->getShaderProgram())
		{
			mat->getShaderProgram()->use();
		}

		pVertexArrayObject->bindVertexArray();
		pVertexArrayObject->bindBuffer();

		uint32_t nTotalSize = nVerticeSize + nColorSize + nUVSize + nNormalSize;
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

		mat->startUpdateShaderUniformValue(node);
		mat->startUpdateShaderVertexValue(pVertexArrayObject, pMesh);

		GLState::enable(EnableMode::TEXTURE_2D);
		auto nMatID = pMesh->getMaterial();
		mat->applyMaterialWithShader(nMatID);

		GLDebug::showError();

		ElementArrayBufferObject* pIndiceObject = _indiceObjects[id];
		if (pIndiceObject)
		{
			pIndiceObject->bindBuffer();
			pIndiceObject->setElementData(pMesh->getIndices());
		}

		uint32_t nIndiceLength = pMesh->getIndices().getLength();
		GLBufferObjects::drawElements(DrawMode::TRIANGLES, nIndiceLength, IndexDataType::UNSIGNED_INT, nullptr);

		GLDebug::showError();
		
		mat->endUpdateShaderVertexValue(pVertexArrayObject);
		mat->endUpdateShaderUniformValue();

		GLState::disable(EnableMode::TEXTURE_2D);
		GLShader::useProgram(0);
		GLDebug::showError();
	}

	GLDebug::showError();
}

void render::Mesh::drawWithClientArray(Node* node, Material* mat)
{
	if (mat == nullptr)
	{
		return;
	}
	for (auto item : _meshes)
	{
		auto pMesh = item.second;
		
		const sys::MeshMemoryData& vertices = pMesh->getVertices();
		const sys::MeshMemoryData& colors = pMesh->getColors();
		const sys::MeshMemoryData& texcoords = pMesh->getUVs();
		const sys::MeshMemoryData& normals = pMesh->getNormals();
		if (vertices.getLength() == 0)
		{
			PRINT("Mesh Vertice is NULL\n");
			continue;
		}
		if (colors.getLength() == 0 && texcoords.getLength() == 0)
		{
			PRINT("Mesh Color or UI is NULL\n");
			continue;
		}

		if (vertices.getLength() > 0)
		{
			GLClientArrays::enableClientState(ClientArrayType::VERTEX_ARRAY);
			GLClientArrays::setVertexPointer(vertices.getUnitSize(), DataType::FLOAT, 0, vertices.getValue());
			GLDebug::showError();
		}
		if (colors.getLength() > 0)
		{
			GLClientArrays::enableClientState(ClientArrayType::COLOR_ARRAY);
			GLClientArrays::setColorPointer(colors.getUnitSize(), DataType::FLOAT, 0, colors.getValue());
			GLDebug::showError();
		}
		
		if (texcoords.getLength() > 0)
		{
			GLClientArrays::enableClientState(ClientArrayType::TEXTURE_COORD_ARRAY);
			GLClientArrays::setTexCoordPointer(texcoords.getUnitSize(), DataType::FLOAT, 0, texcoords.getValue());
			GLDebug::showError();
		}
		
		if (normals.getLength() > 0)
		{
			GLClientArrays::enableClientState(ClientArrayType::NORMAL_ARRAY);
			GLClientArrays::setNormalPointer(DataType::FLOAT, 0, normals.getValue());
			GLDebug::showError();
		}

		GLState::enable(EnableMode::TEXTURE_2D);
		auto nMatID = pMesh->getMaterial();
		mat->applyMaterial(nMatID);

		const sys::MeshMemoryData& indices = pMesh->getIndices();
		if (indices.getLength() > 0)
		{
			GLClientArrays::drawElements(DrawMode::TRIANGLES, indices.getLength(), IndexDataType::UNSIGNED_INT, indices.getValue());
			GLDebug::showError();
		}
		GLState::disable(EnableMode::TEXTURE_2D);

		GLClientArrays::disableClientState(ClientArrayType::VERTEX_ARRAY);
		GLClientArrays::disableClientState(ClientArrayType::NORMAL_ARRAY);
		GLClientArrays::disableClientState(ClientArrayType::TEXTURE_COORD_ARRAY);
		GLClientArrays::disableClientState(ClientArrayType::COLOR_ARRAY);

		//GLMatrix::multMatrix(inverse);
	}
}

void render::Mesh::initBufferData()
{
	for (auto item : _meshes)
	{
		auto pMesh = item.second;

		uint32_t id = item.first;

		auto it1 = _indiceObjects.find(id);
		if (it1 == _indiceObjects.end())
		{
			ElementArrayBufferObject* obj = CREATE_OBJECT(ElementArrayBufferObject);
			SAFE_RETAIN(obj);
			_indiceObjects[id] = obj;
		}

		auto it0 = _vertexArrayObjects.find(id);
		if (it0 == _vertexArrayObjects.end())
		{
			VertexArrayObject* obj = CREATE_OBJECT(VertexArrayObject);
			SAFE_RETAIN(obj);
			_vertexArrayObjects[id] = obj;
		}

		auto it2 = _vertexObjects.find(id);
		if (it2 == _vertexObjects.end())
		{
			ArrayBufferObject* obj = CREATE_OBJECT(ArrayBufferObject);
			SAFE_RETAIN(obj);

			auto pVertexArrayObject = _vertexArrayObjects[id];
			pVertexArrayObject->setBufferObject(obj);

			_vertexObjects[id] = obj;
		}
		GLDebug::showError();
	}
	GLDebug::showError();
}

void render::Mesh::updateVerticeData()
{
	for (auto item : _meshes)
	{
		auto pMesh = item.second;

		uint32_t nLength = pMesh->getVertices().getLength();
		uint32_t nUnitSize = pMesh->getVertices().getUnitSize();
		uint32_t nTypeSize = pMesh->getVertices().getTypeSize();
		if (nLength > 0)
		{
			int k = nLength / nUnitSize;
			for (int i = 0; i < k; i++)
			{
				auto ptr = (float*)pMesh->getVertices().getPtr(i * nUnitSize);
				float x = *(ptr);
				float y = *(ptr + 1);
				float z = *(ptr + 2);

				math::Vector3 vector = Tool::convertToOGLPoisition(x, y, z);
				memcpy(ptr, vector.getValue(), nTypeSize);
				memcpy(ptr + 1, vector.getValue() + 1, nTypeSize);
				memcpy(ptr + 2, vector.getValue() + 2, nTypeSize);

				x = *(ptr);
				y = *(ptr + 1);
				z = *(ptr + 2);
			}
		}
	}
}

const std::map<int, sys::MeshDetail*>& render::Mesh::getMeshes() const
{
	return _meshes;
}


