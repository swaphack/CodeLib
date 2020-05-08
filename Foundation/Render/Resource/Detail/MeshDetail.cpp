#include "MeshDetail.h"
#include "ext-config.h"

using namespace render;

MeshDetail::MeshDetail()
{

}

MeshDetail::~MeshDetail()
{
}

void MeshDetail::setVertices(int size, float* vertexes, int unitSize)
{
	_vertices.init(size, vertexes, sizeof(float));
	_vertices.setTypeSize(unitSize);
}

void MeshDetail::setNormals(int size, float* normals, int unitSize)
{
	_normals.init(size, normals, sizeof(float));
	_normals.setTypeSize(unitSize);
}

void MeshDetail::setColors(int size, float* colors, int unitSize)
{
	_colors.init(size, colors, sizeof(float));
	_colors.setTypeSize(unitSize);
}

void MeshDetail::setUVs(int size, float* texCoords, int unitSize)
{
	_uvs.init(size, texCoords, sizeof(float));
	_uvs.setTypeSize(unitSize);
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
	_indices.setTypeSize(1);
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

const std::string& MeshDetail::getMeshName() const
{
	return _meshName;
}

void MeshDetail::setMeshName(const std::string& name)
{
	_meshName = name;
}


