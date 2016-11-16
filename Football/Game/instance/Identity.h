#pragma once

#include <string>

namespace game
{
	/**
	*	±‡∫≈
	*/
	class Identity
	{
	public:
		Identity();
		virtual ~Identity();
	public:
		/**
		*	ªÒ»°±‡∫≈
		*/
		int getID();
		/**
		*	…Ë÷√±‡∫≈
		*/
		void setID(int nID);
	private:
		int	_id;
	};
}