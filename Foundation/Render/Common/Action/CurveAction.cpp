#include "CurveAction.h"
#include "Common/Tool/Tool.h"
#include "../Node/Node.h"
render::CurveAction::CurveAction()
{

}

render::CurveAction::~CurveAction()
{

}

//////////////////////////////////////////////////////////////////////////

render::BezierAction2::BezierAction2()
{

}

render::BezierAction2::~BezierAction2()
{

}

render::BezierAction2* render::BezierAction2::create(const math::Vector3& p0, const math::Vector3& p1)
{
	auto action = CREATE_ACTION(BezierAction2);
	action->setControlParameters(p0, p1);
	return action;
}

void render::BezierAction2::setControlParameters(const math::Vector3& p0, const math::Vector3& p1)
{
	_controlPoint0 = p0;
	_controlPoint1 = p1;
}

math::Vector3 render::BezierAction2::getPosition(float percent)
{
	return (1 - percent) * _controlPoint0 + percent * _controlPoint1;
}

//////////////////////////////////////////////////////////////////////////

render::BezierAction3::BezierAction3()
{

}

render::BezierAction3::~BezierAction3()
{

}

render::BezierAction3* render::BezierAction3::create(const math::Vector3& p0, const math::Vector3& p1, const math::Vector3& p2)
{
	auto action = CREATE_ACTION(BezierAction3);
	action->setControlParameters(p0, p1, p2);
	return action;
}

void render::BezierAction3::setControlParameters(const math::Vector3& p0, const math::Vector3& p1, const math::Vector3& p2)
{
	_controlPoint0 = p0;
	_controlPoint1 = p1;
	_controlPoint2 = p2;
}

math::Vector3 render::BezierAction3::getPosition(float percent)
{
	return pow((1 - percent), 2) * _controlPoint0 + 2 * (1 - percent) * percent * _controlPoint1 + pow(percent, 2) * _controlPoint2;
}
//////////////////////////////////////////////////////////////////////////

render::CircleAction::CircleAction()
{

}

render::CircleAction::~CircleAction()
{

}

render::CircleAction* render::CircleAction::create(const math::Vector3& centerPos, float circleRadius, const math::Vector3& eularAngle)
{
	auto action = CREATE_ACTION(CircleAction);
	action->setControlParameters(centerPos, circleRadius, eularAngle);
	return action;
}

void render::CircleAction::setControlParameters(const math::Vector3& centerPos, float circleRadius, const math::Vector3& eularAngle)
{
	_centerPoint = centerPos;
	_cicleRadius = circleRadius;

	Tool::convertToRadian(eularAngle, _eularRadian);
}

math::Vector3 render::CircleAction::getPosition(float percent)
{
	float angle = percent * 2 * M_PI;
	float x = _cicleRadius * cosf(angle);
	float y = _cicleRadius * sinf(angle);

	math::Vector3 pos(x, y);

	math::Matrix4x4 transpose;
	math::Matrix4x4::getRST(_eularRadian, math::Vector3(1, 1, 1), pos, transpose);

	math::Matrix4x4 center;
	center.setTranslate(_centerPoint);

	math::Matrix4x4 result = transpose * center;

	return result.getPosition();
}
//////////////////////////////////////////////////////////////////////////
render::EllipseAction::EllipseAction()
{

}

render::EllipseAction::~EllipseAction()
{

}

render::EllipseAction* render::EllipseAction::create(const math::Vector3& centerPos, float radiusX, float radiusY, const math::Vector3& eularAngle)
{
	auto action = CREATE_ACTION(EllipseAction);
	action->setControlParameters(centerPos, radiusX, radiusY, eularAngle);
	return action;
}

void render::EllipseAction::setControlParameters(const math::Vector3& centerPos, float radiusX, float radiusY, const math::Vector3& eularAngle)
{
	_centerPoint = centerPos;
	_radiusX = radiusX;
	_radiusY = radiusY;

	Tool::convertToRadian(eularAngle, _eularRadian);
}

math::Vector3 render::EllipseAction::getPosition(float percent)
{
	float angle = percent * 2 * M_PI;

	float x = _radiusX * cosf(angle);
	float y = _radiusY * sinf(angle);

	math::Vector3 pos(x, y);
	math::Matrix4x4 transpose;

	math::Matrix4x4::getRST(_eularRadian, math::Vector3(1, 1, 1), pos, transpose);

	math::Matrix4x4 center;
	center.setTranslate(_centerPoint);

	math::Matrix4x4 result = transpose * center;

	math::Vector3 newPos = result.getPosition();

	return newPos;
}