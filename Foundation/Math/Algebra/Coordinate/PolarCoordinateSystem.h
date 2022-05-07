#pragma once

#include "CoordinateSystem.h"
#include "Algebra/Vector/Vector2.h"
#include "Number/Complex.h"
namespace math
{
	/**
	*	极坐标系
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
		*	获取二维坐标
		*/
		Vector2 getXYPoint(float radian);
		/**
		*	获取复数坐标
		*/
		Complex getComplex(float radian);
	protected:
	private:
		// 半径
		float _radius = 0;
	};
}