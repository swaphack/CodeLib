#include "MeshDetail.h"
#include "../extensions.h"

using namespace sys;

MeshDetail::MeshDetail()
{

}

MeshDetail::~MeshDetail()
{
}

void MeshDetail::setVertices(int size, float* vertexes, int unitSize)
{
	_vertices.init(size, vertexes, sizeof(float));
	_vertices.setUnitSize(unitSize);
}

void MeshDetail::setNormals(int size, float* normals, int unitSize)
{
	_normals.init(size, normals, sizeof(float));
	_normals.setUnitSize(unitSize);
}

void MeshDetail::setColors(int size, float* colors, int unitSize)
{
	_colors.init(size, colors, sizeof(float));
	_colors.setUnitSize(unitSize);
}

void MeshDetail::setUVs(int size, float* texCoords, int unitSize)
{
	_uvs.init(size, texCoords, sizeof(float));
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

void MeshDetail::setMaterial(int mat)
{
	_material = mat;
}

int MeshDetail::getMaterial() const
{
	return _material;
}

void MeshDetail::setIndices(int size, uint32_t* indices)
{
	_indices.init(size, indices);
	_indices.setUnitSize(1);
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

char* sys::MeshDetail::createVertices(size_t size, uint32_t typeSize, int unitSize)
{
	_vertices.resize(size, typeSize);
	_vertices.setUnitSize(unitSize);
	return _vertices.getPtr();
}

char* sys::MeshDetail::createNormals(size_t size, uint32_t typeSize, int unitSize)
{
	_normals.resize(size, typeSize);
	_normals.setUnitSize(unitSize);
	return _normals.getPtr();
}

char* sys::MeshDetail::createColors(size_t size, uint32_t typeSize, int unitSize)
{
	_colors.resize(size, typeSize);
	_colors.setUnitSize(unitSize);
	return _colors.getPtr();
}

char* sys::MeshDetail::createUVs(size_t size, uint32_t typeSize, int unitSize)
{
	_uvs.resize(size, typeSize);
	_uvs.setUnitSize(unitSize);
	return _uvs.getPtr();
}

char* sys::MeshDetail::createIndices(size_t size, uint32_t typeSize, int unitSize)
{
	_indices.resize(size, typeSize);
	_indices.setUnitSize(unitSize);
	return _indices.getPtr();
}

const std::string& MeshDetail::getMeshName() const
{
	return _meshName;
}

void MeshDetail::setMeshName(const std::string& name)
{
	_meshName = name;
}


