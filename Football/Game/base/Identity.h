#pragma once

#include <string>
#include <cstdint>

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
		uint64_t getID();
		/**
		*	���ñ��
		*/
		void setID(uint64_t nID);
	private:
		uint64_t _id = 0;
	};
}