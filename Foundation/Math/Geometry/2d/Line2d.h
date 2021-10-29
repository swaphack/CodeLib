#pragma once

#include "Algebra/import.h"
#include "LineSegment2d.h"

namespace math
{
	/**
	*	����ֱ�ߵ�λ�ù�ϵ
	*/
	enum class PointAndLinePosition2DType
	{
		NONE,
		// ����
		INCLUDE,
		// �����
		EXLUDE_LEFT,
		// ���ұ�
		EXLUDE_RIGHT,

	};

	/**
	*	ֱ�߷���
	*	Ax + By + C = 0;
	*/
	struct Line2d
	{
	public:
		/**
		*	����
		*/
		Line2d(float a, float b, float c);
		/**
		*	����ȷ��һ��ֱ��
		*/
		Line2d(const Vector2& src, const Vector2& dest);
		Line2d(const Line2d& line);
		Line2d(const LineSegment2d& lineSeg);
	public:
		void set(float a, float b, float c);
		void set(const Vector2& src, const Vector2& dest);
		void set(const Line2d& line);
		void set(const LineSegment2d& lineSeg);
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
		bool contains(const Vector2& point) const;
		/**
		*	�Ƿ�ƽ��
		*/
		bool isParallel(const Line2d& line) const;
		/**
		*	�Ƿ��ཻ
		*/
		bool isIntersect(const Line2d& line) const;
		/**
		*	����ֱ�ߵ�λ�ù�ϵ
		*/
		PointAndLinePosition2DType getPointPositionType(const Vector2& point) const;
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