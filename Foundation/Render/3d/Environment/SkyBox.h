#pragma once

#include "3d/Shape/Cube.h"

namespace render
{
	class TextureCubeMap;
	/**
	*	��պ�
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