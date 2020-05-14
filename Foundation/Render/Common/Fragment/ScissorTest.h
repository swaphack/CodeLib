#pragma once
#include "FragmentTestOp.h"
#include "mathlib.h"

namespace render
{
	/**
	*	���в���
	*	�޶���ʾ����
	*/
	class ScissorTest : public FragmentTestOp
	{
	public:
		ScissorTest();
		virtual ~ScissorTest();
	public:
		void setRect(int x, int y, int width, int height);
	public:
		virtual void startTest();
		virtual void test();
		virtual void endTest();
	protected:
		math::Rect _rect;
	};
}

