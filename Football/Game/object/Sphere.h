#pragma once

#include "Object.h"

namespace game
{
	/**
	*	����
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
		*	�뾶
		*/
		CREATE_COMPONENT_PROPERTY(float, Radius);
	private:
	};
}