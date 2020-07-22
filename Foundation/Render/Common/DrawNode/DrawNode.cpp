#include "DrawNode.h"
#include "Graphic/import.h"
#include "Common/Material/import.h"
#include "Common/Mesh/import.h"
#include "FragmentOperator.h"
#include "Common/Texture/import.h"
#include "Common/Shader/ShaderProgram.h"
#include "DrawTextureCache.h"
#include "macros.h"

using namespace render;

DrawNode::DrawNode()
{
	_material = CREATE_OBJECT(Material);
	SAFE_RETAIN(_material);

	_mesh = CREATE_OBJECT(Mesh);
	SAFE_RETAIN(_mesh);

	_fragOperator = CREATE_OBJECT(FragmentOperator);
	SAFE_RETAIN(_fragOperator);

	_textureCache = CREATE_OBJECT(DrawTextureCache);
	SAFE_RETAIN(_textureCache);
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

	initBufferObject();

	return true;
}

void DrawNode::draw()
{
	this->beforeDraw();

	this->onDraw();

	this->afterDraw();
}

FragmentOperator* render::DrawNode::getFragOperator()
{
	return _fragOperator;
}

render::Material* render::DrawNode::getMaterial()
{
	return _material;
}

render::Mesh* render::DrawNode::getMesh()
{
	return _mesh;
}

void render::DrawNode::setTexture(const std::string& fullpath)
{
	_material->getMaterialDetail()->setAmbientTextureMap(MAT_TEXTURE_NAME);
	_textureCache->addTexture(MAT_TEXTURE_NAME, fullpath);
}

void render::DrawNode::setTexture(const Texture* texture)
{
	_material->getMaterialDetail()->setAmbientTextureMap(MAT_TEXTURE_NAME);
	_textureCache->addTexture(MAT_TEXTURE_NAME, texture);
}

void render::DrawNode::setAmbientTexture(const std::string& fullpath)
{
	_material->getMaterialDetail()->setAmbientTextureMap(MAT_TEXTURE_NAME);
	_textureCache->addTexture(MAT_TEXTURE_NAME, fullpath);
}

void render::DrawNode::setDiffuseTexture(const std::string& fullpath)
{
	_material->getMaterialDetail()->setDiffuseTextureMap(MAT_TEXTURE_DIFFUSE);
	_textureCache->addTexture(MAT_TEXTURE_DIFFUSE, fullpath);
}

void render::DrawNode::setSpecularTexture(const std::string& fullpath)
{
	_material->getMaterialDetail()->setSpecularTextureMap(MAT_TEXTURE_SPECULAR);
	_textureCache->addTexture(MAT_TEXTURE_SPECULAR, fullpath);
}

void render::DrawNode::setAlphaTexture(const std::string& fullpath)
{
	_material->getMaterialDetail()->setAlphaTextureMap(MAT_TEXTURE_ALPHA);
	_textureCache->addTexture(MAT_TEXTURE_ALPHA, fullpath);
}

void render::DrawNode::setBumpTexture(const std::string& fullpath)
{
	_material->getMaterialDetail()->setBumpTextureMap(MAT_TEXTURE_BUMP);
	_textureCache->addTexture(MAT_TEXTURE_BUMP, fullpath);
}

const render::Texture* render::DrawNode::getTexture(const std::string& name) const
{
	return _textureCache->getTexture(name);
}

const render::Texture* render::DrawNode::getTexture() const
{
	return getTexture(MAT_TEXTURE_NAME);
}

void render::DrawNode::setShaderProgram(ShaderProgram* program)
{
	_material->setShaderProgram(program);
}

void render::DrawNode::setShaderProgramFunc(const ShaderProgramFunc& func)
{
	_material->setProgramFunc(func);
}

void render::DrawNode::beforeDraw()
{
	_fragOperator->begin();

	_fragOperator->update();
}

void DrawNode::onDraw()
{
	auto nMatID = _mesh->getMeshDetail()->getMaterial();

	if (_material->getShaderProgram() != nullptr)
	{
		_material->beginApplyWithShader(this, _mesh, _textureCache);

		_mesh->drawWithBufferObject();

		_material->endApplyWithShader(_mesh, _textureCache);
	}
	else
	{
		_material->beginApply(_textureCache);

		_mesh->drawWithClientArray();

		_material->endApply(_textureCache);
	}
}

void render::DrawNode::afterDraw()
{
	_fragOperator->end();
}

void render::DrawNode::initBufferObject()
{
	auto pMaterialDetail = CREATE_OBJECT(sys::MaterialDetail);
	pMaterialDetail->setName(DRAW_MATERIAL_INDEX);
	_material->setMaterialDetail(pMaterialDetail);

	auto pMeshDetail = CREATE_OBJECT(sys::MeshDetail);
	pMeshDetail->setMaterial(DRAW_MATERIAL_INDEX);
	_mesh->setMeshDetail(pMeshDetail);
}

void render::DrawNode::updateBufferData()
{
	_mesh->updateBufferData();
}
