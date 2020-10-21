#pragma once

#include "system.h"
#include "mathlib.h"

// ��״
namespace render
{
	// ���ο򶥵㼯
	struct RectPoints
	{
	public:
		// ���½�
		math::Vector3 leftDown;
		// ���½�
		math::Vector3 rightDown;
		// ���Ͻ�
		math::Vector3 rightUp;
		// ���Ͻ�
		math::Vector3 leftUp;
	public:
		RectPoints();

		// ������ж�
		bool containPointByArea(float x, float y);
		// ����η��ж�
		bool containPointByPolygon(float x, float y);
		//  ��ȡ�����ڵ�ê��λ��
		math::Vector3 getAnchorByPoint(float x, float y);

	public: 
		float getX();
		float getY();

		float getWidth();
		float getHeight();
	protected:
		float getArea(const math::Vector3& p1, const math::Vector3& p2, const math::Vector3& p3);
	};

	// �����嶥�㼯
	struct CubePoints
	{
	public:
		// ǰ��
		RectPoints front;
		// ����
		RectPoints back;
		// ����
		RectPoints left;
		// ����
		RectPoints right;
		// ����
		RectPoints top;
		// �ײ�
		RectPoints bottom;
	public:
		CubePoints()
		{ }

	public:
		void setFrontLeftDownPosition(const math::Vector3& point);
		void setFrontRightDownPosition(const math::Vector3& point);
		void setFrontRightUpPosition(const math::Vector3& point);
		void setFrontLeftUpPosition(const math::Vector3& point);

		void setBackLeftDownPosition(const math::Vector3& point);
		void setBackRightDownPosition(const math::Vector3& point);
		void setBackRightUpPosition(const math::Vector3& point);
		void setBackLeftUpPosition(const math::Vector3& point);
	public:
		// ����η��ж�
		bool containPointByPolygon(float x, float y);
	};
}