#pragma once

#include <string>

namespace game
{
	/**
	*	���
	*/
	class Identity
	{
	public:
		Identity();
		virtual ~Identity();
	public:
		/**
		*	��ȡ���
		*/
		int getID();
		/**
		*	���ñ��
		*/
		void setID(int nID);
	private:
		int	_id;
	};
}