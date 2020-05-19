#pragma once
#include "FragmentHandle.h"
#include "mathlib.h"

namespace render
{
	/**
	*	剪切测试
	*	限定显示区域
	*/
	class FragmentScissorTest : public FragmentHandle
	{
	public:
		FragmentScissorTest();
		virtual ~FragmentScissorTest();
	public:
		void setRect(int x, int y, int width, int height);
	public:
		virtual void update();
	protected:
		virtual void saveData();
		virtual void reloadData();
	protected:
		math::Rect _rect;
		math::Rect _lastRect;
	};
}

