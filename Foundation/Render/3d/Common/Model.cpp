#include "Model.h"
#include "Resource/Detail/ModelDetail.h"
#include "Resource/Detail/MaterialDetail.h"
#include "Resource/Detail/MeshDetail.h"
#include "Graphic/import.h"
#include "Common/Shader/ShaderProgram.h"
#include "Common/Buffer/import.h"

using namespace render;

#define USE_BUFFER_OBJECT 1


Model::Model()
{
}

Model::~Model()
{
#if USE_BUFFER_OBJECT
	removeAllBufferObjects();
#endif
	SAFE_DELETE(_modelDetail);
}

bool render::Model::init()
{
	if (!ColorNode::init())
	{
		return false;
	}
#if USE_BUFFER_OBJECT
	_notify->addListen(ENP_MODEL_FRAME, [this](){
		this->updateBufferData();
	});
	initBufferObject();
#endif
	return true;
}

void render::Model::initBufferObject()
{
}

void render::Model::updateBufferData()
{
	const std::map<int, MeshDetail*>& meshes = _modelDetail->getMeshes();
	for (auto item : meshes)
	{
		auto pMesh = item.second;

		uint32_t id = id;

		auto it0 = _vertexArrayObjects.find(id);
		if (it0 == _vertexArrayObjects.end())
		{
			VertexArrayObject* obj = CREATE_OBJECT(VertexArrayObject);
			SAFE_RETAIN(obj);
			_vertexArrayObjects[id] = obj;
		}

		auto pVertexArrayObject = _vertexArrayObjects[id];

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
			uint32_t nIndiceLength = pMesh->getIndices().getLength();
			pIndiceObject->setBufferData(nIndiceSize, pMesh->getIndices().getValue(), BufferDataUsage::STATIC_DRAW);
		}

		auto it2 = _vertexObjects.find(id);
		if (it2 == _vertexObjects.end())
		{
			NoNamedBufferObject* obj = CREATE_OBJECT(NoNamedBufferObject);
			SAFE_RETAIN(obj);
			obj->setBufferTarget(BufferTarget::ARRAY_BUFFER);
			_vertexObjects[id] = obj;
		}

		NoNamedBufferObject* pVertexObject = _vertexObjects[id];
		if (pVertexObject)
		{
			pVertexArrayObject->setBufferObject(pVertexObject);

			uint32_t nVerticeSize = pMesh->getVertices().getSize();
			uint32_t nNormalSize = pMesh->getNormals().getSize();
			uint32_t nColorSize = pMesh->getColors().getSize();
			uint32_t nUVSize = pMesh->getUVs().getSize();

			uint32_t nTotalSize = nVerticeSize + nNormalSize + nColorSize + nUVSize;
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

void Model::drawSample()
{

#if USE_BUFFER_OBJECT
	this->drawSampleWithBufferObject();
#else
	
	this->drawSampleWithClientArray();
#endif
}

void Model::setModelData(const ModelDetail* detail)
{
	SAFE_DELETE(_modelDetail);
	_modelDetail = (ModelDetail*)detail;

	this->notify(ENP_MODEL_FRAME);
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

	const std::map<int, MeshDetail*>& meshes = _modelDetail->getMeshes();
	for (auto item : meshes)
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

		NoNamedBufferObject* pVertexObject = _vertexObjects[id];
		if (pVertexObject == nullptr)
		{
			continue;
		}

		pVertexArrayObject->bindVertexArray();
		pVertexArrayObject->bindBuffer();

		uint32_t nVerticeSize = pMesh->getVertices().getSize();
		uint32_t nColorSize = pMesh->getColors().getSize();
		uint32_t nUVSize = pMesh->getUVs().getSize();

		uint32_t nNormalSize = pMesh->getNormals().getSize();

		VertexAttribPointer* pointer0 = pVertexArrayObject->getVertexAttrib<VertexAttribPointer>((uint32_t)VertexAttribType::POSITION);
		VertexAttribPointer* pointer1 = pVertexArrayObject->getVertexAttrib<VertexAttribPointer>((uint32_t)VertexAttribType::COLOR);
		VertexAttribPointer* pointer2 = pVertexArrayObject->getVertexAttrib<VertexAttribPointer>((uint32_t)VertexAttribType::UV);

		pointer0->setVertexAttribPointer(3, VertexAttribPointerType::FLOAT, 0);
		GLDebug::showError();

		pointer1->setVertexAttribPointer(4, VertexAttribPointerType::FLOAT, nVerticeSize);
		GLDebug::showError();

		pointer2->setVertexAttribPointer(2, VertexAttribPointerType::FLOAT, nVerticeSize + nColorSize);
		GLDebug::showError();

		auto nMatID = pMesh->getMaterial();
		this->applyMatToMesh(nMatID);


		if (getProgram())
		{
			getProgram()->use();
		}
		else
		{
			ShaderProgram::useNone();
		}

		GLDebug::showError();
		const MeshMemoryData& indices = pMesh->getIndices();
		uint32_t nIndiceLength = indices.getLength();

		pIndiceObject->bindBuffer();
		GLBufferObjects::drawElements(DrawMode::TRIANGLES, nIndiceLength, IndexDataType::UNSIGNED_INT, (void*)0);

		GLDebug::showError();
		pointer0->disableVertexArrayAttrib();
		pointer1->disableVertexArrayAttrib();
		pointer2->disableVertexArrayAttrib();

		GLState::disable(EnableModel::TEXTURE_2D);

		GLDebug::showError();
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

	for (auto item : _vertexArrayObjects)
	{
		SAFE_RELEASE(item.second);
	}

	_indiceObjects.clear();
	_vertexObjects.clear();
	_vertexArrayObjects.clear();
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
