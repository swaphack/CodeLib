#pragma once

#include "../base/Component.h"
#include "../struct/Vector.h"

namespace game
{
	/**
	*	物体
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
		*	位置
		*/
		CREATE_COMPONENT_PROPERTY_CLASS(Vector, Position);
		/**
		*	缩放
		*/
		CREATE_COMPONENT_PROPERTY_CLASS(Vector, Scale);
		/**
		*	体积
		*/
		CREATE_COMPONENT_PROPERTY_CLASS(Vector, Volume);
	};
}