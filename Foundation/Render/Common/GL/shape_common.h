#pragma once

#include "system.h"

// ��״
namespace render
{
	// ���ο򶥵㼯
	struct RectangeVertex
	{
		// ���½�
		sys::Vector3 leftDown;
		// ���½�
		sys::Vector3 rightDown;
		// ���Ͻ�
		sys::Vector3 rightUp;
		// ���Ͻ�
		sys::Vector3 leftUp;

		RectangeVertex();

		// �ж�
		bool containPoint(float x, float y);
		//  ��ȡ�����ڵ�ê��λ��
		sys::Vector3 getAnchorByPoint(float x, float y);
	};
}