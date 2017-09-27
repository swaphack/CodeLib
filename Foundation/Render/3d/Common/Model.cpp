#include "Model.h"

using namespace render;


Model::Model()
:_material(nullptr)
, _texFrame(nullptr)
{
	_material = new Material();
	_texFrame = new TexFrame();
	_mesh = new Mesh();
}

Model::~Model()
{
	SAFE_FREE(_material);
	SAFE_FREE(_texFrame);
	SAFE_FREE(_mesh);
}

void Model::draw()
{
	ColorNode::draw();
	if (_material)
	{
		_material->apply();
	}

	if (_mesh)
	{
		int textureID = 0;
		if (_texFrame->getTexture())
		{
			textureID = _texFrame->getTexture()->getTextureID();
		}
		_mesh->apply(textureID, _color, _opacity, _blend);
	}
	
	Material::applyDefault();
}

void Model::setMatrial(const Material* material)
{
	if (material == nullptr)
	{
		return;
	}
	*_material = *material;
}

const Material* Model::getMatrial() const
{
	return _material;
}

Material* Model::getMatrial()
{
	return _material;
}

const Mesh* Model::getMesh() const
{
	return _mesh;
}

Mesh* Model::getMesh()
{
	return _mesh;
}

void Model::setTexFrame(const TexFrame* frame)
{
	if (frame == nullptr)
	{
		return;
	}

	*_texFrame = *frame;
}