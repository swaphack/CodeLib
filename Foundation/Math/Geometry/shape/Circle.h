#pragma once

#include "Algebra/import.h"

namespace math
{
	/**
	*	Բ
	*/
	struct Circle
	{
	public:
		Circle();
		Circle(const Vector3& position, float radius);
		Circle(const Circle& circle);
		virtual ~Circle();
	public:
		/**
		*	λ��
		*/
		const Vector3& getPosition() const;
		/**
		*	�뾶
		*/
		float getRadius() const;
	public:
		/**
		*	�Ƿ������
		*/
		bool contains(const Vector3& point) const;
	private:
		/**
		*	ԭ������
		*/
		Vector3 _position;
		/**
		*	�뾶
		*/
		float _radius = 0;
	};
}