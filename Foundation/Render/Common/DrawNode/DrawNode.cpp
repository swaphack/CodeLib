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

void render::DrawNode::addMaterialTexture(const std::string& matName, const std::string& fullpath)
{
	_materiales->addTexture(matName, fullpath);
}

void render::DrawNode::setTexture(const Texture* texture)
{
	this->addMaterialTexture(MAT_TEXTURE_NAME, texture);
	this->setTextureName(MAT_TEXTURE_NAME);
}

void render::DrawNode::addMaterialTexture(const std::string& matName, const Texture* texture)
{
	_materiales->addTexture(matName, texture);
}

void render::DrawNode::setTextureName(const std::string& textureName)
{
	for (auto item : _materiales->getMaterials())
	{
		item.second->getMaterialDetail()->setAmbientTextureMap(textureName);
	}
}

void render::DrawNode::setAmbientTextureName(const std::string& textureName)
{
	for (auto item : _materiales->getMaterials())
	{
		item.second->getMaterialDetail()->setAmbientTextureMap(textureName);
	}
}

void render::DrawNode::setDiffuseTextureName(const std::string& textureName)
{
	for (auto item : _materiales->getMaterials())
	{
		item.second->getMaterialDetail()->setDiffuseTextureMap(textureName);
	}
}

void render::DrawNode::setSpecularTextureName(const std::string& textureName)
{
	for (auto item : _materiales->getMaterials())
	{
		item.second->getMaterialDetail()->setSpecularTextureMap(textureName);
	}
}

void render::DrawNode::setAlphaTextureName(const std::string& textureName)
{
	for (auto item : _materiales->getMaterials())
	{
		item.second->getMaterialDetail()->setAlphaTextureMap(textureName);
	}
}

void render::DrawNode::setBumpTextureName(const std::string& textureName)
{
	for (auto item : _materiales->getMaterials())
	{
		item.second->getMaterialDetail()->setBumpTextureMap(textureName);
	}
}

render::ShaderProgram* render::DrawNode::getMaterialShaderProgram(const std::string& matName)
{
	auto pMat = _materiales->getMaterial(matName);
	if (!pMat)
	{
		return nullptr;
	}

	return pMat->getShaderProgram();
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
