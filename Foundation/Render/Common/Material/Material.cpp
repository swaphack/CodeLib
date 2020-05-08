#include "Material.h"
#include "Resource/Detail/ModelDetail.h"
#include "Resource/Detail/MaterialDetail.h"
#include "Resource/Detail/MeshDetail.h"
#include "Graphic/import.h"
#include "Common/Shader/import.h"
#include "Common/Buffer/import.h"
#include "Common/View/import.h"

using namespace render;

render::Material::Material()
{

}

render::Material::~Material()
{
	SAFE_RELEASE(_modelDetail);
	SAFE_RELEASE(_shaderProgram);
}

void render::Material::setModelDetail(ModelDetail* modelDetail)
{
	SAFE_RELEASE(_modelDetail);
	SAFE_RETAIN(modelDetail);

	_modelDetail = modelDetail;
}

render::ModelDetail* render::Material::getModelDetail()
{
	return _modelDetail;
}

void render::Material::setShaderProgram(ShaderProgram* shaderProgram)
{
	SAFE_RELEASE(_shaderProgram);
	SAFE_RETAIN(shaderProgram);

	_shaderProgram = shaderProgram;
}

render::ShaderProgram* render::Material::getShaderProgram()
{
	return _shaderProgram;
}

void render::Material::addVertexAttrib(VertexAttribType vat, uint32_t index)
{
	_vertexAttribIndices[vat] = index;
}

int32_t render::Material::getVertexAttribIndex(VertexAttribType vat)
{
	auto it = _vertexAttribIndices.find(vat);
	if (it == _vertexAttribIndices.end())
	{
		return -1;
	}

	return it->second;
}

void render::Material::removeVertexAttribIndices()
{
	_vertexAttribIndices.clear();
}

void render::Material::addVertexUniform(VertexAttribType vat, uint32_t index)
{
	_vertexAttribIndices[vat] = index;
}

int32_t render::Material::getVertexUniformIndex(VertexAttribType vat)
{
	auto it = _vertexAttribIndices.find(vat);
	if (it == _vertexAttribIndices.end())
	{
		return -1;
	}

	return it->second;
}

void render::Material::removeVertexUniformIndices()
{
	_vertexUniformIndices.clear();
}

void render::Material::draw(const math::Matrix44& projMat, const math::Matrix44& viewMat, const math::Matrix44& modelMat)
{
	if (_modelDetail == nullptr)
	{
		return;
	}

	if (_shaderProgram == nullptr)
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
		GLDebug::showError();

		_shaderProgram->use();
		{
			auto pUniform = _shaderProgram->getUniform("projMat");
			if (pUniform) pUniform->setMatrix4(1, false, projMat.getValue());

			pUniform = _shaderProgram->getUniform("viewMat");
			if (pUniform) pUniform->setMatrix4(1, false, viewMat.getValue());

			pUniform = _shaderProgram->getUniform("modelMat");
			if (pUniform) pUniform->setMatrix4(1, false, modelMat.getValue());
		}

		pVertexArrayObject->bindVertexArray();
		pVertexArrayObject->bindBuffer();

		uint32_t nVerticeSize = pMesh->getVertices().getSize();
		uint32_t nColorSize = pMesh->getColors().getSize();
		uint32_t nUVSize = pMesh->getUVs().getSize();

		uint32_t nNormalSize = pMesh->getNormals().getSize();

		VertexAttribPointer* pointer0 = nullptr;
		VertexAttribPointer* pointer1 = nullptr;
		VertexAttribPointer* pointer2 = nullptr;
		int index = this->getVertexAttribIndex(VertexAttribType::POSITION);
		if (index >= 0)
		{
			pointer0 = pVertexArrayObject->getVertexAttrib<VertexAttribPointer>(index);
		}

		index = this->getVertexAttribIndex(VertexAttribType::COLOR);
		if (index >= 0)
		{
			pointer1 = pVertexArrayObject->getVertexAttrib<VertexAttribPointer>(index);
		}

		index = this->getVertexAttribIndex(VertexAttribType::UV);
		if (index >= 0)
		{
			pointer2 = pVertexArrayObject->getVertexAttrib<VertexAttribPointer>(index);
		}

		if (pointer0 && nVerticeSize > 0)
		{
			pointer0->enableVertexArrayAttrib();
			pointer0->setVertexAttribPointer(3, VertexAttribPointerType::FLOAT, 0);
			GLDebug::showError();
		}

		if (pointer1 && nColorSize > 0)
		{
			pointer1->enableVertexArrayAttrib();
			pointer1->setVertexAttribPointer(4, VertexAttribPointerType::FLOAT, nVerticeSize);
			GLDebug::showError();
		}

		if (pointer2 && nUVSize > 0)
		{
			pointer2->enableVertexArrayAttrib();
			pointer2->setVertexAttribPointer(2, VertexAttribPointerType::FLOAT, nVerticeSize + nColorSize);
			GLDebug::showError();
		}

		auto nMatID = pMesh->getMaterial();
		this->applyMatToMesh(nMatID);

		GLDebug::showError();
		const MeshMemoryData& indices = pMesh->getIndices();
		uint32_t nIndiceLength = indices.getLength();

		pIndiceObject->bindBuffer();
		GLBufferObjects::drawElements(DrawMode::TRIANGLES, nIndiceLength, IndexDataType::UNSIGNED_INT, (void*)0);

		GLDebug::showError();
		if (pointer0)
		{
			pointer0->disableVertexArrayAttrib();
		}
		if (pointer1)
		{
			pointer1->disableVertexArrayAttrib();
		}
		if (pointer2)
		{
			pointer2->disableVertexArrayAttrib();;
		}

		ShaderProgram::useNone();

		GLState::disable(EnableModel::TEXTURE_2D);

		GLDebug::showError();
	}
}

void render::Material::applyMatToMesh(uint32_t nMatID)
{
	if (_modelDetail == nullptr)
	{
		return;
	}
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

void render::Material::updateMatTexture()
{
	if (_modelDetail == nullptr)
	{
		return;
	}
	for (auto item : _modelDetail->getTexturePaths())
	{
		Texture2D* pTexture = _modelDetail->createTexture(item.second);
		if (pTexture)
		{
			_modelDetail->addTexture(item.first, pTexture);
		}
	}

	_modelDetail->removeAllTexturePaths();
}

void render::Material::updateBufferData()
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
			uint32_t nIndiceLength = pMesh->getIndices().getLength();
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

void render::Material::removeAllBufferObjects()
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
