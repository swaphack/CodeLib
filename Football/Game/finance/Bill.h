#pragma once

#include "../base/Component.h"

namespace game
{
	/**
	*	�˵�
	*/
	class Bill : public Component
	{
	public:
		Bill();
		virtual ~Bill();
	public:
		/**
		*	�����
		*/
		void addItem(int nType, int money);
		/**
		*	����
		*/
		int getBlance() const;
	};
}