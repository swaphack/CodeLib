#pragma once

#include "../base/Component.h"
#include "../struct/Vector.h"

namespace game
{
	/**
	*	����
	*	�Խŵ�Ϊ����
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
		CREATE_COMPONENT_PROPERTY(Vector, Position);
		/**
		*	����
		*/
		CREATE_COMPONENT_PROPERTY(Vector, Scale);
		/**
		*	���
		*/
		CREATE_COMPONENT_PROPERTY(Vector, Volume);
	};
}