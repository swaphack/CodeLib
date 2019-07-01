#pragma once

#include "../base/Component.h"

namespace game
{
	/**
	*	账单
	*/
	class Bill : public Component
	{
	public:
		Bill();
		virtual ~Bill();
	public:
		/**
		*	添加项
		*/
		void addItem(int nType, int money);
		/**
		*	结余
		*/
		int getBlance() const;
	};
}