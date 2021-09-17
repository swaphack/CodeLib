#pragma once
#include "Algebra/Vector/Vector3.h"

namespace math
{
	// ����
	struct Ray
	{
	public:
		Ray(const Vector3& srcPoint, const Vector3& direction);
		~Ray();
	public:
		// ��ʼ��
		void setPoint(const Vector3& srcPoint);
		// ��ʼ��
		const Vector3& getPoint() const;
		// ����
		void setDirection(const Vector3& direction);
		// ����
		const Vector3& getDirection() const;
		// ��ȡĿ��㣬���ź�ķ�����������ʼ��ĺ�
		Vector3 getDestPoint(float scaler = 1) const;
	private:
		// ��ʼ��
		Vector3 _point;
		// ����
		Vector3 _direction;
	};
}
