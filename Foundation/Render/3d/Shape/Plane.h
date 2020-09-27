#pragma once

#include "3d/Common/Model.h"
#include "Common/struct/import.h"

namespace render
{
	/**
	*	ƽ�棬��������
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