#include "CartesianCoordinateSystem3D.h"
#include "Basic/base.h"
#include "Algebra/Vector/Vector2.h"
#include "Algebra/Vector/Vector3.h"
#include "Algebra/Polynomial/CubicPolynomial.h"
#include "Algebra/Determinant/Determinant.h"

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

math::CartesianCoordinateSystem3D math::CartesianCoordinateSystem3D::createWithPoints(const std::vector<Vector3>& points)
{
	int count = points.size();
	math::CartesianCoordinateSystem3D ccs;

	math::Vector3 m;
	for (int i = 0; i < count; i++)
	{
		m += points[i];
	}
	m /= count;

	float a, b, c, d, e, f;
	a = b = c = d = e = f = 0.0f;
	for (int i = 0; i < count; i++)
	{
		a += powf(points[i].getX() - m.getX(), 2);
		b += powf(points[i].getY() - m.getY(), 2);
		c += powf(points[i].getZ() - m.getZ(), 2);

		d += (points[i].getX() - m.getX()) * (points[i].getY() - m.getY());
		e += (points[i].getX() - m.getX()) * (points[i].getZ() - m.getZ());
		f += (points[i].getY() - m.getY()) * (points[i].getZ() - m.getZ());
	}

	a /= count; b /= count; c /= count; d /= count; e /= count; f /= count;

	float da = -1;
	float db = (a + b + c);
	float dc = f * f + d * d + e * e -(a * b + a * c + b * c);
	float dd = a * b * c + 2 * d * e * f - (a * f * f + b * e * e + c * d * d);

	CubicPolynomial cubicPoly(da, db, dc, dd);
	std::vector<Complex> result = cubicPoly.getEquationSolution();
	if (result.size() != 3)
	{
		return ccs;
	}

	for (int i = 0; i < 3; i++)
	{
		if (result[i].getImz() != 0)
		{
			return ccs;
		}
	}

	float l1 = result[0].getRez();
	float l2 = result[1].getRez();
	float l3 = result[2].getRez();

	math::Determinant3 m1(math::Array2D<float, 3, 3>(
		a - l1,	d,		e,
		d,		b-l1,	f,
		e,		f,		c-l1));

	math::Determinant3 m2(math::Array2D<float, 3, 3>(
		a - l2,	d,		e,
		d,		b - l2, f,
		e,		f,		c - l2));

	math::Determinant3 m3(math::Array2D<float, 3, 3>(
		a - l3,	d,		e,
		d,		b - l3, f,
		e,		f,		c - l3));

	Array<float, 3> v(0, 0, 0);
	Vector3 o1 = m1.getSolution(v);
	Vector3 o2 = m2.getSolution(v);
	Vector3 o3 = m3.getSolution(v);

	o1.normalize(); o2.normalize(); o3.normalize();

	Array<float, 4> v1(o1);
	Array<float, 4> v2(o2);
	Array<float, 4> v3(o3);

	ccs.setColumn(0, v1);
	ccs.setColumn(1, v2);
	ccs.setColumn(2, v3);

	return ccs;
}
