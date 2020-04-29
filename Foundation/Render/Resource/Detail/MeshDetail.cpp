#include "MeshDetail.h"
#include "ext-config.h"

using namespace render;

MeshDetail::MeshDetail()
{

}

MeshDetail::~MeshDetail()
{
}

void MeshDetail::setVertices(int count, float* vertexes, int unitSize)
{
	_vertices.init(count, vertexes, sizeof(float));
	_vertices.setTypeSize(unitSize);
}

void MeshDetail::setNormals(int count, float* normals, int unitSize)
{
	_normals.init(count, normals, sizeof(float));
	_normals.setTypeSize(unitSize);
}

void MeshDetail::setColors(int count, float* colors, int unitSize)
{
	float* vertors = (float*)malloc(count * sizeof(float));

	for (int i = 0; i < count; i++)
	{
		vertors[i] = colors[i];
	}

	_colors.init(count, vertors, sizeof(float));
	_colors.setTypeSize(unitSize);

	free(vertors);
}

void MeshDetail::setUVs(int count, float* texCoords, int unitSize)
{
	_uvs.init(count, texCoords, sizeof(float));
	_uvs.setTypeSize(unitSize);
}

const MeshMemoryData& MeshDetail::getVertices()
{
	return _vertices;
}

const MeshMemoryData& MeshDetail::getNormals()
{
	return _normals;
}

const MeshMemoryData& MeshDetail::getColors()
{
	return _colors;
}

const MeshMemoryData& MeshDetail::getUVs()
{
	return _uvs;
}

void MeshDetail::setMaterial(int mat)
{
	_material = mat;
}

int MeshDetail::getMaterial()
{
	return _material;
}

void MeshDetail::setIndices(int size, uint32_t* indices)
{
	_indices.init(size, indices);
}

const MeshMemoryData& MeshDetail::getIndices()
{
	return _indices;
}

const math::Matrix44& MeshDetail::getMatrix()
{
	return _matrix;
}

void MeshDetail::setMatrix(const math::Matrix44& mat)
{
	_matrix = mat;
}

const std::string& MeshDetail::getMeshName()
{
	return _meshName;
}

void MeshDetail::setMeshName(const std::string& name)
{
	_meshName = name;
}
