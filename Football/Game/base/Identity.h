#pragma once

#include <string>
#include <cstdint>

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
		uint64_t getID();
		/**
		*	…Ë÷√±‡∫≈
		*/
		void setID(uint64_t nID);
	private:
		uint64_t _id = 0;
	};
}