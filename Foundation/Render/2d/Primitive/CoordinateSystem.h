#pragma once

#include "PrimitiveNode.h"

namespace render
{
	/**
	*	����ϵ
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
