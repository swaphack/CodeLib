#pragma once

#include "macros.h"

namespace game
{ 
	/**
	*	Çò
	*/
	class Ball : public Sphere
	{
	public:
		Ball();
		virtual ~Ball();
	public:
		CREATE_COMPONENT_TYPE();
		CREATE_COMPONENT_CLONE(Ball);
	public:

	protected:
	private:
	};
}