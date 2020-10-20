#pragma once

#include "TrackAction.h"

namespace render
{
	/**
	*	�����˶�
	*/
	class CurveAction : public TrackAction
	{
	public:
		CurveAction();
		virtual ~CurveAction();
	};

	/**
	*	����������
	*/
	class BezierAction2 : public CurveAction
	{
	public:
		BezierAction2();
		virtual ~BezierAction2();
	public:
		static BezierAction2* create(const math::Vector3& p0, const math::Vector3& p1);

		void setControlParameters(const math::Vector3& p0, const math::Vector3& p1);
	protected:
		// ��ȡλ��
		virtual math::Vector3 getPosition(float percent);
	private:
		math::Vector3 _controlPoint0;
		math::Vector3 _controlPoint1;
	};

	/**
	*	����������
	*/
	class BezierAction3 : public CurveAction
	{
	public:
		BezierAction3();
		virtual ~BezierAction3();
	public:
		static BezierAction3* create(const math::Vector3& p0, const math::Vector3& p1, const math::Vector3& p2);

		void setControlParameters(const math::Vector3& p0, const math::Vector3& p1, const math::Vector3& p2);
	protected:
		// ��ȡλ��
		virtual math::Vector3 getPosition(float percent);
	private:
		math::Vector3 _controlPoint0;
		math::Vector3 _controlPoint1;
		math::Vector3 _controlPoint2;
	};

	/**
	*	Բ�˶�
	*/
	class CircleAction : public CurveAction
	{
	public:
		CircleAction();
		virtual ~CircleAction();
	public:
		static CircleAction* create(const math::Vector3& centerPos, float circleRadius, const math::Vector3& eularAngle);

		void setControlParameters(const math::Vector3& centerPos, float circleRadius, const math::Vector3& eularAngle);
	protected:
		// ��ȡλ��
		virtual math::Vector3 getPosition(float percent);
	private:
		math::Vector3 _centerPoint;
		float _cicleRadius = 1;
		math::Vector3 _eularRadian;
	};

	/**
	*	��Բ�˶�
	*/
	class EllipseAction : public CurveAction
	{
	public:
		EllipseAction();
		virtual ~EllipseAction();
	public:
		static EllipseAction* create(const math::Vector3& centerPos, float radiusX, float radiusY, const math::Vector3& eularAngle);

		void setControlParameters(const math::Vector3& centerPos, float radiusX, float radiusY, const math::Vector3& eularAngle);
	protected:
		// ��ȡλ��
		virtual math::Vector3 getPosition(float percent);
	private:
		math::Vector3 _centerPoint;
		float _radiusX = 1;
		float _radiusY = 1;
		math::Vector3 _eularRadian;
	};
}