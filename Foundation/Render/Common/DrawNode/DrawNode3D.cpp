#include "DrawNode3D.h"

#include "Common/Fragment/import.h"
#include "Common/Material/import.h"
#include "Common/Mesh/import.h"
#include "Common/DrawNode/import.h"
#include "Common/Tool/Tool.h"
#include "Graphic/import.h"
#include "Common/View/Camera.h"

render::DrawNode3D::DrawNode3D()
{

}

render::DrawNode3D::~DrawNode3D()
{
}



bool render::DrawNode3D::init()
{
	if (!DrawNode::init())
	{
		return false;
	}

	addNotifyListener(NodeNotifyType::BODY, [this]() {
		this->calBoxData();
		});

	FragmentDepthTest* pDepthTest = this->getFragOperator()->getHandle<FragmentDepthTest>();
	if (pDepthTest)
	{
		pDepthTest->setEnabled(true);
	}

	return true;
}

bool render::DrawNode3D::containPoint(const math::Vector2& touchPoint)
{
	//Camera::getMainCamera()
	/*
	math::Vector3 point(touchPoint.getX(), touchPoint.getY());

	math::Vector3 localPoint = _worldInverseMatrix * point;
	// ´ý²¹³ä
	return localPoint.getX() >= -getAnchorPointX() * getWidth()
		&& localPoint.getX() <= (1-getAnchorPointX()) * getWidth()
		&& localPoint.getY() >= -getAnchorPointY() * getHeight()
		&& localPoint.getY() <= (1 - getAnchorPointY()) * getHeight()
		&& localPoint.getZ() >= -getAnchorPointZ() * getDepth()
		&& localPoint.getZ() <= (1 - getAnchorPointZ()) * getDepth();

	*/

	return false;
}

void render::DrawNode3D::calBoxData()
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

void render::DrawNode3D::drawBox()
{
	if (!isBoxVisible())
	{
		return;
	}
	GLVertex::setColor(_boxColor);
	GLState::setLineWidth(_boxLineWidth);

	GLVertex::beginMode(ShapeMode::LINE_LOOP);
	GLVertex::setVertex(_boxVertex.front.leftDown);
	GLVertex::setVertex(_boxVertex.front.rightDown);
	GLVertex::setVertex(_boxVertex.front.rightUp);
	GLVertex::setVertex(_boxVertex.front.leftUp);
	GLVertex::endMode();

	GLVertex::beginMode(ShapeMode::LINE_LOOP);
	GLVertex::setVertex(_boxVertex.back.leftDown);
	GLVertex::setVertex(_boxVertex.back.rightDown);
	GLVertex::setVertex(_boxVertex.back.rightUp);
	GLVertex::setVertex(_boxVertex.back.leftUp);
	GLVertex::endMode();

	GLVertex::beginMode(ShapeMode::LINE_LOOP);
	GLVertex::setVertex(_boxVertex.left.leftDown);
	GLVertex::setVertex(_boxVertex.left.rightDown);
	GLVertex::setVertex(_boxVertex.left.rightUp);
	GLVertex::setVertex(_boxVertex.left.leftUp);
	GLVertex::endMode();

	GLVertex::beginMode(ShapeMode::LINE_LOOP);
	GLVertex::setVertex(_boxVertex.right.leftDown);
	GLVertex::setVertex(_boxVertex.right.rightDown);
	GLVertex::setVertex(_boxVertex.right.rightUp);
	GLVertex::setVertex(_boxVertex.right.leftUp);
	GLVertex::endMode();

	GLVertex::beginMode(ShapeMode::LINE_LOOP);
	GLVertex::setVertex(_boxVertex.top.leftDown);
	GLVertex::setVertex(_boxVertex.top.rightDown);
	GLVertex::setVertex(_boxVertex.top.rightUp);
	GLVertex::setVertex(_boxVertex.top.leftUp);
	GLVertex::endMode();

	GLVertex::beginMode(ShapeMode::LINE_LOOP);
	GLVertex::setVertex(_boxVertex.bottom.leftDown);
	GLVertex::setVertex(_boxVertex.bottom.rightDown);
	GLVertex::setVertex(_boxVertex.bottom.rightUp);
	GLVertex::setVertex(_boxVertex.bottom.leftUp);
	GLVertex::endMode();
}
