#pragma once

#include "Object.h"

namespace game
{
	/**
	*	ÇòÌå
	*/
	class Sphere : public Object
	{
	public:
		Sphere();
		virtual ~Sphere();
	public:
		CREATE_COMPONENT_TYPE();
		CREATE_COMPONENT_CLONE(Sphere);
	public:
		/**
		*	°ë¾¶
		*/
		CREATE_COMPONENT_PROPERTY(float, Radius);
	private:
	};
}