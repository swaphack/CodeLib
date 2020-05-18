#pragma once
#include "FragmentHandle.h"
#include "mathlib.h"

namespace render
{
	/**
	*	���в���
	*	�޶���ʾ����
	*/
	class FragmentScissorTest : public FragmentHandle
	{
	public:
		FragmentScissorTest();
		virtual ~FragmentScissorTest();
	public:
		void setRect(int x, int y, int width, int height);
	public:
		virtual void begin();
		virtual void update();
		virtual void end();
	protected:
		math::Rect _rect;
	};
}

