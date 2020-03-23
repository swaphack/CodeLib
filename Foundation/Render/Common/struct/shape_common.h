#pragma once

#include "system.h"
#include "mathlib.h"

// ��״
namespace render
{
	// ���ο򶥵㼯
	struct RectVertex
	{
		// ���½�
		math::Vector3 leftDown;
		// ���½�
		math::Vector3 rightDown;
		// ���Ͻ�
		math::Vector3 rightUp;
		// ���Ͻ�
		math::Vector3 leftUp;

		RectVertex();

		// �ж�
		bool containPoint(float x, float y);
		//  ��ȡ�����ڵ�ê��λ��
		math::Vector3 getAnchorByPoint(float x, float y);
	};

	// �����嶥�㼯
	struct CubeVertex
	{
		// ǰ��
		RectVertex front;
		// ����
		RectVertex back;
		// ����
		RectVertex left;
		// ����
		RectVertex right;
		// ����
		RectVertex top;
		// �ײ�
		RectVertex bottom;

		CubeVertex()
		{ }
	};
}