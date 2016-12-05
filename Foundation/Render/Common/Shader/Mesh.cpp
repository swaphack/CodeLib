#include "Mesh.h"

#include "../Tool/Tool.h"

using namespace render;

Mesh::Mesh()
:_vertexes(nullptr)
, _texCoords(nullptr)
, _indices(nullptr)
, _normals(nullptr)
, _colors(nullptr)
, _triangleCount(0)
, _vertexCount(0)
{

}

Mesh::~Mesh()
{
	SAFE_FREE(_normals);
	SAFE_FREE(_vertexes);
	SAFE_FREE(_colors);
	SAFE_FREE(_texCoords);
	SAFE_FREE(_indices);
}

void Mesh::setVertexes(int count, float* vertexes, float* normals, float* colors, float* texCoords)
{
	if (vertexes == nullptr || normals == nullptr || colors == nullptr || texCoords == nullptr)
	{
		return;
	}

	_vertexCount = count;

	SAFE_FREE(_vertexes);
	SAFE_FREE(_normals);
	SAFE_FREE(_colors);
	SAFE_FREE(_texCoords);

	for (int i = 0; i < count / 3; i++)
	{
		vertexes[3 * i] /= Tool::getGLViewSize().width;
		vertexes[3 * i + 1] /= Tool::getGLViewSize().height;
		vertexes[3 * i + 2] /= Tool::getGLViewSize().deep;

		colors[3 * i] /= sys::COLOR_FLOAT_VALUE;
		colors[3 * i + 1] /= sys::COLOR_FLOAT_VALUE;
		colors[3 * i + 2] /= sys::COLOR_FLOAT_VALUE;
	}


	_vertexes = (float*)malloc(count * sizeof(float));
	_normals = (float*)malloc(count * sizeof(float));
	_colors = (float*)malloc(count * sizeof(float));
	_texCoords = (float*)malloc(count * sizeof(float));

	// 顶点
	memcpy(_vertexes, vertexes, count * sizeof(float));
	// 法线
	memcpy(_normals, normals, count * sizeof(float));
	// 颜色
	memcpy(_colors, colors, count * sizeof(float));
	// 纹理坐标
	memcpy(_texCoords, texCoords, count * sizeof(float));
}

void Mesh::setIndices(int count, ushort* indices)
{
	if (indices == nullptr)
	{
		return;
	}

	_triangleCount = count;

	SAFE_FREE(_indices);

	_indices = (ushort*)malloc(count * sizeof(ushort));

	// 索引
	memcpy(_indices, indices, count * sizeof(ushort));
}

int Mesh::getVertexCount()
{
	return _vertexCount / 3;
}

int Mesh::getTriangleCount()
{
	return _triangleCount / 3;
}

void Mesh::apply(int textureID, const sys::Color4B& color, uchar opacity, const BlendParam& blend)
{
	if (_vertexes == nullptr 
		|| _normals == nullptr 
		|| _colors == nullptr 
		|| _texCoords == nullptr
		|| _indices == nullptr)
	{
		return;
	}

	G_DRAWCOMMANDER->addCommand(
		DCTextureBatch::create(textureID,
		color, opacity, blend,
		_vertexCount, _normals, _vertexes, _colors, _texCoords,
		_triangleCount, _indices));
}
