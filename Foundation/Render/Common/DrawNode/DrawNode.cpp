#include "DrawNode.h"
#include "Graphic/import.h"
#include "Material.h"
#include "Mesh.h"

using namespace render;


DrawNode::DrawNode()
{
	_material = CREATE_OBJECT(Material);
	SAFE_RETAIN(_material);

	_mesh = CREATE_OBJECT(Mesh);
	SAFE_RETAIN(_mesh);
}

DrawNode::~DrawNode()
{

	SAFE_RELEASE(_material);
	SAFE_RELEASE(_mesh);
}

void DrawNode::draw()
{
	GLState::enable(EnableModel::BLEND);
	GLState::setBlendFunc(getBlend().src, getBlend().dest);
	GLVertex::setColor(getColor());

	this->drawing();

	GLState::disable(EnableModel::BLEND);
}

Material* render::DrawNode::getMaterial()
{
	return _material;
}

Mesh* render::DrawNode::getMesh()
{
	return _mesh;
}

void DrawNode::drawing()
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

void render::DrawNode::drawWithClientArray()
{
	_mesh->drawWithClientArray(this, _material);
}

void render::DrawNode::drawWithBufferObject()
{
	_mesh->drawWithBufferObject(this, _material);
}
