#include "CtrlModel.h"

using namespace render;


CtrlModel::CtrlModel()
:_material(nullptr)
, _texFrame(nullptr)
{
	_material = new Material();
	_texFrame = new TexFrame();
}

CtrlModel::~CtrlModel()
{
	SAFE_DELETE(_material);
	SAFE_DELETE(_texFrame);
}

void CtrlModel::draw()
{
	ColorNode::draw();

	if (_material)
	{
		_material->apply();
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
