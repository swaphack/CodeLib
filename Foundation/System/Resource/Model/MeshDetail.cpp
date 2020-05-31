#include "MeshDetail.h"
#include "../extensions.h"

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

void MeshDetail::setMaterial(const std::string& name)
{
	_materialName = name;
}

const std::string& MeshDetail::getMaterial() const
{
	return _materialName;
}

void MeshDetail::setIndices(int size, const uint32_t* indices, int unitSize)
{
	_indices.init(size, indices);
	_indices.setUnitSize(unitSize);
}

const MeshMemoryData& MeshDetail::getIndices() const
{
	return _indices;
}

const math::Matrix44& MeshDetail::getMatrix() const
{
	return _matrix;
}

void MeshDetail::setMatrix(const math::Matrix44& mat)
{
	_matrix = mat;
}

char* sys::MeshDetail::createVertices(size_t len, uint32_t typeSize, int unitSize)
{
	_vertices.resize(len * unitSize, typeSize);
	_vertices.setUnitSize(unitSize);
	return _vertices.getPtr();
}

char* sys::MeshDetail::createNormals(size_t len, uint32_t typeSize, int unitSize)
{
	_normals.resize(len * unitSize, typeSize);
	_normals.setUnitSize(unitSize);
	return _normals.getPtr();
}

char* sys::MeshDetail::createColors(size_t len, uint32_t typeSize, int unitSize)
{
	_colors.resize(len * unitSize, typeSize);
	_colors.setUnitSize(unitSize);
	return _colors.getPtr();
}

char* sys::MeshDetail::createUVs(size_t len, uint32_t typeSize, int unitSize)
{
	_uvs.resize(len * unitSize, typeSize);
	_uvs.setUnitSize(unitSize);
	return _uvs.getPtr();
}

char* sys::MeshDetail::createIndices(size_t len, uint32_t typeSize, int unitSize)
{
	_indices.resize(len * unitSize, typeSize);
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


