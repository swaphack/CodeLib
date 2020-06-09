#pragma once

#include "3d/Shape/CubeMap.h"

namespace render
{
	class TextureCubeMap;
	/**
	*	Ìì¿ÕºÐ
	*/
	class SkyBox : public CubeMap
	{
	public:
		SkyBox();
		virtual ~SkyBox();
	public:
	protected:
		virtual void beforeDrawNode();
		virtual void afterDrawNode();
	protected:
		virtual void onCubeChanged();
	};
}