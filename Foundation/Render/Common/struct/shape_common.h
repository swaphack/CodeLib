#pragma once

#include "system.h"
#include "mathlib.h"

// ��״
namespace render
{
	// ���ο򶥵㼯
	struct RectVectices
	{
		// ���½�
		math::Vector3 leftDown;
		// ���½�
		math::Vector3 rightDown;
		// ���Ͻ�
		math::Vector3 rightUp;
		// ���Ͻ�
		math::Vector3 leftUp;

		RectVectices();

		// �ж�
		bool containPoint(float x, float y);
		//  ��ȡ�����ڵ�ê��λ��
		math::Vector3 getAnchorByPoint(float x, float y);
	};

	// �����嶥�㼯
	struct CubeVectices
	{
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