#include "MeshDetail.h"
#include "third_party.h"

using namespace sys;

MeshDetail::MeshDetail()
{

}

MeshDetail::~MeshDetail()
{
}

void MeshDetail::setVertices(int len, const float* vertexes, int unitSize)
{
	_vertices.init(len * unitSize, vertexes, sizeof(float));
	_vertices.setUnitSize(unitSize);
}

void MeshDetail::setNormals(int len, const float* normals, int unitSize)
{
	_normals.init(len * unitSize, normals, sizeof(float));
	_normals.setUnitSize(unitSize);
}

void MeshDetail::setColors(int len, const float* colors, int unitSize)
{
	_colors.init(len * unitSize, colors, sizeof(float));
	_colors.setUnitSize(unitSize);
}

void MeshDetail::setUVs(int len, const float* texCoords, int unitSize)
{
	_uvs.init(len * unitSize, texCoords, sizeof(float));
	_uvs.setUnitSize(unitSize);
}

const MeshMemoryData& MeshDetail::getVertices() const
{
	return _vertices;
}

const MeshMemoryData& MeshDetail::getNormals() const
{
	return _normals;
}

const MeshMemoryData& MeshDetail::getColors() const
{
	return _colors;
}

const MeshMemoryData& MeshDetail::getUVs() const
{
	return _uvs;
}

void MeshDetail::setMaterialName(const std::string& name)
{
	_materialName = name;
}

const std::string& MeshDetail::getMaterialName() const
{
	return _materialName;
}

void MeshDetail::setIndices(int size, const uint32_t* indices, int unitSize)
{
	if (size == 0)
	{
		int a = 1;
	}
	_indices.init(size, indices);
	_indices.setUnitSize(unitSize);
}

const MeshMemoryData& MeshDetail::getIndices() const
{
	return _indices;
}

const math::Matrix4x4& MeshDetail::getMatrix() const
{
	return _matrix;
}

void MeshDetail::setMatrix(const math::Matrix4x4& mat)
{
	_matrix = mat;
}

const sys::MeshMemoryData& sys::MeshDetail::getTangents() const
{
	return _tangents;
}

void sys::MeshDetail::setTangents(int len, const float* normals, int unitSize /*= 3*/)
{
	_tangents.init(len * unitSize, normals, sizeof(float));
	_tangents.setUnitSize(unitSize);
}

const sys::MeshMemoryData& sys::MeshDetail::getBitangents() const
{
	return _bitangents;
}

void sys::MeshDetail::setBitangents(int len, const float* normals, int unitSize /*= 3*/)
{
	_bitangents.init(len * unitSize, normals, sizeof(float));
	_bitangents.setUnitSize(unitSize);
}

char* sys::MeshDetail::createVertices(size_t len, int unitSize)
{
	_vertices.resize(len * unitSize, sizeof(float));
	_vertices.setUnitSize(unitSize);
	return _vertices.getPtr();
}

char* sys::MeshDetail::createNormals(size_t len, int unitSize)
{
	_normals.resize(len * unitSize, sizeof(float));
	_normals.setUnitSize(unitSize);
	return _normals.getPtr();
}

char* sys::MeshDetail::createTangents(size_t len, int unitSize /*= 3*/)
{
	_tangents.resize(len * unitSize, sizeof(float));
	_tangents.setUnitSize(unitSize);
	return _tangents.getPtr();
}

char* sys::MeshDetail::createBitangents(size_t len, int unitSize /*= 3*/)
{
	_bitangents.resize(len * unitSize, sizeof(float));
	_bitangents.setUnitSize(unitSize);
	return _bitangents.getPtr();
}

char* sys::MeshDetail::createColors(size_t len, int unitSize)
{
	_colors.resize(len * unitSize, sizeof(float));
	_colors.setUnitSize(unitSize);
	return _colors.getPtr();
}

char* sys::MeshDetail::createUVs(size_t len, int unitSize)
{
	_uvs.resize(len * unitSize, sizeof(float));
	_uvs.setUnitSize(unitSize);
	return _uvs.getPtr();
}

char* sys::MeshDetail::createIndices(size_t len, int unitSize)
{
	if (len == 0)
	{
		int a = 1;
	}
	_indices.resize(len * unitSize, sizeof(uint32_t));
	_indices.setUnitSize(unitSize);
	return _indices.getPtr();
}

const std::string& MeshDetail::getName() const
{
	return _meshName;
}

void MeshDetail::setName(const std::string& name)
{
	_meshName = name;
}

bool MeshDetail::equals(const MeshDetail& detail)
{
	return _indices.equals(detail.getIndices())
		&& _vertices.equals(detail.getVertices())
		&& _normals.equals(detail.getNormals())
		&& _colors.equals(detail.getColors())
		&& _uvs.equals(detail.getUVs())
		&& _tangents.equals(detail.getTangents())
		&& _bitangents.equals(detail.getBitangents());
}

bool sys::MeshDetail::sameLayout(const MeshDetail& detail)
{
	return _indices.getVerticeCount() == detail.getIndices().getVerticeCount()
		&& _vertices.getVerticeCount() == detail.getVertices().getVerticeCount()
		&& _normals.getVerticeCount() == detail.getNormals().getVerticeCount()
		&& _colors.getVerticeCount() == detail.getColors().getVerticeCount()
		&& _uvs.getVerticeCount() == detail.getUVs().getVerticeCount()
		&& _tangents.getVerticeCount() == detail.getTangents().getVerticeCount()
		&& _bitangents.getVerticeCount() == detail.getBitangents().getVerticeCount();
}