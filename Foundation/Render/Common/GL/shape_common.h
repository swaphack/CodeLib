#pragma once

#include "system.h"

// ��״
namespace render
{
	// ���ο򶥵㼯
	struct RectVertex
	{
		// ���½�
		sys::Vector3 leftDown;
		// ���½�
		sys::Vector3 rightDown;
		// ���Ͻ�
		sys::Vector3 rightUp;
		// ���Ͻ�
		sys::Vector3 leftUp;

		RectVertex();

		// �ж�
		bool containPoint(float x, float y);
		//  ��ȡ�����ڵ�ê��λ��
		sys::Vector3 getAnchorByPoint(float x, float y);
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