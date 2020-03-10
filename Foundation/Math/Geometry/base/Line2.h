#pragma once

#include "Algebra/import.h"
#include "macros.h"

namespace math
{
	/**
	*	ֱ�߷���
	*	Ax + By + C = 0;
	*/
	struct Line2
	{
	public:
		/**
		*	����
		*/
		Line2(float a, float b, float c);
		/**
		*	����ȷ��һ��ֱ��
		*/
		Line2(const Vector2& src, const Vector2& dest);
		Line2(const Line2& line);
	public:
		float getParamA() const;
		float getParamB() const;
		float getParamC() const;
		/**
		*	������
		*/
		const Vector2& getNormal() const;
		/**
		*	��������
		*/
		const Vector2& getDirection() const;
	public:
		/**
		*	�㵽ֱ�ߵľ���
		*/
		float getDistanceWithPoint(const Vector2& point);
		/**
		*	������
		*/
		bool contains(const Vector2& point);
		/**
		*	�Ƿ�ƽ��
		*/
		bool isParallel(const Line2& line);
		/**
		*	�Ƿ��ཻ
		*/
		bool isIntersect(const Line2& line);
		/**
		*	����ֱ�ߵ�λ�ù�ϵ
		*/
		PointAndLinePositionType getPointPositionType(const Vector2& point);
	protected:
		float _paramA = 0;
		float _paramB = 0;
		float _paramC = 0;
		/**
		*	������
		*/
		Vector2 _normal;
		/**
		*	��������
		*/
		Vector2 _direction;
	};

}