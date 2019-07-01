#pragma once

#include "../macros.h"

namespace game
{
	class Field : public Component
	{
	public:
		Field();
		virtual ~Field();
	public:
		CREATE_COMPONENT_TYPE();
		CREATE_COMPONENT_CLONE(Field);
		/**
		*	宽度
		*/
		CREATE_COMPONENT_PROPERTY(float, Width);
		/**
		*	高度
		*/
		CREATE_COMPONENT_PROPERTY(float,Height);
		/**
		* 是否包含
		*/
		bool contains(const Point& point);
	private:
		float m_width = 0;
		float m_height = 0;
	};
}