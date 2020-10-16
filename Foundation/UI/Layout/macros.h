#pragma once

#include "system.h"

namespace ui
{
	/**
	*	���ַ���
	*/
	enum class LayoutDirection
	{
		// ��
		NONE,
		// ��ֱ����
		HORIZONTAL,
		// ˮƽ����
		ERTICAL,
	};

	/**
	*	����״̬
	*/
	struct MarginState
	{
		bool Top = false;
		bool Right = false;
		bool Bottom = false;
		bool Left = false;

		MarginState() {}

		MarginState(bool top, bool right, bool bottom, bool left)
			:Top(top), Right(right), Bottom(bottom), Left(left)
		{

		}
	};
}