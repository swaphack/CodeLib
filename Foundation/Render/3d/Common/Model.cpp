#include "Model.h"
#include "Resource/Detail/ModelDetail.h"
#include "Resource/Detail/MaterialDetail.h"
#include "Resource/Detail/MeshDetail.h"
#include "Graphic/import.h"

#include "Common/Buffer/NoNamedBufferObject.h"
#include "Common/Buffer/VertexArrayObject.h"

using namespace render;


Model::Model()
{
}

Model::~Model()
{
	removeAllBufferObjects();
	SAFE_DELETE(_modelDetail);
}

void Model::drawSample()
{
	this->drawSampleWithClientArray();
	//this->drawSampleWithBufferObject();
}

void Model::setModelData(const ModelDetail* detail)
{
	SAFE_DELETE(_modelDetail);
	_modelDetail = (ModelDetail*)detail;
}

const ModelDetail* Model::getModelData()
{
	return _modelDetail;
}

void render::Model::drawSampleWithClientArray()
{
	if (_modelDetail == nullptr)
	{
		return;
	}

	//PRINT("=============begin=============\n");

	const std::map<int, MeshDetail*>& meshes = _modelDetail->getMeshes();
	for (auto item : meshes)
	{
		//auto mat = item0.second->getMatrix();
		//auto inverse = mat.getInverse();

		//GLMatrix::multMatrix(mat);

		auto pMesh = item.second;

		const MeshMemoryData& normals = pMesh->getNormals();
		if (normals.getLength() > 0)
		{
			GLClientArrays::enableClientState(ClientArrayType::NORMAL_ARRAY);
			GLClientArrays::setNormalPointer(DataType::FLOAT, 0, normals.getValue());

		}
		const MeshMemoryData& vertices = pMesh->getVertices();
		if (vertices.getLength() > 0)
		{
			GLClientArrays::enableClientState(ClientArrayType::VERTEX_ARRAY);
			GLClientArrays::setVertexPointer(vertices.getTypeSize(), DataType::FLOAT, 0, vertices.getValue());

		}
		const MeshMemoryData& texcoords = pMesh->getUVs();
		if (texcoords.getLength() > 0)
		{
			GLClientArrays::enableClientState(ClientArrayType::TEXTURE_COORD_ARRAY);
			GLClientArrays::setTexCoordPointer(texcoords.getTypeSize(), DataType::FLOAT, 0, texcoords.getValue());
		}

		const MeshMemoryData& colors = pMesh->getColors();
		if (colors.getLength() > 0)
		{
			GLClientArrays::enableClientState(ClientArrayType::COLOR_ARRAY);
			GLClientArrays::setColorPointer(colors.getTypeSize(), DataType::FLOAT, 0, colors.getValue());
		}

		auto nMatID = pMesh->getMaterial();
		this->applyMatToMesh(nMatID);

		const MeshMemoryData& indices = pMesh->getIndices();
		if (indices.getLength() > 0)
		{
			GLClientArrays::drawElements(DrawMode::TRIANGLES, indices.getLength(), IndexDataType::UNSIGNED_INT, indices.getValue());
		}
		GLState::disable(EnableModel::TEXTURE_2D);

		GLClientArrays::disableClientState(ClientArrayType::VERTEX_ARRAY);
		GLClientArrays::disableClientState(ClientArrayType::NORMAL_ARRAY);
		GLClientArrays::disableClientState(ClientArrayType::TEXTURE_COORD_ARRAY);
		GLClientArrays::disableClientState(ClientArrayType::COLOR_ARRAY);

		//GLMatrix::multMatrix(inverse);
	}

	//PRINT("=============end=============\n");
}

void render::Model::drawSampleWithBufferObject()
{
	if (_modelDetail == nullptr)
	{
		return;
	}

	if (_vertexArrayObject == nullptr)
	{
		_vertexArrayObject = CREATE_OBJECT(VertexArrayObject);
		SAFE_RETAIN(_vertexArrayObject);
	}

	if (_vertexArrayObject == nullptr)
	{
		return;
	}

	const std::map<int, MeshDetail*>& meshes = _modelDetail->getMeshes();
	for (auto item : meshes)
	{
		auto pMesh = item.second;

		auto it1 = _indiceObjects.find(item.first);
		if (it1 == _indiceObjects.end())
		{
			NoNamedBufferObject* obj = CREATE_OBJECT(NoNamedBufferObject);
			SAFE_RETAIN(obj);
			obj->setBufferTarget(BufferTarget::ELEMENT_ARRAY_BUFFER);
			_indiceObjects[item.first] = obj;
		}

		NoNamedBufferObject* pIndiceObject = _indiceObjects[item.first];
		if (pIndiceObject == nullptr)
		{
			continue;
		}

		pIndiceObject->bindBuffer();

		uint32_t nIndiceSize = pMesh->getIndices().getSize();
		uint32_t nIndiceLength = pMesh->getIndices().getLength();
		pIndiceObject->setBufferData(nIndiceSize, pMesh->getIndices().getValue(), BufferDataUsage::STATIC_DRAW);

		auto it0 = _vertexObjects.find(item.first);
		if (it0 == _vertexObjects.end())
		{
			NoNamedBufferObject* obj = CREATE_OBJECT(NoNamedBufferObject);
			SAFE_RETAIN(obj);
			obj->setBufferTarget(BufferTarget::ARRAY_BUFFER);
			_vertexObjects[item.first] = obj;
		}

		NoNamedBufferObject* pVertexObject = _vertexObjects[item.first];
		if (pVertexObject == nullptr)
		{
			continue;
		}

		_vertexArrayObject->bindVertexArray();
		_vertexArrayObject->setBufferObject(pVertexObject);
		_vertexArrayObject->bindBuffer();

		uint32_t nVerticeSize = pMesh->getVertices().getSize();
		uint32_t nNormalSize = pMesh->getNormals().getSize();
		uint32_t nColorSize = pMesh->getColors().getSize();
		uint32_t nUVSize = pMesh->getUVs().getSize();

		uint32_t nTotalSize = nVerticeSize + nNormalSize + nColorSize + nUVSize;

		pVertexObject->setBufferData(nTotalSize, nullptr, BufferDataUsage::STATIC_DRAW);
		if (nVerticeSize > 0)
		{
			pVertexObject->setBufferSubData(0, nVerticeSize, pMesh->getVertices().getPtr());
		}
		if (nNormalSize > 0)
		{
			pVertexObject->setBufferSubData(nVerticeSize, nNormalSize, pMesh->getNormals().getPtr());
		}
		if (nColorSize > 0)
		{
			pVertexObject->setBufferSubData(nVerticeSize + nNormalSize, nColorSize, pMesh->getColors().getPtr());
		}
		if (nUVSize > 0)
		{
			pVertexObject->setBufferSubData(nVerticeSize + nNormalSize + nColorSize, nUVSize, pMesh->getUVs().getPtr());
		}

		auto nMatID = pMesh->getMaterial();
		this->applyMatToMesh(nMatID);

		GLBufferObjects::drawElements(DrawMode::TRIANGLES, nIndiceLength, IndexDataType::UNSIGNED_INT, nullptr);

		GLState::disable(EnableModel::TEXTURE_2D);
	}
}

void render::Model::removeAllBufferObjects()
{
	for (auto item : _indiceObjects)
	{
		SAFE_RELEASE(item.second);
	}

	for (auto item : _vertexObjects)
	{
		SAFE_RELEASE(item.second);
	}

	_indiceObjects.clear();
	_vertexObjects.clear();
	SAFE_RELEASE(_vertexArrayObject);
}

void render::Model::applyMatToMesh(uint32_t nMatID)
{
	auto pMat = _modelDetail->getMaterial(nMatID);
	if (pMat)
	{
		pMat->apply();

		auto nTextureID1 = _modelDetail->getTexture(pMat->getAmbientTextureMap());
		auto nTextureID2 = _modelDetail->getTexture(pMat->getDiffuseTextureMap());
		if (nTextureID1 || nTextureID2)
		{
			GLState::enable(EnableModel::TEXTURE_2D);
			if (nTextureID1) GLTexture::bindTexture2D(nTextureID1);
			else if (nTextureID2) GLTexture::bindTexture2D(nTextureID2);
		}
	}
}
