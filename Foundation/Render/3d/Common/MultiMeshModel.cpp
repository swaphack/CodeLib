#include "MultiMeshModel.h"
#include "Graphic/import.h"
#include "Common/DrawNode/import.h"
#include "Common/Tool/Tool.h"
#include "Common/Fragment/import.h"

render::MultiMeshModel::MultiMeshModel()
{

}

render::MultiMeshModel::~MultiMeshModel()
{

}

bool render::MultiMeshModel::init()
{
	if (!MultiDrawNode::init())
	{
		return false;
	}

	_notify->addListen(NodeNotifyType::BODY, [this]() {
		this->calBoxData();
		});

	FragmentDepthTest* pDepthTest = this->getFragOperator()->getHandle<FragmentDepthTest>();
	if (pDepthTest)
	{
		pDepthTest->setEnabled(true);
	}

	return true;
}

void render::MultiMeshModel::setBoxVisible(bool bVisible)
{
	_bBoxVisible = bVisible;
}

bool render::MultiMeshModel::isBoxVisible() const
{
	return _bBoxVisible;
}

bool render::MultiMeshModel::containTouchPoint(float x, float y)
{
	return _realBoxVertex.containPointByPolygon(x, y);
}

void render::MultiMeshModel::calBoxData()
{
	Tool::calCube(math::Vector3(), _volume, _anchor, _boxVertex);

	math::Vector3 frontLeftDown = this->convertLocalPostitionToWorld(_boxVertex.front.leftDown);
	math::Vector3 frontRightDown = this->convertLocalPostitionToWorld(_boxVertex.front.rightDown);
	math::Vector3 frontRightUp = this->convertLocalPostitionToWorld(_boxVertex.front.rightUp);
	math::Vector3 frontLeftUp = this->convertLocalPostitionToWorld(_boxVertex.front.leftUp);

	math::Vector3 backLeftDown = this->convertLocalPostitionToWorld(_boxVertex.back.leftDown);
	math::Vector3 backRightDown = this->convertLocalPostitionToWorld(_boxVertex.back.rightDown);
	math::Vector3 backRightUp = this->convertLocalPostitionToWorld(_boxVertex.back.rightUp);
	math::Vector3 backLeftUp = this->convertLocalPostitionToWorld(_boxVertex.back.leftUp);

	_realBoxVertex.setFrontLeftDownPosition(frontRightDown);
	_realBoxVertex.setFrontRightDownPosition(frontRightDown);
	_realBoxVertex.setFrontRightUpPosition(frontRightUp);
	_realBoxVertex.setFrontLeftUpPosition(frontLeftUp);

	_realBoxVertex.setBackLeftDownPosition(backLeftDown);
	_realBoxVertex.setBackRightDownPosition(backRightDown);
	_realBoxVertex.setBackRightUpPosition(backRightUp);
	_realBoxVertex.setBackLeftUpPosition(backLeftUp);
}

void render::MultiMeshModel::drawBox()
{
	if (!isBoxVisible())
	{
		return;
	}
	GLVertex::setColor(1.0f, 0.0f, 0.0f, 1.0f);
	GLState::setLineWidth(5);

	ShapeMode type = ShapeMode::POLYGON;

	GLVertex::beginMode(type);
	GLVertex::setVertex(_boxVertex.front.leftDown);
	GLVertex::setVertex(_boxVertex.front.rightDown);
	GLVertex::setVertex(_boxVertex.front.rightUp);
	GLVertex::setVertex(_boxVertex.front.leftUp);
	GLVertex::endMode();

	GLVertex::beginMode(type);
	GLVertex::setVertex(_boxVertex.back.leftDown);
	GLVertex::setVertex(_boxVertex.back.rightDown);
	GLVertex::setVertex(_boxVertex.back.rightUp);
	GLVertex::setVertex(_boxVertex.back.leftUp);
	GLVertex::endMode();

	GLVertex::beginMode(type);
	GLVertex::setVertex(_boxVertex.left.leftDown);
	GLVertex::setVertex(_boxVertex.left.rightDown);
	GLVertex::setVertex(_boxVertex.left.rightUp);
	GLVertex::setVertex(_boxVertex.left.leftUp);
	GLVertex::endMode();

	GLVertex::beginMode(type);
	GLVertex::setVertex(_boxVertex.right.leftDown);
	GLVertex::setVertex(_boxVertex.right.rightDown);
	GLVertex::setVertex(_boxVertex.right.rightUp);
	GLVertex::setVertex(_boxVertex.right.leftUp);
	GLVertex::endMode();

	GLVertex::beginMode(type);
	GLVertex::setVertex(_boxVertex.top.leftDown);
	GLVertex::setVertex(_boxVertex.top.rightDown);
	GLVertex::setVertex(_boxVertex.top.rightUp);
	GLVertex::setVertex(_boxVertex.top.leftUp);
	GLVertex::endMode();

	GLVertex::beginMode(type);
	GLVertex::setVertex(_boxVertex.bottom.leftDown);
	GLVertex::setVertex(_boxVertex.bottom.rightDown);
	GLVertex::setVertex(_boxVertex.bottom.rightUp);
	GLVertex::setVertex(_boxVertex.bottom.leftUp);
	GLVertex::endMode();
}

void render::MultiMeshModel::afterDrawNode()
{
	this->drawAllChildren();

	this->drawBox();
}

