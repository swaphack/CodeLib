#pragma once

namespace game
{
	/**
	*	�˵�
	*/
	class Bill
	{
	public:
		virtual ~Bill();
	public:
		/**
		*	�����
		*/
		virtual void addItem(int nType, int money);
		/**
		*	����
		*/
		virtual int getBlance() const;
	};
}