#pragma once

#include "PrimitiveNode.h"

namespace render
{
	/**
	*	坐标系
	*/
	class CoordinateSystem : public PrimitiveNode
	{
	public:
		CoordinateSystem();
		virtual ~CoordinateSystem();
	public:
		virtual bool init();
	public:
		/**
		*	大小改变
		*/
		virtual void onDrawNode2DBodyChange();
		/**
		*	颜色改变
		*/
		virtual void onDrawNode2DColorChange();
	protected:
	private:
	};
}
