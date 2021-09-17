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
		void setPoint(const Vector3& srcPoint);
		// 起始点
		const Vector3& getPoint() const;
		// 方向
		void setDirection(const Vector3& direction);
		// 方向
		const Vector3& getDirection() const;
		// 获取目标点，缩放后的方向向量与起始点的和
		Vector3 getDestPoint(float scaler = 1) const;
	private:
		// 起始点
		Vector3 _point;
		// 方向
		Vector3 _direction;
	};
}
