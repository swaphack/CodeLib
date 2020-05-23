#include "DrawNode.h"
#include "Graphic/import.h"
#include "Common/Material/import.h"
#include "Common/Mesh/import.h"
#include "FragmentOperator.h"

using namespace render;


DrawNode::DrawNode()
{
	_materiales = CREATE_OBJECT(Materials);
	SAFE_RETAIN(_materiales);

	_meshes = CREATE_OBJECT(Meshes);
	SAFE_RETAIN(_meshes);

	_fragOperator = CREATE_OBJECT(FragmentOperator);
	SAFE_RETAIN(_fragOperator);
}

DrawNode::~DrawNode()
{
	SAFE_RELEASE(_materiales);
	SAFE_RELEASE(_meshes);
	SAFE_RELEASE(_fragOperator);
}

bool render::DrawNode::init()
{
	if (!Node::init())
	{
		return false;
	}

	return true;
}

void DrawNode::draw()
{
	this->beforeDraw();

	this->onDraw();

	this->afterDraw();
}

Materials* render::DrawNode::getMaterials()
{
	return _materiales;
}

Meshes* render::DrawNode::getMeshes()
{
	return _meshes;
}

FragmentOperator* render::DrawNode::getFragOperator()
{
	return _fragOperator;
}

render::Material* render::DrawNode::getMaterial(int id)
{
	return _materiales->getMaterial(id);
}

render::Mesh* render::DrawNode::getMesh(int id)
{
	return _meshes->getMesh(id);
}

void render::DrawNode::beforeDraw()
{
	_fragOperator->begin();

	_fragOperator->update();
}

void DrawNode::onDraw()
{
	_meshes->drawNodeWithMaterials(this, _materiales);
}

void render::DrawNode::afterDraw()
{
	_fragOperator->end();
}
