#pragma once

namespace render
{
	/**
	*	剪切测试
	*	限定显示区域
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

