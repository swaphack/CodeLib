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

void Mesh::setVertexes(int count, float* vertexes)
{
	float* vertors = (float*)malloc(count * sizeof(float));

	int size = 3;
	const math::Volume& volume = Tool::getGLViewSize();

	for (int i = 0; i < count / size; i++)
	{
		vertors[size * i] = vertexes[size * i] / volume.getWidth();
		vertors[size * i + 1] = vertexes[size * i + 1] / volume.getHeight();
		vertors[size * i + 2] = vertexes[size * i + 2] / volume.getDeep();
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
		vertors[i] = colors[i] / COLOR_FLOAT_VALUE;
	}

	_colors.init(count, vertors, size);

	free(vertors);
}

void Mesh::setUV(int count, float* texCoords, int size)
{
	_uvs.init(count, texCoords, size);
}

void Mesh::setIndices(int count, uint16_t* indices)
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

void Mesh::apply(int textureID, const sys::Color4B& color, uint8_t opacity, const BlendParam& blend)
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
