#pragma once

#include "Camera.h"

namespace render
{
	/**
	*	2DÉãÏñ»ú
	*/
	class Camera2D : public Camera
	{
	public:
		Camera2D();
		virtual ~Camera2D();
	public:
	protected:
		virtual void updateView();
		virtual void updateViewPort();
	};
}