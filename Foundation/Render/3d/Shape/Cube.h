#pragma once

#include "3d/Common/Model.h"
#include "Common/struct/import.h"

namespace render
{
	class Texture2D;
	/**
	*	Α’·½Με
	*/
	class Cube : public Model
	{
	public:
		Cube();
		virtual ~Cube();
	public:
		virtual bool init();
	protected:
		virtual void updateDrawNode3DMesh();
	};
}