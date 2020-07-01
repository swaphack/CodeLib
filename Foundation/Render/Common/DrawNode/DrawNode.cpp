#include "DrawNode.h"
#include "Graphic/import.h"
#include "Common/Material/import.h"
#include "Common/Mesh/import.h"
#include "FragmentOperator.h"
#include "Common/Texture/import.h"

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

	initBufferObject();

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

render::Material* render::DrawNode::getMaterial(const std::string& name)
{
	return _materiales->getMaterial(name);
}

render::Mesh* render::DrawNode::getMesh(const std::string& name)
{
	return _meshes->getMesh(name);
}

void render::DrawNode::setTexture(const std::string& fullpath)
{
	this->setTexture(MAT_TEXTURE_NAME, fullpath);
}

void render::DrawNode::setTexture(const std::string& name, const std::string& fullpath)
{
	_materiales->addTexture(name, fullpath);
	for (auto item : _materiales->getMaterials())
	{
		item.second->getMaterialDetail()->setAmbientTextureMap(name);
	}
}

void render::DrawNode::setTexture(const std::string& name, const Texture* texture)
{
	_materiales->addTexture(name, texture);
	for (auto item : _materiales->getMaterials())
	{
		item.second->getMaterialDetail()->setAmbientTextureMap(name);
	}
}

void render::DrawNode::setTexture(const Texture* texture)
{
	setTexture(MAT_TEXTURE_NAME, texture);
}

void render::DrawNode::setAmbientTexture(const std::string& fullpath)
{
	setTexture(MAT_TEXTURE_NAME, fullpath);
}

void render::DrawNode::setDiffuseTexture(const std::string& fullpath)
{
	_materiales->addTexture(MAT_TEXTURE_DIFFUSE, fullpath);

	for (auto item : _materiales->getMaterials())
	{
		item.second->getMaterialDetail()->setDiffuseTextureMap(MAT_TEXTURE_DIFFUSE);
	}
}

void render::DrawNode::setSpecularTexture(const std::string& fullpath)
{
	_materiales->addTexture(MAT_TEXTURE_SPECULAR, fullpath);

	for (auto item : _materiales->getMaterials())
	{
		item.second->getMaterialDetail()->setSpecularTextureMap(MAT_TEXTURE_SPECULAR);
	}
}

void render::DrawNode::setAlphaTexture(const std::string& fullpath)
{
	_materiales->addTexture(MAT_TEXTURE_ALPHA, fullpath);

	for (auto item : _materiales->getMaterials())
	{
		item.second->getMaterialDetail()->setAlphaTextureMap(MAT_TEXTURE_ALPHA);
	}
}

void render::DrawNode::setBumpTexture(const std::string& fullpath)
{
	_materiales->addTexture(MAT_TEXTURE_BUMP, fullpath);

	for (auto item : _materiales->getMaterials())
	{
		item.second->getMaterialDetail()->setBumpTextureMap(MAT_TEXTURE_BUMP);
	}
}

void render::DrawNode::setShaderProgram(ShaderProgram* program)
{
	for (auto item : _materiales->getMaterials())
	{
		item.second->setShaderProgram(program);
	}
}

void render::DrawNode::setShaderProgramFunc(const ShaderProgramFunc& func)
{
	for (auto item : _materiales->getMaterials())
	{
		item.second->setProgramFunc(func);
	}
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

void render::DrawNode::initBufferObject()
{
	sys::ModelDetail* pModelDetail = CREATE_OBJECT(sys::ModelDetail);

	auto pMat = CREATE_OBJECT(sys::MaterialDetail);
	pModelDetail->addMaterial(DRAW_MATERIAL_INDEX, pMat);

	auto pMesh = CREATE_OBJECT(sys::MeshDetail);
	pMesh->setMaterial(DRAW_MATERIAL_INDEX);
	pModelDetail->addMesh(DRAW_MESH_INDEX, pMesh);

	_materiales->setModelDetail(pModelDetail);
	_meshes->setModelDetail(pModelDetail);
}

void render::DrawNode::updateBufferData()
{
	if (_materiales)
	{
		_materiales->updateMatTexture();
	}
	if (_meshes)
	{
		_meshes->updateBufferData();
	}
}
