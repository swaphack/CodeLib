#pragma once

namespace render
{
	/**
	*	���в���
	*	�޶���ʾ����
	*/
	class ScissorTest
	{
	public:
		static void enable();
		static void disable();
		static bool isEnabled();
		static void setBox(int x, int y, int width, int height);
	};
}

