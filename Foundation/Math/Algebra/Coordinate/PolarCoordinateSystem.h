#pragma once

#include "CoordinateSystem.h"
#include "Algebra/Vector/Vector2.h"
#include "Number/Complex.h"
namespace math
{
	/**
	*	������ϵ
	*/
	class PolarCoordinateSystem 
	{
	public:
		PolarCoordinateSystem();
		PolarCoordinateSystem(float radius);
		virtual ~PolarCoordinateSystem();
	public:
		void setRadius(float value);
		float getRadius() const;
		/**
		*	��ȡ��ά����
		*/
		Vector2 getXYPoint(float radian);
		/**
		*	��ȡ��������
		*/
		Complex getComplex(float radian);
	protected:
	private:
		// �뾶
		float _radius = 0;
	};
}