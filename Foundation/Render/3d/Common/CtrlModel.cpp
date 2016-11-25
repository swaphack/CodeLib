#include "CtrlModel.h"

using namespace render;


CtrlModel::CtrlModel()
:_material(nullptr)
, _texFrame(nullptr)
, _vertexes(nullptr)
, _texCoords(nullptr)
, _indices(nullptr)
, _normals(nullptr)
, _colors(nullptr)
, _triangleCount(0)
, _vertexCount(0)
{
	_material = new Material();
	_texFrame = new TexFrame();
}

CtrlModel::~CtrlModel()
{
	SAFE_FREE(_material);
	SAFE_FREE(_texFrame);

	SAFE_FREE(_normals);
	SAFE_FREE(_vertexes);
	SAFE_FREE(_colors);
	SAFE_FREE(_texCoords);
	SAFE_FREE(_indices);
}

void CtrlModel::draw()
{
	ColorNode::draw();

	if (_vertexes && _normals && _colors && _texCoords && _indices)
	{
		if (_material)
		{
			_material->apply();
		}

		int textureID = _texFrame->getTexture()->getTextureID();

		G_DRAWCOMMANDER->addCommand(
			DCTextureBatch::create(textureID,
			_color, _opacity, _blend,
			_vertexCount, _normals, _vertexes, _colors, _texCoords,
			_triangleCount, _indices));

		Material::applyDefault();
	}
}

void CtrlModel::setMatrial(const Material* material)
{
	if (material == nullptr)
	{
		return;
	}
	*_material = *material;
}

const Material* CtrlModel::getMatrial() const
{
	return _material;
}

Material* CtrlModel::getMatrial()
{
	return _material;
}

void CtrlModel::initSelf()
{
	Node::initSelf();
}

void CtrlModel::setTexFrame(const TexFrame* frame)
{
	if (frame == nullptr)
	{
		return;
	}

	*_texFrame = *frame;
}

void CtrlModel::setVertexes(int count, float* vertexes, float* normals, float* colors, float* texCoords)
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

	for (int i = 0; i < count/3; i++)
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

void CtrlModel::setIndices(int count, int* indices)
{
	if (indices == nullptr)
	{
		return;
	}

	_triangleCount = count;

	SAFE_FREE(_indices);

	_indices = (int*)malloc(count * sizeof(int));

	// 索引
	memcpy(_indices, indices, count * sizeof(int));
}

int CtrlModel::getVertexCount()
{
	return _vertexCount / 3;
}

int CtrlModel::getTriangleCount()
{
	return _triangleCount / 3;
}