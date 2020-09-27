#pragma once

#include "3d/Common/Model.h"
#include "Common/struct/import.h"

namespace render
{
	/**
	*	平面，单面纹理
	*/
	class Plane : public Model
	{
	public:
		Plane();
		virtual ~Plane();
	public:
		virtual bool init();
	protected:
		void onPlaneBodyChanged();
	private:
		RectVertex _rectVertex;
	};
}