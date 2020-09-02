#pragma once

#include "PrimitiveNode.h"

namespace render
{
	/**
	*	×ø±êÏµ
	*/
	class CoordinateSystem : public PrimitiveNode
	{
	public:
		CoordinateSystem();
		virtual ~CoordinateSystem();
	public:
		virtual bool init();
	public:
		void onCoordianteSystemBodyChange();
	protected:
	private:
	};
}
