#pragma once

#include "system.h"
#include "mathlib.h"

// ��״
namespace render
{
	// ���ο򶥵㼯
	struct RectVectices
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
		RectVectices();

		// ������ж�
		bool containPointByArea(float x, float y);
		// ����η��ж�
		bool containPointByPolygon(float x, float y);
		//  ��ȡ�����ڵ�ê��λ��
		math::Vector3 getAnchorByPoint(float x, float y);
	protected:
		double getArea(const math::Vector3& p1, const math::Vector3& p2, const math::Vector3& p3);
	};

	// �����嶥�㼯
	struct CubeVectices
	{
	public:
		// ǰ��
		RectVectices front;
		// ����
		RectVectices back;
		// ����
		RectVectices left;
		// ����
		RectVectices right;
		// ����
		RectVectices top;
		// �ײ�
		RectVectices bottom;

		CubeVectices()
		{ }
	};
}