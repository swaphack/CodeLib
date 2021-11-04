#include "ModelFile.h"
#include "Common/Material/import.h"
#include "Common/Mesh/import.h"
#include "Common/DrawNode/DrawTextureCache.h"
#include "Common/Tool/VertexTool.h"
#include "Box/BoxSpace.h"

render::ModelFile::ModelFile()
{
	this->setBoxNode(this);
}

render::ModelFile::~ModelFile()
{

}

bool render::ModelFile::init()
{
	if (!MultiDrawNode::init())
	{
		return false;
	}

	Box3DProtocol::initBox3D(this);

	// 添加属性改变监听
	addNotifyListener(NodeNotifyType::MODEL, [this]() {
		onLoadModelDetail();
		this->updateMeshData();
	});

	return true;
}

void render::ModelFile::setModelData(sys::ModelDetail* detail)
{
	if (detail == nullptr)
	{
		return;
	}
	SAFE_RETAIN(detail);
	SAFE_RELEASE(_modelDetail);
	_modelDetail = detail;
	if (_loadFinishedCallback == nullptr)
	{
		onLoadModelDetail();
	}
	this->notify(NodeNotifyType::MODEL);
}

void render::ModelFile::setAsynLoadedCallback(const LoadedModelCallback& func)
{
	_loadFinishedCallback = func;
}

bool render::ModelFile::containPoint(const math::Vector2& touchPoint)
{
	return G_BOXSPACE->containsTouchPoint3D(this, touchPoint);
}

void render::ModelFile::onDraw()
{
	if (!_bloadedModel)
	{
		return;
	}

	MultiDrawNode::onDraw();
}

void render::ModelFile::onLoadModelDetail()
{
	if (_modelDetail == nullptr) return;

	_materiales->setModelDetail(_modelDetail);
	_meshes->setModelDetail(_modelDetail);
	for (auto item : _modelDetail->getTexturePaths())
	{
		_textureCache->addTexture(item.first, item.second);
	}

	SAFE_RELEASE(_modelDetail);
	_modelDetail = nullptr;
	if (_loadFinishedCallback)
	{
		_loadFinishedCallback(this);
		_loadFinishedCallback = nullptr;
	}
	_bloadedModel = true;
}