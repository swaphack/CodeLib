#include "Mesh.h"

#include "../Tool/Tool.h"

using namespace render;

Mesh::Mesh()
{

}

Mesh::~Mesh()
{
}

void Mesh::setVertexes(int count, float* vertexes)
{
	float* vertors = (float*)malloc(count * sizeof(float));

	int size = 3;
	const sys::Volume& volume = Tool::getGLViewSize();

	for (int i = 0; i < count / size; i++)
	{
		vertors[size * i] = vertexes[size * i] / volume.width;
		vertors[size * i + 1] = vertexes[size * i + 1] / volume.height;
		vertors[size * i + 2] = vertexes[size * i + 2] / volume.deep;
	}

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
		vertors[i] = colors[i] / sys::COLOR_FLOAT_VALUE;
	}

	_colors.init(count, vertors, size);

	free(vertors);
}

void Mesh::setUV(int count, float* texCoords, int size)
{
	_uvs.init(count, texCoords, size);
}

void Mesh::setIndices(int count, ushort* indices)
{
	_indices.init(count, indices);
}

int Mesh::getVertexCount()
{
	return _vertexes.count / _vertexes.size;
}

int Mesh::getTriangleCount()
{
	return _indices.count / 3;
}

void Mesh::apply(int textureID, const sys::Color4B& color, uchar opacity, const BlendParam& blend)
{
	if (_vertexes.value == nullptr 
		|| _normals.value == nullptr
		|| _colors.value == nullptr
		|| _uvs.value == nullptr
		|| _indices.value == nullptr)
	{
		return;
	}

	G_DRAWCOMMANDER->addCommand(
		DCTextureBatch::create(textureID,
		color, opacity, blend,
		&_vertexes, &_normals, &_colors, &_uvs,
		&_indices));
}
