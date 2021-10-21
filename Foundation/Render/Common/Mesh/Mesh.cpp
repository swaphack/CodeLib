#include "Mesh.h"
#include "Common/Buffer/import.h"
#include "Common/VAO/import.h"
#include "Graphic/import.h"
#include "Common/Material/import.h"
#include "Common/DrawNode/DrawCore.h"

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
	SAFE_RETAIN(detail);
	SAFE_RELEASE(_detail);
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

void render::Mesh::setVertices(int len, const float* vertexes, int unitSize)
{
	getMeshDetail()->setVertices(len, vertexes, unitSize);
}

void render::Mesh::setVertices(const std::vector<math::Vector3>& points)
{
	int nCount = points.size();
	int nLength = 3;
	auto pVertice = (float*)getMeshDetail()->createVertices(nCount, nLength);
	for (int i = 0; i < nCount; i++)
	{
		memcpy(pVertice + i * nLength, points[i].getValue(), nLength * sizeof(float));
	}
}

void render::Mesh::setNormals(int len, const float* normals, int unitSize)
{
	getMeshDetail()->setNormals(len, normals, unitSize);
}

void render::Mesh::setNormals(const std::vector<math::Vector3>& normals)
{
	int nCount = normals.size();
	int nLength = 3;
	auto pVertice = (float*)getMeshDetail()->createNormals(nCount, nLength);
	for (int i = 0; i < nCount; i++)
	{
		memcpy(pVertice + i * nLength, normals[i].getValue(), nLength * sizeof(float));
	}
}

void render::Mesh::setColors(int len, const float* colors, int unitSize)
{
	getMeshDetail()->setColors(len, colors, unitSize);
}

void render::Mesh::setColors(const std::vector<phy::Color4F>& colors)
{
	int nCount = colors.size();
	int nLength = 4;
	auto pVertice = (float*)getMeshDetail()->createColors(nCount, nLength);
	for (int i = 0; i < nCount; i++)
	{
		memcpy(pVertice + i * nLength, colors[i].getValue(), nLength * sizeof(float));
	}
}

void render::Mesh::setUVs(int len, const float* texCoords, int unitSize)
{
	getMeshDetail()->setUVs(len, texCoords, unitSize);
}

void render::Mesh::setUVs(const std::vector<math::Vector2>& uvs)
{
	int nCount = uvs.size();
	int nLength = 2;
	auto pVertice = (float*)getMeshDetail()->createUVs(nCount, nLength);
	for (int i = 0; i < nCount; i++)
	{
		memcpy(pVertice + i * nLength, uvs[i].getValue(), nLength * sizeof(float));
	}
}

void render::Mesh::setIndices(int size, const uint32_t* indices, int unitSize)
{
	getMeshDetail()->setIndices(size, indices, unitSize);
}

void render::Mesh::setIndices(const std::vector<int>& indices)
{
	int nCount = indices.size();
	int nLength =1;

	auto pVertice = (uint32_t*)getMeshDetail()->createIndices(nCount, nLength);

	memcpy(pVertice, &indices[0], nCount * sizeof(uint32_t));
}

void render::Mesh::setDrawMode(DrawMode mode)
{
	_drawMode = mode;
}

DrawMode render::Mesh::getDrawMode() const
{
	return _drawMode;
}

void render::Mesh::setComputeNormal(bool compute)
{
	_bComputeNormal = compute;
	if (compute == false)
	{
		getMeshDetail()->setNormals(0, nullptr);
	}
}

bool render::Mesh::isComputeNormal()
{
	return _bComputeNormal;
}

void render::Mesh::setComputeTangent(bool compute)
{
	_bComputeTangent = compute;
	if (compute == false)
	{
		getMeshDetail()->setTangents(0, nullptr);
	}
}

bool render::Mesh::isComputeTangent()
{
	return _bComputeTangent;
}

void render::Mesh::drawWithBufferObject()
{
	if (_detail == nullptr)
	{
		return;
	}
	uint32_t nVerticeSize = _detail->getVertices().getSize();

	if (nVerticeSize == 0)
	{
		return;
	}

	uint32_t nIndiceLength = _detail->getIndices().getLength();
	if (nIndiceLength == 0)
	{
		return;
	}

	GLDebug::showError();
	_indiceBuffer->bindBuffer();
	if (_modelMatrices.getLength() > 0)
	{
		int primaryCount = 1;
		if (isBatchDraw())
		{
			primaryCount = _modelMatrices.getVerticeCount();
		}
		GLBufferObjects::drawElementsInstanced(_drawMode, nIndiceLength, IndexDataType::UNSIGNED_INT, nullptr, primaryCount);
	}
	else
	{
		GLBufferObjects::drawElements(_drawMode, nIndiceLength, IndexDataType::UNSIGNED_INT, nullptr);
	}

	GLDebug::showError();
}

void render::Mesh::drawWithClientArray()
{
	if (_detail == nullptr)
	{
		return;
	}
	const sys::MeshMemoryData& vertices = _detail->getVertices();
	if (vertices.getLength() == 0)
	{
		//PRINT("Mesh Vertice is NULL\n");
		return;
	}

	const sys::MeshMemoryData& indices = _detail->getIndices();
	if (indices.getLength() == 0)
	{
		return;
	}

	const sys::MeshMemoryData& colors = _detail->getColors();
	const sys::MeshMemoryData& texcoords = _detail->getUVs();
	const sys::MeshMemoryData& normals = _detail->getNormals();
	const sys::MeshMemoryData& tangents = _detail->getTangents();
	const sys::MeshMemoryData& bitangents = _detail->getBitangents();

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
	/*
	if (tangents.getLength() > 0)
	{
		GLClientArrays::enableClientState(ClientArrayType::TANGENT_ARRAY);
		GLClientArrays::setTangentPointer(DataType::FLOAT, 0, bitangents.getValue());
		GLDebug::showError();
	}

	if (bitangents.getLength() > 0)
	{
		GLClientArrays::enableClientState(ClientArrayType::BITANGENT_ARRAY);
		GLClientArrays::setBitangentPointer(DataType::FLOAT, 0, bitangents.getValue());
		GLDebug::showError();
	}
	*/
	{
		GLClientArrays::drawElements(_drawMode, indices.getLength(), IndexDataType::UNSIGNED_INT, indices.getValue());
		GLDebug::showError();
	}

	GLClientArrays::disableClientState(ClientArrayType::VERTEX_ARRAY);
	GLClientArrays::disableClientState(ClientArrayType::NORMAL_ARRAY);
	GLClientArrays::disableClientState(ClientArrayType::TEXTURE_COORD_ARRAY);
	GLClientArrays::disableClientState(ClientArrayType::COLOR_ARRAY);
	/*
	GLClientArrays::disableClientState(ClientArrayType::BITANGENT_ARRAY);
	GLClientArrays::disableClientState(ClientArrayType::TANGENT_ARRAY);
	*/
}

void render::Mesh::updateBufferData()
{
	if (!_detail)
	{
		return;
	}

	uint32_t nVerticeSize = _detail->getVertices().getSize();
	if (nVerticeSize == 0)
	{
		return;
	}

	uint32_t nColorSize = _detail->getColors().getSize();
	uint32_t nUVSize = _detail->getUVs().getSize();
	uint32_t nNormalSize = _detail->getNormals().getSize();
	uint32_t nTangentSize = _detail->getTangents().getSize();
	uint32_t nBitangentSize = _detail->getBitangents().getSize();
	uint32_t nModelMatricesSize = _modelMatrices.getSize();

	_vertexBuffer->bindBuffer();

	GLDebug::showError();

	uint32_t nTotalSize = nVerticeSize + nColorSize + nUVSize + nNormalSize + nTangentSize + nBitangentSize + nModelMatricesSize;
	_vertexBuffer->setBufferData(nTotalSize, nullptr, BufferDataUsage::STATIC_DRAW);

	int nOffset = 0;
	if (nVerticeSize > 0)
	{
		_vertexBuffer->setBufferSubData(nOffset, nVerticeSize, _detail->getVertices().getPtr());
		nOffset += nVerticeSize;
	}

	GLDebug::showError();
	if (nColorSize > 0)
	{
		_vertexBuffer->setBufferSubData(nOffset, nColorSize, _detail->getColors().getPtr());
		nOffset += nColorSize;
	}

	GLDebug::showError();
	if (nUVSize > 0)
	{
		_vertexBuffer->setBufferSubData(nOffset, nUVSize, _detail->getUVs().getPtr());
		nOffset += nUVSize;
	}

	GLDebug::showError();
	if (nNormalSize > 0)
	{
		_vertexBuffer->setBufferSubData(nOffset, nNormalSize, _detail->getNormals().getPtr());
		nOffset += nNormalSize;
	}

	GLDebug::showError();
	if (nTangentSize > 0)
	{
		_vertexBuffer->setBufferSubData(nOffset, nTangentSize, _detail->getTangents().getPtr());
		nOffset += nTangentSize;
	}
	GLDebug::showError();
	if (nBitangentSize > 0)
	{
		_vertexBuffer->setBufferSubData(nOffset, nBitangentSize, _detail->getBitangents().getPtr());
		nOffset += nBitangentSize;
	}
	GLDebug::showError();
	if (nModelMatricesSize > 0)
	{
		_vertexBuffer->setBufferSubData(nOffset, nModelMatricesSize, _modelMatrices.getPtr());
		nOffset += nModelMatricesSize;
	}
	_vertexBuffer->unbindBuffer();
	GLDebug::showError();

	_indiceBuffer->bindBuffer();
	_indiceBuffer->setElementData(_detail->getIndices());
	_indiceBuffer->unbindBuffer();
	GLDebug::showError();
}

void render::Mesh::initMeshOtherDetail()
{
	if (getMeshDetail()->getVertices().getSize() == 0)
	{
		return;
	}

	if (getMeshDetail()->getUVs().getSize() == 0)
	{
		if (getMeshDetail()->getNormals().getSize() == 0)
		{
			this->initDetailNormalData();
		}
	}
	else
	{
		if (getMeshDetail()->getNormals().getSize() == 0)
		{
			this->initDetailNormalData();
		}
		if (getMeshDetail()->getTangents().getSize() == 0)
		{
			this->initDetailTangentData();
		}
	}
}

void render::Mesh::forceUpdateMeshData()
{
	this->initMeshOtherDetail();
	this->updateBufferData();
}

void render::Mesh::initDetailNormalData()
{
	if (!isComputeNormal())
	{
		return;
	}
	if (getMeshDetail()->getVertices().getSize() == 0)
	{
		return;
	}
	if (getMeshDetail()->getNormals().getSize() != 0)
	{
		return;
	}

	int nSize = getMeshDetail()->getVertices().getSize();
	int nCount = getMeshDetail()->getVertices().getLength();
	int nUnitSize = getMeshDetail()->getVertices().getUnitSize();

	int nLength = nCount / nUnitSize;

	float* normals = (float*)getMeshDetail()->createNormals(nLength, 3);
	this->calTrianglesVertexNormal(getMeshDetail()->getVertices(), getMeshDetail()->getIndices(), normals);
}

void render::Mesh::initDetailTangentData()
{
	if (!isComputeTangent())
	{
		return;
	}
	if (getMeshDetail()->getVertices().getSize() == 0)
	{
		return;
	}

	if (getMeshDetail()->getBitangents().getSize() != 0)
	{
		return;
	}

	int nSize = getMeshDetail()->getVertices().getSize();
	int nCount = getMeshDetail()->getVertices().getLength();
	int nUnitSize = getMeshDetail()->getVertices().getUnitSize();

	int nLength = nCount / nUnitSize;
	float* tangents = (float*)getMeshDetail()->createTangents(nLength, 3);
	this->calTrianglesVertexTangent(getMeshDetail()->getVertices(), getMeshDetail()->getUVs(), getMeshDetail()->getIndices(), tangents);
}

void render::Mesh::calTrianglesVertexNormal(const sys::MeshMemoryData& vertices, const sys::MeshMemoryData& indices, float* normals)
{
	int nUnitSize = vertices.getUnitSize();
	int nVerticeCount = vertices.getLength() / nUnitSize;

	float* pVerticeData = (float*)vertices.getValue();
	if (pVerticeData == nullptr)
	{
		return;
	}
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

	int nPointCount = indices.getVerticeCount();
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
}

void render::Mesh::calTrianglesVertexTangent(const sys::MeshMemoryData& vertices, const sys::MeshMemoryData& uvs,
	const sys::MeshMemoryData& indices,
	float* tangents)
{
	int nUnitSize = vertices.getUnitSize();
	int nVerticeCount = vertices.getLength() / nUnitSize;

	float* pVerticeData = (float*)vertices.getValue();
	float* pUVData = (float*)uvs.getValue();

	if (pVerticeData == nullptr || pUVData == nullptr)
	{
		return;
	}

	if (nVerticeCount < 3)
	{
		return;
	}

	if (!(nUnitSize == 2 || nUnitSize == 3))
	{
		return;
	}

	std::vector<math::Vector3> vecPoint;
	std::vector<math::Vector2> vecUV;

	for (int i = 0; i < nVerticeCount; i++)
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

		math::Vector2 uv = math::Vector2(pUVData[i * 2], pUVData[i * 2 + 1]);
		vecUV.push_back(uv);
	}

	int nPointCount = indices.getVerticeCount();
	int nTriangleCount = nPointCount / 3;

	uint32_t* pIndice = (uint32_t*)indices.getValue();

	std::map<int, std::vector<math::Vector3>> mapPointTangent;

	for (int i = 0; i < nTriangleCount; i++)
	{
		math::Vector3 p0 = vecPoint[pIndice[i * 3 + 0]];
		math::Vector3 p1 = vecPoint[pIndice[i * 3 + 1]];
		math::Vector3 p2 = vecPoint[pIndice[i * 3 + 2]];

		math::Vector3 edge1 = p1 - p0;
		math::Vector3 edge2 = p2 - p0;

		math::Vector2 uv0 = vecUV[pIndice[i * 3 + 0]];
		math::Vector2 uv1 = vecUV[pIndice[i * 3 + 1]];
		math::Vector2 uv2 = vecUV[pIndice[i * 3 + 2]];
		math::Vector2 deltaUV1 = uv1 - uv0;
		math::Vector2 deltaUV2 = uv2 - uv0;

		float f = 1.0f / (deltaUV1.getX() * deltaUV2.getY() - deltaUV2.getX() * deltaUV1.getY());
		float tx = f * (deltaUV2.getY() * edge1.getX() - deltaUV1.getY() * edge2.getX());
		float ty = f * (deltaUV2.getY() * edge1.getY() - deltaUV1.getY() * edge2.getY());
		float tz = f * (deltaUV2.getY() * edge1.getZ() - deltaUV1.getY() * edge2.getZ());

		float btx = f * (deltaUV1.getX() * edge1.getX() - deltaUV2.getX() * edge2.getX());
		float bty = f * (deltaUV1.getX() * edge1.getY() - deltaUV2.getX() * edge2.getY());
		float btz = f * (deltaUV1.getX() * edge1.getZ() - deltaUV2.getX() * edge2.getZ());

		math::Vector3 tangent(tx, ty, tz);

		mapPointTangent[pIndice[i * 3 + 0]].push_back(tangent);
		mapPointTangent[pIndice[i * 3 + 1]].push_back(tangent);
		mapPointTangent[pIndice[i * 3 + 2]].push_back(tangent);
		
	}

	for (int i = 0; i < nVerticeCount; i++)
	{
		math::Vector3 normal;
		math::Vector3 tangent;
		if (mapPointTangent[i].empty())
		{
			tangent = math::Vector3(0, 1, 0);
		}
		else
		{
			for (auto item : mapPointTangent[i])
			{
				tangent += item;
			}
			tangent /= mapPointTangent[i].size();
			tangent.normalize();
		}
		memcpy(tangents + i * 3, tangent.getValue(), 3 * sizeof(float));
	}
}

void render::Mesh::setModelMatrices(int len, const float* vertexes, int unitSize)
{
	_modelMatrices.init(len * unitSize, vertexes, sizeof(float));
	_modelMatrices.setUnitSize(unitSize);
}

void render::Mesh::setModelMatrices(int len, const math::Matrix4x4* vertexes)
{
	float* value = (float*)createModelMatrices(len, sizeof(float));
	for (int i = 0; i < len; i++)
	{
		memcpy(value + i * 16, vertexes->getValue(), 16 * sizeof(float));
	}
}

char* render::Mesh::createModelMatrices(size_t len, int unitSize)
{
	_modelMatrices.resize(len * unitSize, sizeof(float));
	_modelMatrices.setUnitSize(unitSize);
	return _modelMatrices.getPtr();
}

const sys::MeshMemoryData& render::Mesh::getModelMatrices() const
{
	return _modelMatrices;
}

void render::Mesh::setBatchDraw(bool bBatch)
{
	_bBatchDraw = bBatch;
}

bool render::Mesh::isBatchDraw() const
{
	return _bBatchDraw;
}

bool render::Mesh::equals(const Mesh& mesh) const
{
	if (getDrawMode() != mesh.getDrawMode()) return false;
	return _detail->equals(*mesh.getMeshDetail());
}

bool render::Mesh::sameLayout(const Mesh& mesh) const
{
	if (getDrawMode() != mesh.getDrawMode()) return false;
	return _detail->sameLayout(*mesh.getMeshDetail());
}

