#pragma once

#include "Graphic/GLAPI/macros.h"
#include "FragmentTestOp.h"

namespace render
{
	/**
	*	…Ó∂»≤‚ ‘
	*/
	class FragmentDepthTest : public FragmentTestOp
	{
	public:
		FragmentDepthTest();
		virtual ~FragmentDepthTest();
	public:
		void setFunc(DepthFunction func);
	public:
		virtual void start();
		virtual void update();
		virtual void end();
	protected:
		DepthFunction _func;
	};
}
