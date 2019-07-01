#pragma once

#include "../base/Component.h"
#include "../struct/Vector.h"

namespace game
{
	/**
	*	物体
	*	以脚底为中心
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
		CREATE_COMPONENT_PROPERTY(Vector, Position);
		/**
		*	缩放
		*/
		CREATE_COMPONENT_PROPERTY(Vector, Scale);
		/**
		*	体积
		*/
		CREATE_COMPONENT_PROPERTY(Vector, Volume);
	};
}