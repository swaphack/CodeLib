#include "CartesianCoordinateSystem3D.h"
#include "Basic/base.h"
#include "Algebra/Vector/Vector2.h"
#include "Algebra/Vector/Vector3.h"

math::CartesianCoordinateSystem3D::CartesianCoordinateSystem3D()
{
	this->loadIdentity();
}

math::CartesianCoordinateSystem3D::~CartesianCoordinateSystem3D()
{

}

void math::CartesianCoordinateSystem3D::loadIdentity()
{
	_systemMatrix.reset();
	_systemMatrix[0] = 1;
	_systemMatrix[4] = 1;
	_systemMatrix[8] = 1;
}

math::CartesianCoordinateSystem3D math::CartesianCoordinateSystem3D::create(const Vector3& point, const Vector3& vector, Axis3D eAxis)
{
	math::CartesianCoordinateSystem3D system;
	if (vector.getMagnitudeSqr() == 0) 
	{// 0 向量
		return system;
	}

	float d = fabs(vector.getX()) + fabs(vector.getY());

	Vector3 va = vector;
	Vector3 vb;
	Vector3 vc;

	Vector3 vd;

	if (d > 0)
	{
		d = sqrt(va.getX() * va.getX() + va.getY() * va.getY());
		vb.setX(-va.getY() / d);
		vb.setY(va.getX() / d);
		vb.setZ(0);
	}
	else
	{// 给定坐标轴平行于z轴
		vb.setX(1.0f);
		vb.setY(0);
		vb.setZ(0);
	}

	vc = Vector3::cross(va, vb);


	vd.setX(-(va.getX() * point.getX() + va.getY() * point.getY() + va.getZ() * point.getZ()));
	vd.setY(-(vb.getX() * point.getX() + vb.getY() * point.getY() + vb.getZ() * point.getZ()));
	vd.setZ(-(vc.getX() * point.getX() + vc.getY() * point.getY() + vc.getZ() * point.getZ()));

	switch (eAxis)
	{
	case Axis3D::X:
	{
		//float ra[] = { va.getX(), va.getY(), va.getZ(), 0 };
		//float rb[] = { vb.getX(), vb.getY(), vb.getZ(), 0 };
		//float rc[] = { vc.getX(), vc.getY(), vc.getZ(), 0 };
		//float rd[] = { vd.getX(), vd.getY(), vd.getZ(), 1 };

		system.getMatrix().setRow(0, { va.getX(), va.getY(), va.getZ(), 0 });
		system.getMatrix().setRow(1, { vb.getX(), vb.getY(), vb.getZ(), 0 });
		system.getMatrix().setRow(2, { vc.getX(), vc.getY(), vc.getZ(), 0 });
		system.getMatrix().setRow(3, { vd.getX(), vd.getY(), vd.getZ(), 1 });
	}
		break;
	case Axis3D::Y:
	{
		//float ra[] = { va.getZ(), va.getX(), va.getY(), 0 };
		//float rb[] = { vb.getZ(), vb.getX(), vb.getY(), 0 };
		//float rc[] = { vc.getZ(), vc.getX(), vc.getY(), 0 };
		//float rd[] = { vd.getZ(), vd.getX(), vd.getY(), 1 };

		system.getMatrix().setRow(0, { va.getZ(), va.getX(), va.getY(), 0 });
		system.getMatrix().setRow(1, { vb.getZ(), vb.getX(), vb.getY(), 0 });
		system.getMatrix().setRow(2, { vc.getZ(), vc.getX(), vc.getY(), 0 });
		system.getMatrix().setRow(3, { vd.getZ(), vd.getX(), vd.getY(), 1 });

	}
		break;
	case Axis3D::Z:
	{
		//float ra[] = { va.getY(), va.getZ(), va.getX(), 0 };
		//float rb[] = { vb.getY(), vb.getZ(), vb.getX(), 0 };
		//float rc[] = { vc.getY(), vc.getZ(), vc.getX(), 0 };
		//float rd[] = { vd.getY(), vd.getZ(), vd.getX(), 1 };

		system.getMatrix().setRow(0, { va.getY(), va.getZ(), va.getX(), 0 });
		system.getMatrix().setRow(1, { vb.getY(), vb.getZ(), vb.getX(), 0 });
		system.getMatrix().setRow(2, { vc.getY(), vc.getZ(), vc.getX(), 0 });
		system.getMatrix().setRow(3, { vd.getY(), vd.getZ(), vd.getX(), 1 });
	}
		break;
	default:
		break;
	}


	return system;
}

math::CartesianCoordinateSystem3D math::CartesianCoordinateSystem3D::createWithTwoPoints(const Vector3& srcPoint, const Vector3& destPoint, Axis3D eAxis)
{
	math::CartesianCoordinateSystem3D system;
	if (srcPoint == destPoint)
	{// 0 向量
		return system;
	}

	Vector3 vector = destPoint - srcPoint;
	vector.normalize();

	return create(srcPoint, vector, eAxis);
}

math::CartesianCoordinateSystem3D math::CartesianCoordinateSystem3D::createAxonometric(const Vector3& ratio, const Vector2& angle)
{
	float radianX = ANGLE_TO_RADIAN(angle.getX());
	float radianY = ANGLE_TO_RADIAN(angle.getY());

	math::CartesianCoordinateSystem3D system;
	system.getMatrix().setValue(0, 0, ratio.getX() * sinf(radianX));
	system.getMatrix().setValue(0, 1, ratio.getX() * cosf(radianX));
	system.getMatrix().setValue(2, 0, -ratio.getZ() * sinf(radianY));
	system.getMatrix().setValue(2, 1, ratio.getZ() * cosf(radianY));
	system.getMatrix().setValue(1, 1, ratio.getY());

	return system;

}

math::CartesianCoordinateSystem3D math::CartesianCoordinateSystem3D::createAxonometric(Axonometric eType)
{
	Vector3 ratio;
	Vector2 angle;
	switch (eType)
	{
	case Axonometric::PositiveIsometric:
	{
		float v0 = sqrt(6.0f) / 3.0f;
		ratio.setX(v0);
		ratio.setY(v0);
		ratio.setZ(v0);

		angle.setX(120);
		angle.setY(120);
	}
		break;
	case Axonometric::PositiveTwoMeasurement:
	{
		float v0 = sqrt(2.0f) / 3.0f;
		ratio.setX(v0);
		ratio.setY(2 * v0);
		ratio.setZ(2 * v0);

		angle.setX(131.4166667f);
		angle.setY(97.16666667f);
	}
		break;
	case Axonometric::ObliqueTwoMeasurement:
	{
		ratio.setX(1.0f);
		ratio.setY(1.0f);
		ratio.setZ(0.5f);

		angle.setX(90.0f);
		angle.setY(135.0f);
	}
		break;
	default:
		break;
	}

	return createAxonometric(ratio, angle);
}
