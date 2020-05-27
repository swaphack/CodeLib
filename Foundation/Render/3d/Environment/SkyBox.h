#pragma once

#include "3d/Shape/Cube.h"

namespace render
{
	class TextureCubeMap;
	/**
	*	Ìì¿ÕºÐ
	*/
	class SkyBox : public Cube
	{
	public:
		SkyBox();
		virtual ~SkyBox();
	public:
		virtual bool init();
	public:
		
	};
}