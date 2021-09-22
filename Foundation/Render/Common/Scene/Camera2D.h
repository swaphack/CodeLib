#pragma once

#include "Camera.h"

namespace render
{
	/**
	*	2D�����
	*/
	class Camera2D : public Camera
	{
	public:
		Camera2D();
		virtual ~Camera2D();
	public:
		virtual bool init();
	protected:
		virtual void updateViewPort();
	};
}