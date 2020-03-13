#include "Mesh.h"

#include "../Tool/Tool.h"
#include "Graphic/import.h"

using namespace render;

Mesh::Mesh()
{

}

Mesh::~Mesh()
{
}

void Mesh::setVertices(int count, float* vertexes)
{
	float* vertors = (float*)malloc(count * sizeof(float));
	memcpy(vertors, vertexes, count * sizeof(float));

	int size = 3;
	_vertexes.init(count, vertors, size);
	free(vertors);
}

void Mesh::setNormals(int count, float* normals)
{
	int size = 3;

	_normals.init(count, normals, size);
}

void Mesh::setColors(int count, float* colors, int size)
{
	float* vertors = (float*)malloc(count * sizeof(float));

	for (int i = 0; i < count; i++)
	{
		vertors[i] = colors[i] / COLOR_FLOAT_VALUE;
	}

	_colors.init(count, vertors, size);

	free(vertors);
}

void Mesh::setUV(int count, float* texCoords, int size)
{
	_uvs.init(count, texCoords, size);
}

void Mesh::setIndices(int size, uint16_t* indices)
{
	_indices.init(size, indices);
}

int Mesh::getVertexCount()
{
	return _vertexes.size / _vertexes.unit;
}

int Mesh::getTriangleCount()
{
	return _indices.size / 3;
}

void Mesh::apply(int textureID, const sys::Color4B& color, uint8_t opacity, const BlendParam& blend)
{
	G_DRAWCOMMANDER->addCommand(
		DCTextureBatch::create(textureID,
		color, opacity, blend,
		&_vertexes, &_normals, &_colors, &_uvs,
		&_indices));
}

void Mesh::apply(const sys::Color4B& color /*= sys::Color4B()*/, uint8_t opacity /*= 255*/, const BlendParam& blend /*= BlendParam()*/)
{
	G_DRAWCOMMANDER->addCommand(
		DCTextureBatch::create(0,
		color, opacity, blend,
		&_vertexes, &_normals, &_colors, &_uvs,
		&_indices));
}

void Mesh::setMaterial(int matID)
{
	_material = matID;
}

int Mesh::getMaterial()
{
	return _material;
}


