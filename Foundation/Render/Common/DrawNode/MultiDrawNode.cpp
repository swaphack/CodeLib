#include "MultiDrawNode.h"
#include "Graphic/import.h"
#include "Common/Material/import.h"
#include "Common/Mesh/import.h"
#include "FragmentOperator.h"
#include "Common/Texture/import.h"
#include "DrawTextureCache.h"
#include "DrawCore.h"
#include "Common/Shader/ShaderProgram.h"
#include "Common/Scene/Camera.h"

using namespace render;

MultiDrawNode::MultiDrawNode()
{
	_materiales = CREATE_OBJECT(Materials);
	_materiales->setNode(this);
	SAFE_RETAIN(_materiales);

	_meshes = CREATE_OBJECT(Meshes);
	_meshes->setNode(this);
	SAFE_RETAIN(_meshes);

	_fragOperator = CREATE_OBJECT(FragmentOperator);
	SAFE_RETAIN(_fragOperator);

	_textureCache = CREATE_OBJECT(DrawTextureCache);
	SAFE_RETAIN(_textureCache);
}

MultiDrawNode::~MultiDrawNode()
{
	SAFE_RELEASE(_materiales);
	SAFE_RELEASE(_meshes);
	SAFE_RELEASE(_fragOperator);
	SAFE_RELEASE(_textureCache);
	for (auto& item : _drawParameters)
	{
		G_DRAWCORE->removeDrawParameter(&item.second);
	}
}

bool render::MultiDrawNode::init()
{
	if (!Node::init())
	{
		return false;
	}

	addNotifyListener(NodeNotifyType::COLOR, [this]() {
		this->onDrawNodeColorChange();
	});

	addNotifyListener(NodeNotifyType::Draw, [this]() {
		this->initDrawParameters();
	});

	onColorChange();

	initBufferObject();

	return true;
}

void MultiDrawNode::draw()
{
	this->beforeDraw();

	this->onDraw();

	this->afterDraw();
}

Materials* render::MultiDrawNode::getMaterials() const
{
	return _materiales;
}

Meshes* render::MultiDrawNode::getMeshes() const
{
	return _meshes;
}

FragmentOperator* render::MultiDrawNode::getFragOperator() const
{
	return _fragOperator;
}

DrawTextureCache* render::MultiDrawNode::getDrawTextureCache() const
{
	return _textureCache;
}

DrawParameter* render::MultiDrawNode::getDrawParameter(const std::string& meshName)
{
	auto it = _drawParameters.find(meshName);
	if (it == _drawParameters.end()) return nullptr;
	return &it->second;
}

render::Material* render::MultiDrawNode::getMaterial(const std::string& name)
{
	return _materiales->getMaterial(name);
}

render::Mesh* render::MultiDrawNode::getMesh(const std::string& name)
{
	return _meshes->getMesh(name);
}

void render::MultiDrawNode::setTexture(const std::string& fullpath)
{
	_textureCache->addTexture(MAT_TEXTURE_NAME, fullpath);

	for (auto item : _materiales->getMaterials())
	{
		item.second->getMaterialDetail()->setAmbientTextureMap(MAT_TEXTURE_NAME);
	}
}

void render::MultiDrawNode::setTexture(const Texture* texture)
{
	_textureCache->addTexture(MAT_TEXTURE_NAME, texture);

	for (auto item : _materiales->getMaterials())
	{
		item.second->getMaterialDetail()->setAmbientTextureMap(MAT_TEXTURE_NAME);
	}
}

void render::MultiDrawNode::setAmbientTexture(const std::string& fullpath)
{
	_textureCache->addTexture(MAT_TEXTURE_AMBIENT, fullpath);

	for (auto item : _materiales->getMaterials())
	{
		item.second->getMaterialDetail()->setAmbientTextureMap(MAT_TEXTURE_AMBIENT);
	}
}

void render::MultiDrawNode::setDiffuseTexture(const std::string& fullpath)
{
	_textureCache->addTexture(MAT_TEXTURE_DIFFUSE, fullpath);

	for (auto item : _materiales->getMaterials())
	{
		item.second->getMaterialDetail()->setDiffuseTextureMap(MAT_TEXTURE_DIFFUSE);
	}
}

void render::MultiDrawNode::setSpecularTexture(const std::string& fullpath)
{
	_textureCache->addTexture(MAT_TEXTURE_SPECULAR, fullpath);

	for (auto item : _materiales->getMaterials())
	{
		item.second->getMaterialDetail()->setSpecularTextureMap(MAT_TEXTURE_SPECULAR);
	}
}

void render::MultiDrawNode::setAlphaTexture(const std::string& fullpath)
{
	_textureCache->addTexture(MAT_TEXTURE_ALPHA, fullpath);

	for (auto item : _materiales->getMaterials())
	{
		item.second->getMaterialDetail()->setAlphaTextureMap(MAT_TEXTURE_ALPHA);
	}
}

void render::MultiDrawNode::setBumpTexture(const std::string& fullpath)
{
	_textureCache->addTexture(MAT_TEXTURE_BUMP, fullpath);

	for (auto item : _materiales->getMaterials())
	{
		item.second->getMaterialDetail()->setBumpTextureMap(MAT_TEXTURE_BUMP);
	}
}

void render::MultiDrawNode::setNormalTexture(const std::string& fullpath)
{
	_textureCache->addTexture(MAT_TEXTURE_NORMAL, fullpath);

	for (auto item : _materiales->getMaterials())
	{
		item.second->getMaterialDetail()->setNormalTextureMap(MAT_TEXTURE_NORMAL);
	}
}

void render::MultiDrawNode::setShadowTexture(const Texture* texture)
{
	_textureCache->addTexture(MAT_TEXTURE_SHADOW, texture);

	for (auto item : _materiales->getMaterials())
	{
		item.second->getMaterialDetail()->setShadowTextureMap(MAT_TEXTURE_SHADOW);
	}
}

void render::MultiDrawNode::setShaderProgram(ShaderProgram* program)
{
	for (auto item : _materiales->getMaterials())
	{
		item.second->setShaderProgram(program);
	}
}

void render::MultiDrawNode::setShaderProgramFunc(const ShaderProgramFunc& func)
{
	for (auto item : _materiales->getMaterials())
	{
		item.second->setProgramFunc(func);
	}
}

void render::MultiDrawNode::beforeDraw()
{
	_fragOperator->begin();

	_fragOperator->update();
}

void MultiDrawNode::onDraw()
{
	G_DRAWCORE->render(this);
}

void render::MultiDrawNode::afterDraw()
{
	_fragOperator->end();
}

void render::MultiDrawNode::initBufferObject()
{
	sys::ModelDetail* pModelDetail = CREATE_OBJECT(sys::ModelDetail);

	auto pMat = CREATE_OBJECT(sys::MaterialDetail);
	pModelDetail->addMaterial(DRAW_MATERIAL_INDEX, pMat);

	auto pMesh = CREATE_OBJECT(sys::MeshDetail);
	pMesh->setMaterialName(DRAW_MATERIAL_INDEX);
	pModelDetail->addMesh(DRAW_MESH_INDEX, pMesh);

	_materiales->setModelDetail(pModelDetail);
	_meshes->setModelDetail(pModelDetail);
}

void render::MultiDrawNode::updateMeshData()
{
	if (_meshes && _materiales)
	{
		for (auto item : _meshes->getMeshes())
		{
			auto pMesh = item.second;
			if (!pMesh)
			{
				continue;
			}

			pMesh->setComputeNormal(false);
			pMesh->setComputeTangent(false);

			if (!pMesh->getMeshDetail())
			{
				continue;
			}

			auto pMaterial = _materiales->getMaterial(pMesh->getMeshDetail()->getMaterialName());
			if (!pMaterial)
			{
				continue;
			}

			auto program = pMaterial->getShaderProgram();
			if (!program)
			{
				continue;
			}

			program->use();
			// 计算法线
			if (pMaterial->hasAttrib(VertexDataType::NORMAL))
			{
				pMesh->setComputeNormal(true);
			}

			// 计算切线
			if (pMaterial->hasAttrib(VertexDataType::TANGENT))
			{
				pMesh->setComputeTangent(true);
			}
			program->unuse();
		}
		
	}

	if (_meshes)
	{
		_meshes->updateBufferData();
	}

	this->initDrawParameters();
}

void render::MultiDrawNode::initDrawParameters()
{
	if (this->getMeshes() == nullptr || this->getMaterials() == nullptr)
	{
		return;
	}
	_drawParameters.clear();

	auto pMateriales = this->getMaterials();
	for (auto item : this->getMeshes()->getMeshes())
	{
		auto pMesh = item.second;
		auto nMatID = pMesh->getMeshDetail()->getMaterialName();
		auto pMaterial = pMateriales->getMaterial(nMatID);
		if (pMaterial == nullptr)
		{// 临时处理
			continue;
		}
		auto program = pMaterial->getShaderProgram();
		DrawParameter& drawParameter = _drawParameters[item.first];
		drawParameter.node = this;
		drawParameter.mesh = pMesh;
		drawParameter.material = pMaterial;
		drawParameter.textureCache = _textureCache;
		drawParameter.matrix = pMesh->getMeshDetail()->getMatrix();

		//G_DRAWCORE->addDrawParameter(&drawParameter);
	}
}

void render::MultiDrawNode::onColorChange()
{
	this->notify(NodeNotifyType::COLOR);
	
}

void render::MultiDrawNode::onDrawNodeColorChange()
{
	for (auto item : _materiales->getMaterials())
	{
		item.second->getMaterialDetail()->setEmission(_color[0], _color[1], _color[2], _color[3]);
	}
}
