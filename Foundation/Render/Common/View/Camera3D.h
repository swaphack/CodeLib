#pragma once

#include "Camera.h"

namespace render
{
	/**
	*	3D�����
	*/
	class Camera3D : public Camera
	{
	public:
		Camera3D();
		virtual ~Camera3D();
	public:
	protected:
		virtual void updateView();
		virtual void updateViewPort();

	};
}