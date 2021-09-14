#include "ModelFile.h"
#include "Common/Material/import.h"
#include "Common/Mesh/import.h"
#include "Common/DrawNode/DrawTextureCache.h"
#include "Common/Tool/VertexTool.h"

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
	// 添加属性改变监听
	addNotifyListener(NodeNotifyType::BODY, [this]() {
		onModelFileBodyChange();
	});

	addNotifyListener(NodeNotifyType::MODEL, [this]() {
		onLoadModelDetail();
		this->updateMeshData();
	});

	addNotifyListener(NodeNotifyType::SPACE, [this]() {
		onModelFileWorldBodyChange();
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

void render::ModelFile::onModelFileBodyChange()
{
	render::VertexTool::setTexture3DVertices(&_localCubeVertex, math::Vector3(), _volume, _anchor);
	onModelFileWorldBodyChange();
}

void render::ModelFile::onModelFileWorldBodyChange()
{
	_worldCubeVertex.setFrontLeftBottomPosition(this->convertLocalPostitionToWorld(_localCubeVertex.front.getLeftBottomPosition()));
	_worldCubeVertex.setFrontRightBottomPosition(this->convertLocalPostitionToWorld(_localCubeVertex.front.getRightBottomPosition()));
	_worldCubeVertex.setFrontRightTopPosition(this->convertLocalPostitionToWorld(_localCubeVertex.front.getRightTopPosition()));
	_worldCubeVertex.setFrontLeftTopPosition(this->convertLocalPostitionToWorld(_localCubeVertex.front.getLeftTopPosition()));

	_worldCubeVertex.setBackLeftBottomPosition(this->convertLocalPostitionToWorld(_localCubeVertex.back.getLeftBottomPosition()));
	_worldCubeVertex.setBackRightBottomPosition(this->convertLocalPostitionToWorld(_localCubeVertex.back.getRightBottomPosition()));
	_worldCubeVertex.setBackRightTopPosition(this->convertLocalPostitionToWorld(_localCubeVertex.back.getRightTopPosition()));
	_worldCubeVertex.setBackLeftTopPosition(this->convertLocalPostitionToWorld(_localCubeVertex.back.getLeftTopPosition()));

	setBoxVertices(_worldCubeVertex);
}
