#include "Mesh.h"
#include "Common/Buffer/import.h"
#include "Common/VAO/import.h"
#include "Graphic/import.h"
#include "Common/Material/import.h"

render::Mesh::Mesh()
{
	_vertexArrayObject = CREATE_OBJECT(VertexArrayObject);
	SAFE_RETAIN(_vertexArrayObject);

	_vertexBuffer = CREATE_OBJECT(ArrayBuffer);
	SAFE_RETAIN(_vertexBuffer);

	_indiceBuffer = CREATE_OBJECT(ElementArrayBuffer);
	SAFE_RETAIN(_indiceBuffer);

	_vertexArrayObject->setBuffer(_vertexBuffer);
}

render::Mesh::~Mesh()
{
	SAFE_RELEASE(_detail);
	SAFE_RELEASE(_vertexArrayObject);
	SAFE_RELEASE(_indiceBuffer);
	SAFE_RELEASE(_vertexBuffer);
}

void render::Mesh::setMeshDetail(sys::MeshDetail* detail)
{
	SAFE_RELEASE(_detail);
	SAFE_RETAIN(detail);

	_detail = detail;
}

sys::MeshDetail* render::Mesh::getMeshDetail() const
{
	return _detail;
}

render::VertexArrayObject* render::Mesh::getVertexArrayObject() const
{
	return _vertexArrayObject;
}

render::ElementArrayBuffer* render::Mesh::getIndiceBuffer() const
{
	return _indiceBuffer;
}

render::ArrayBuffer* render::Mesh::getVertexBuffer() const
{
	return _vertexBuffer;
}

void render::Mesh::setDrawMode(DrawMode mode)
{
	_drawMode = mode;
}

DrawMode render::Mesh::getDrawMode() const
{
	return _drawMode;
}

void render::Mesh::drawWithBufferObject()
{
	if (_detail == nullptr)
	{
		return;
	}
	uint32_t nVerticeSize = _detail->getVertices().getSize();
	uint32_t nColorSize = _detail->getColors().getSize();
	uint32_t nUVSize = _detail->getUVs().getSize();
	uint32_t nNormalSize = _detail->getNormals().getSize();

	if (nVerticeSize == 0)
	{
		PRINT("Mesh Vertice is NULL\n");
		return;
	}
	/*
	if (nColorSize == 0 && nUVSize == 0)
	{
		PRINT("Mesh Color or UI is NULL\n");
		return;
	}
	*/
	GLDebug::showError();
	_indiceBuffer->bindBuffer();

	uint32_t nIndiceLength = _detail->getIndices().getLength();
	GLBufferObjects::drawElements(_drawMode, nIndiceLength, IndexDataType::UNSIGNED_INT, nullptr);

	GLDebug::showError();
}

void render::Mesh::drawWithClientArray()
{
	if (_detail == nullptr)
	{
		return;
	}
	const sys::MeshMemoryData& vertices = _detail->getVertices();
	const sys::MeshMemoryData& colors = _detail->getColors();
	const sys::MeshMemoryData& texcoords = _detail->getUVs();
	const sys::MeshMemoryData& normals = _detail->getNormals();
	if (vertices.getLength() == 0)
	{
		PRINT("Mesh Vertice is NULL\n");
		return;
	}
	/*
	if (colors.getLength() == 0 && texcoords.getLength() == 0)
	{
		PRINT("Mesh Color or UI is NULL\n");
		return;
	}
	*/
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

	const sys::MeshMemoryData& indices = _detail->getIndices();
	if (indices.getLength() > 0)
	{
		GLClientArrays::drawElements(_drawMode, indices.getLength(), IndexDataType::UNSIGNED_INT, indices.getValue());
		GLDebug::showError();
	}

	GLClientArrays::disableClientState(ClientArrayType::VERTEX_ARRAY);
	GLClientArrays::disableClientState(ClientArrayType::NORMAL_ARRAY);
	GLClientArrays::disableClientState(ClientArrayType::TEXTURE_COORD_ARRAY);
	GLClientArrays::disableClientState(ClientArrayType::COLOR_ARRAY);
}

void render::Mesh::updateBufferData()
{
	if (!_detail)
	{
		return;
	}

	uint32_t nVerticeSize = _detail->getVertices().getSize();
	uint32_t nColorSize = _detail->getColors().getSize();
	uint32_t nUVSize = _detail->getUVs().getSize();
	uint32_t nNormalSize = _detail->getNormals().getSize();

	if (nVerticeSize == 0)
	{
		PRINT("Mesh Vertice is NULL\n");
		return;
	}
	/*
	if (nColorSize == 0 && nUVSize == 0)
	{
		PRINT("Mesh Color or UI is NULL\n");
		return;
	}
	*/
	_vertexBuffer->bindBuffer();

	GLDebug::showError();

	uint32_t nTotalSize = nVerticeSize + nColorSize + nUVSize + nNormalSize;
	_vertexBuffer->setBufferData(nTotalSize, nullptr, BufferDataUsage::STATIC_DRAW);
	if (nVerticeSize > 0)
	{
		_vertexBuffer->setBufferSubData(0, nVerticeSize, _detail->getVertices().getPtr());
	}
	if (nColorSize > 0)
	{
		_vertexBuffer->setBufferSubData(nVerticeSize, nColorSize, _detail->getColors().getPtr());
	}
	if (nUVSize > 0)
	{
		_vertexBuffer->setBufferSubData(nVerticeSize + nColorSize, nUVSize, _detail->getUVs().getPtr());
	}
	if (nNormalSize > 0)
	{
		_vertexBuffer->setBufferSubData(nVerticeSize + nColorSize + nUVSize, nNormalSize, _detail->getNormals().getPtr());
	}
	_vertexBuffer->unbindBuffer();
	GLDebug::showError();
	_indiceBuffer->bindBuffer();
	GLDebug::showError();
	_indiceBuffer->setElementData(_detail->getIndices());
	GLDebug::showError();
	_indiceBuffer->unbindBuffer();
	GLDebug::showError();
}

