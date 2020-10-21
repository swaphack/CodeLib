#pragma once

#include "Algebra/import.h"

#include <cstdint>

namespace math
{
	/**
	*	��Χ��
	*/
	struct BoundingBox
	{
	public:
		BoundingBox();
		BoundingBox(const Vector3& center);
		virtual ~BoundingBox();
	public:
		/**
		*	���ĵ�
		*/
		void setCenter(const Vector3& center);
		/**
		*	���ĵ�
		*/
		const Vector3& getCenter() const;
	public:
		/**
		*	�Ƿ������
		*/
		virtual bool contains(const Vector2& point);
		/**
		*	�Ƿ������
		*/
		virtual bool contains(const Vector3& point);
	protected:
		// ���ĵ�
		Vector3 _center;
	};
}