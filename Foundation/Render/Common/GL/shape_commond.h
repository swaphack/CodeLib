#pragma once

#include "system.h"

// ��״
namespace render
{
	// ���ο򶥵㼯
	struct RectangeVertex
	{
		// ���½�
		sys::Vector leftDown;
		// ���½�
		sys::Vector rightDown;
		// ���Ͻ�
		sys::Vector rightUp;
		// ���Ͻ�
		sys::Vector leftUp;

		RectangeVertex()
		{

		}
	};
}