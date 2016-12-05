#include "CtrlModel.h"

using namespace render;


CtrlModel::CtrlModel()
:_material(nullptr)
, _texFrame(nullptr)
{
	_material = new Material();
	_texFrame = new TexFrame();
	_mesh = new Mesh();
}

CtrlModel::~CtrlModel()
{
	SAFE_FREE(_material);
	SAFE_FREE(_texFrame);
	SAFE_FREE(_mesh);
}

void CtrlModel::draw()
{
	ColorNode::draw();
	if (_material)
	{
		_material->apply();
	}

	if (_mesh)
	{
		_mesh->apply(_texFrame->getTexture()->getTextureID(), _color, _opacity, _blend);
	}
	
	Material::applyDefault();
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

const Mesh* CtrlModel::getMesh() const
{
	return _mesh;
}

Mesh* CtrlModel::getMesh()
{
	return _mesh;
}

void CtrlModel::setTexFrame(const TexFrame* frame)
{
	if (frame == nullptr)
	{
		return;
	}

	*_texFrame = *frame;
}