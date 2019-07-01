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
		*	���
		*/
		CREATE_COMPONENT_PROPERTY(float, Width);
		/**
		*	�߶�
		*/
		CREATE_COMPONENT_PROPERTY(float,Height);
		/**
		* �Ƿ����
		*/
		bool contains(const Point& point);
	private:
		float m_width = 0;
		float m_height = 0;
	};
}