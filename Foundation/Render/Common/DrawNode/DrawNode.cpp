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

render::Material* render::DrawNode::getMaterial(int id)
{
	return _materiales->getMaterial(id);
}

render::Mesh* render::DrawNode::getMesh(int id)
{
	return _meshes->getMesh(id);
}

void render::DrawNode::addMaterialTexture(const std::string& name, const std::string& fullpath)
{
	_materiales->addTexture(name, fullpath);
}

void render::DrawNode::addMaterialTexture(const std::string& name, Texture2D* texture)
{
	_materiales->addTexture(name, texture);
}

void render::DrawNode::setAllMaterialsTexture(const std::string& name)
{
	int count = _materiales->getMaterialCount();
	for (int i = 0; i < count; i++)
	{
		auto pMat = _materiales->getMaterial(i);
		if (pMat)
		{
			pMat->getMaterialDetail()->setAmbientTextureMap(name);
		}
	}
}

void render::DrawNode::setMaterialTexture(int mat, const std::string& name)
{
	auto pMat = _materiales->getMaterial(mat);
	if (pMat)
	{
		pMat->getMaterialDetail()->setAmbientTextureMap(name);
	}
}

render::ShaderProgram* render::DrawNode::getMaterialShaderProgram(int mat)
{
	auto pMat = _materiales->getMaterial(mat);
	if (!pMat)
	{
		return nullptr;
	}

	return pMat->getShaderProgram();
}

void render::DrawNode::setAllMaterialsShaderProgram(ShaderProgram* program)
{
	int count = _materiales->getMaterialCount();
	for (int i = 0; i < count; i++)
	{
		auto pMat = _materiales->getMaterial(i);
		if (pMat)
		{
			pMat->setShaderProgram(program);
		}
	}
}

void render::DrawNode::setMaterialShaderProgram(int mat, ShaderProgram* program)
{
	auto pMat = _materiales->getMaterial(mat);
	if (pMat)
	{
		pMat->setShaderProgram(program);
	}
}

void render::DrawNode::setAllShaderProgramFunc(const ShaderProgramFunc& func)
{
	int count = _materiales->getMaterialCount();
	for (int i = 0; i < count; i++)
	{
		auto pMat = _materiales->getMaterial(i);
		if (pMat)
		{
			pMat->setProgramFunc(func);
		}
	}
}

void render::DrawNode::setMaterialShaderProgram(int mat, const ShaderProgramFunc& func)
{
	auto pMat = _materiales->getMaterial(mat);
	if (pMat)
	{
		pMat->setProgramFunc(func);
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
