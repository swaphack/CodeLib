#include "DrawNode.h"
#include "Graphic/import.h"
#include "Common/Material/import.h"
#include "Common/Mesh/import.h"
#include "FragmentOperator.h"
#include "Common/Texture/import.h"
#include "Common/Shader/ShaderProgram.h"
#include "DrawTextureCache.h"
#include "DrawCore.h"
#include "FragmentOperator.h"
#include "Common/Fragment/import.h"
#include "Common/Scene/Camera.h"
#include "macros.h"

using namespace render;

DrawNode::DrawNode()
{
	_material = CREATE_OBJECT(Material);
	_material->setNode(this);
	SAFE_RETAIN(_material);

	_mesh = CREATE_OBJECT(Mesh);
	_mesh->setNode(this);
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
	SAFE_RELEASE(_textureCache);

	G_DRAWCORE->removeDrawParameter(&_drawParameter);
}

bool render::DrawNode::init()
{
	if (!Node::init())
	{
		return false;
	}

	FragmentBlend* pBlend = this->getFragOperator()->getHandle<FragmentBlend>();
	if (pBlend)
	{
		pBlend->setEnabled(true);
	}

	addNotifyListener(NodeNotifyType::COLOR, [this]() {
		this->onDrawNodeColorChange();
	});

	addNotifyListener(NodeNotifyType::Draw, [this]() {
		this->initDrawParameter();
	});

	addNotifyListener(NodeNotifyType::MESH, [this]() {
		this->updateMeshData();
	});

	onBlendChange();
	onColorChange();

	initBufferObject();

	return true;
}

void DrawNode::draw()
{
	uint32_t nVerticeSize = _mesh->getMeshDetail()->getVertices().getSize();

	if (nVerticeSize == 0)
	{
		return;
	}

	if (_mesh->getMeshDetail()->getIndices().getLength() <= 0)
	{
		return;
	}

	this->beforeDraw();

	this->onDraw();

	this->afterDraw();
}

FragmentOperator* render::DrawNode::getFragOperator() const
{
	return _fragOperator;
}

render::Material* render::DrawNode::getMaterial() const
{
	return _material;
}

render::Mesh* render::DrawNode::getMesh() const
{
	return _mesh;
}

DrawParameter* render::DrawNode::getDrawParameter()
{
	return &_drawParameter;
}

DrawTextureCache* render::DrawNode::getDrawTextureCache() const
{
	return _textureCache;
}

void render::DrawNode::setTexture(const std::string& fullpath)
{
	_material->getMaterialDetail()->setTexture(MAT_TEXTURE_NAME);
	_textureCache->addTexture(MAT_TEXTURE_NAME, fullpath);
}

void render::DrawNode::setTexture(const Texture* texture)
{
	_material->getMaterialDetail()->setTexture(MAT_TEXTURE_NAME);
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

void render::DrawNode::setNormalTexture(const std::string& fullpath)
{
	_material->getMaterialDetail()->setNormalTextureMap(MAT_TEXTURE_NORMAL);
	_textureCache->addTexture(MAT_TEXTURE_NORMAL, fullpath);
}

void render::DrawNode::setShadowTexture(const Texture* texture)
{
	_material->getMaterialDetail()->setShadowTextureMap(MAT_TEXTURE_SHADOW);
	_textureCache->addTexture(MAT_TEXTURE_SHADOW, texture);
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
	this->notify(render::NodeNotifyType::Draw);
}

ShaderProgram* render::DrawNode::getShaderProgram() const
{
	return _material->getShaderProgram();
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
	if (_mesh == nullptr || _material == nullptr || _mesh->getMeshDetail() == nullptr)
	{
		return;
	}
	G_DRAWCORE->render(this);
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
	pMeshDetail->setMaterialName(DRAW_MATERIAL_INDEX);
	_mesh->setMeshDetail(pMeshDetail);
}

void render::DrawNode::updateMeshData()
{
	if (!_mesh)
	{
		return;
	}

	_mesh->setComputeNormal(false);
	_mesh->setComputeTangent(false);

	if (_material != nullptr)
	{
		auto program = _material->getShaderProgram();
		if (program)
		{
			program->use();
			// 计算法线
			if (_material->hasAttrib(VertexDataType::NORMAL))
			{
				_mesh->setComputeNormal(true);
			}

			// 计算切线
			if (_material->hasAttrib(VertexDataType::TANGENT))
			{
				_mesh->setComputeTangent(true);
			}
			program->unuse();
		}
	}

	_mesh->initMeshOtherDetail();
	_mesh->updateBufferData();
	
	this->initDrawParameter();
}

void render::DrawNode::initDrawParameter()
{
	_drawParameter.node = this;
	_drawParameter.mesh = _mesh;
	_drawParameter.material = _material;
	_drawParameter.textureCache = _textureCache;
	_drawParameter.tessilation = isTessilationEnable();
	
	int zOrder = G_DRAWCORE->getDrawZOrder(this);
	_drawParameter.localZOrder = zOrder / 1000.0f;
	G_DRAWCORE->addDrawParameter(&_drawParameter);
}

void render::DrawNode::onColorChange()
{
	this->notify(NodeNotifyType::COLOR);
}

void render::DrawNode::onDrawNodeColorChange()
{
	auto pMaterialDetail = _material->getMaterialDetail();
	if (pMaterialDetail)
	{
		pMaterialDetail->setEmission(_color[0], _color[1], _color[2], _color[3]);
	}
	
}

void render::DrawNode::onBlendChange()
{
	FragmentBlend* pBlend = this->getFragOperator()->getHandle<FragmentBlend>();
	if (pBlend)
	{
		pBlend->setBlendFactor(_blendParam.src, _blendParam.dest);

		pBlend->setBlendColor(_blendColor);
	}
}
