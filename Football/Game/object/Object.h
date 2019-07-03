#pragma once

#include "../base/Component.h"
#include "../struct/Vector.h"

namespace game
{
	/**
	*	����
	*/
	class Object : public Component
	{
	public:
		Object();
		virtual ~Object();
	public:
		CREATE_COMPONENT_TYPE();
		CREATE_COMPONENT_CLONE(Object);
	public:
		/**
		*	λ��
		*/
		CREATE_COMPONENT_PROPERTY_CLASS(Vector, Position);
		/**
		*	����
		*/
		CREATE_COMPONENT_PROPERTY_CLASS(Vector, Scale);
		/**
		*	���
		*/
		CREATE_COMPONENT_PROPERTY_CLASS(Vector, Volume);
	};
}