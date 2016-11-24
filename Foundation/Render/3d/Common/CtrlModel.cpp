#include "CtrlModel.h"

using namespace render;


CtrlModel::CtrlModel()
:_material(nullptr)
, _texFrame(nullptr)
, _vertexs(nullptr)
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
	SAFE_FREE(_vertexs);
	SAFE_FREE(_colors);
	SAFE_FREE(_texCoords);
	SAFE_FREE(_indices);
}

void CtrlModel::draw()
{
	if (_vertexs == nullptr || _normals == nullptr || _colors  == nullptr|| _texCoords == nullptr || _indices == nullptr)
	{
		return;
	}

	ColorNode::draw();

	if (_material)
	{
		_material->apply();
	}

	int textureID = _texFrame->getTexture()->getTextureID();

	G_DRAWCOMMANDER->addCommand(
		DCTextureBatch::create(textureID,
		_color, _opacity, _blend,
		_vertexCount, _normals, _vertexs, _colors, _texCoords,
		_triangleCount, _indices));
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

void CtrlModel::setVertexs(int count, float* vertexs, float* normals, float* colors, float* texCoords)
{
	if (vertexs == nullptr || normals == nullptr || colors == nullptr || texCoords == nullptr)
	{
		return;
	}

	_vertexCount = count;

	SAFE_FREE(_vertexs);
	SAFE_FREE(_normals);
	SAFE_FREE(_colors);
	SAFE_FREE(_texCoords);

	
	_vertexs = (float*)malloc(count * sizeof(float));
	_normals = (float*)malloc(count * sizeof(float));
	_colors = (float*)malloc(count * sizeof(float));
	_texCoords = (float*)malloc(count * sizeof(float));

	// 顶点
	memcpy(_vertexs, vertexs, count * sizeof(float));
	// 法线
	memcpy(_normals, normals, count * sizeof(float));
	// 颜色
	memcpy(_colors, colors, count * sizeof(float));
	// 纹理坐标
	memcpy(_texCoords, texCoords, count * sizeof(float));
}

void CtrlModel::setIndices(int count, ushort* indices)
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

int CtrlModel::getVertexCount()
{
	return _vertexCount / 3;
}

int CtrlModel::getTriangleCount()
{
	return _triangleCount / 3;
}