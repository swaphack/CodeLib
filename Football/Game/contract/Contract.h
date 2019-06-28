#pragma once

#include <cstdint>

namespace game
{
	class PropertySheet;

	/**
	*	合同
	*/
	class Contract
	{
	public:
		Contract();
		virtual ~Contract();
	public:
		/**
		*	俱乐部
		*/
		uint64_t getClubID();
		/**
		*	员工
		*/
		uint64_t getPersonID();
		/**
		*	协定条件
		*/
		const PropertySheet* getAgreement();
	};
}