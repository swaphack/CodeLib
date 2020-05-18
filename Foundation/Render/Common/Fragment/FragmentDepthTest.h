#pragma once

#include "Graphic/GLAPI/macros.h"
#include "FragmentHandle.h"

namespace render
{
	/**
	*	…Ó∂»≤‚ ‘
	*/
	class FragmentDepthTest : public FragmentHandle
	{
	public:
		FragmentDepthTest();
		virtual ~FragmentDepthTest();
	public:
		void setFunc(DepthFunction func);
	public:
		virtual void begin();
		virtual void update();
		virtual void end();
	protected:
		DepthFunction _func;
	};
}
