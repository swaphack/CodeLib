#pragma once

#include "Graphic/GLAPI/macros.h"
#include "FragmentTestOp.h"

namespace render
{
	/**
	*	…Ó∂»≤‚ ‘
	*/
	class DepthTest : public FragmentTestOp
	{
	public:
		DepthTest();
		virtual ~DepthTest();
	public:
		void setFunc(DepthFunction func);
	public:
		virtual void startTest();
		virtual void test();
		virtual void endTest();
	protected:
		DepthFunction _func;
	};
}
