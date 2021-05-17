#pragma once
#include "Algebra/Vector/Vector3.h"

namespace math
{
	// 射线
	struct Ray
	{
	public:
		Ray(const Vector3& srcPoint, const Vector3& direction);
		~Ray();
	public:
		// 起始点
		void setSrcPoint(const Vector3& srcPoint);
		// 起始点
		const Vector3& getSrcPoint() const;
		// 方向
		void setDirection(const Vector3& direction);
		// 方向
		const Vector3& getDirection() const;
	private:
		// 起始点
		Vector3 _srcPoint;
		// 方向
		Vector3 _direction;
	};
}
