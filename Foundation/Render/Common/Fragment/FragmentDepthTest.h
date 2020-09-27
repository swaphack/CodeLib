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
		virtual void update();
	public:
		virtual void saveData();
		virtual void reloadData();
	protected:
		DepthFunction _func = DepthFunction::LESS;
		DepthFunction _lastFunc = DepthFunction::LEQUAL;
	};
}
