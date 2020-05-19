#pragma once

#include "Graphic/GLAPI/macros.h"
#include "FragmentHandle.h"

namespace render
{
	enum class PolygonOffsetType
	{
		POLYGON_OFFSET_FILL= GL_POLYGON_OFFSET_FILL,
		POLYGON_OFFSET_LINE= GL_POLYGON_OFFSET_LINE,
		POLYGON_OFFSET_POINT=GL_POLYGON_OFFSET_POINT,
	};
	/**
	*	¶à±ßÐÎ²Ù×÷
	*/
	class FragmentPolygonOffset : public FragmentHandle
	{
	public:
		FragmentPolygonOffset();
		virtual ~FragmentPolygonOffset();
	public:
		void setOffsetType(PolygonOffsetType type);
		// offset = m * factor + r * units;
		void setOffset(float factor, float units);
	public:
		virtual void update();
	protected:
		sys::Tuple2<float, float> _offset;
	};
}