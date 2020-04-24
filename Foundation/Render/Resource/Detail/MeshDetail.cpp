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
	float* vertors = (float*)malloc(count * sizeof(float));
	memcpy(vertors, vertexes, count * sizeof(float));

	_vertices.init(count, vertors, unitSize);
	free(vertors);
}

void MeshDetail::setNormals(int count, float* normals, int unitSize)
{
	_normals.init(count, normals, unitSize);
}

void MeshDetail::setColors(int count, float* colors, int unitSize)
{
	float* vertors = (float*)malloc(count * sizeof(float));

	for (int i = 0; i < count; i++)
	{
		vertors[i] = colors[i] / COLOR_FLOAT_VALUE;
	}

	_colors.init(count, vertors, unitSize);

	free(vertors);
}

void MeshDetail::setUVs(int count, float* texCoords, int unitSize)
{
	_uvs.init(count, texCoords, unitSize);
}

int MeshDetail::getVerticesCount()
{
	return _vertices.size / _vertices.unit;
}

const T_Vertex& MeshDetail::getVertices()
{
	return _vertices;
}

const T_Vertex& MeshDetail::getNormals()
{
	return _normals;
}

const T_Vertex& MeshDetail::getColors()
{
	return _colors;
}

const T_Vertex& MeshDetail::getUVs()
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

const T_Indice& MeshDetail::getIndices()
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
