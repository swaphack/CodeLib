#include "CtrlModel.h"

using namespace render;


CtrlModel::CtrlModel()
:_material(nullptr)
, _texFrame(nullptr)
{
	_material = new Material();
	AUTO_RELEASE_OBJECT(_material);
}

CtrlModel::~CtrlModel()
{
	SAFE_RELEASE(_material);
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

void CtrlModel::setMatrial(Material* material)
{
	if (material == nullptr)
	{
		return;
	}
	SAFE_RELEASE(_material);
	SAFE_RETAIN(material);
	_material = material;
}

Material* CtrlModel::getMatrial()
{
	return _material;
}

void CtrlModel::initSelf()
{
	Node::initSelf();
}

void CtrlModel::setTexFrame(TexFrame* frame)
{
	if (frame == nullptr)
	{
		return;
	}
	SAFE_RELEASE(_texFrame);
	SAFE_RETAIN(frame);
	_texFrame = frame;
}
