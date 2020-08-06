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
	_indiceBuffer->setElementData(_detail->getIndices());
	_indiceBuffer->unbindBuffer();
	GLDebug::showError();
}

void render::Mesh::initDetailNormalData()
{
	if (getMeshDetail()->getVertices().getSize() == 0)
	{
		return;
	}

	int nSize = getMeshDetail()->getVertices().getSize();
	int nCount = getMeshDetail()->getVertices().getLength();
	int nUnitSize = getMeshDetail()->getVertices().getUnitSize();

	int nLength = nCount / nUnitSize;

	float* normals = (float*)malloc(nSize);
	this->calTrianglesVertexNormal(getMeshDetail()->getVertices(), getMeshDetail()->getIndices(), normals);
	getMeshDetail()->setNormals(nLength, normals, nUnitSize);
	free(normals);
}

class mycompare {
public:
	bool operator()(const math::Vector3& _Left, const math::Vector3& _Right)const {
		return _Left.toString() < _Right.toString();
	}
};

void render::Mesh::calTrianglesVertexNormal(const sys::MeshMemoryData& vertices, const sys::MeshMemoryData& indices, float* normals)
{
	int nUnitSize = vertices.getUnitSize();
	int nVerticeCount = vertices.getLength() / nUnitSize;

	float* pVerticeData = (float*)vertices.getValue();

	if (nVerticeCount < 3)
	{
		return;
	}

	if (!(nUnitSize == 2 || nUnitSize == 3))
	{
		return;
	}

	std::vector<math::Vector3> vecPoint;

	for (int i = 0 ; i < nVerticeCount; i++)
	{
		math::Vector3 pos;
		if (nUnitSize == 2)
		{
			pos = math::Vector3(pVerticeData[i * nUnitSize], pVerticeData[i * nUnitSize + 1]);
		}
		else if (nUnitSize == 3)
		{
			pos = math::Vector3(pVerticeData[i * nUnitSize], pVerticeData[i * nUnitSize + 1], pVerticeData[i * nUnitSize + 2]);
		}
		vecPoint.push_back(pos);
	}

	int nPointCount = indices.getLength() / indices.getUnitSize();
	int nTriangleCount = nPointCount / 3;

	uint32_t* pIndice = (uint32_t*)indices.getValue();

	std::map<int, std::vector<math::Vector3>> mapPointNormal;
	for (int i = 0; i < nTriangleCount; i++)
	{
		math::Vector3 p0 = vecPoint[pIndice[i * 3 + 0]];
		math::Vector3 p1 = vecPoint[pIndice[i * 3 + 1]];
		math::Vector3 p2 = vecPoint[pIndice[i * 3 + 2]];

		math::Vector3 normal = math::Vector3::cross(p1 - p0, p2 - p0);

		mapPointNormal[pIndice[i * 3 + 0]].push_back(normal);
		mapPointNormal[pIndice[i * 3 + 1]].push_back(normal);
		mapPointNormal[pIndice[i * 3 + 2]].push_back(normal);
	}

	for (int i = 0; i < nVerticeCount; i++)
	{
		math::Vector3 normal;
		if (mapPointNormal[i].empty())
		{
			normal = math::Vector3(0, 1, 0);
		}
		else
		{
			for (auto item : mapPointNormal[i])
			{
				normal += item;
			}
			normal /= mapPointNormal[i].size();
			normal.normalize();
		}
		memcpy(normals + i * 3, normal.getValue(), 3 * sizeof(float));
	}

	int a = 1;
}

