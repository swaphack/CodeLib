#include "DrawNode.h"
#include "Graphic/import.h"
#include "Material.h"
#include "Mesh.h"
#include "FragmentOperator.h"

using namespace render;


DrawNode::DrawNode()
{
	_material = CREATE_OBJECT(Material);
	SAFE_RETAIN(_material);

	_mesh = CREATE_OBJECT(Mesh);
	SAFE_RETAIN(_mesh);

	_fragOperator = CREATE_OBJECT(FragmentOperator);
	SAFE_RETAIN(_fragOperator);
}

DrawNode::~DrawNode()
{
	SAFE_RELEASE(_material);
	SAFE_RELEASE(_mesh);
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

Material* render::DrawNode::getMaterial()
{
	return _material;
}

Mesh* render::DrawNode::getMesh()
{
	return _mesh;
}

FragmentOperator* render::DrawNode::getFragOperator()
{
	return _fragOperator;
}

void render::DrawNode::beforeDraw()
{
	_fragOperator->begin();

	_fragOperator->update();
}

void DrawNode::onDraw()
{
	if (_material->getShaderProgram())
	{
		this->drawWithBufferObject();
	}
	else
	{
		this->drawWithClientArray();
	}
}

void render::DrawNode::afterDraw()
{
	_fragOperator->end();
}

void render::DrawNode::drawWithClientArray()
{
	_mesh->drawWithClientArray(this, _material);
}

void render::DrawNode::drawWithBufferObject()
{
	_mesh->drawWithBufferObject(this, _material);
}
