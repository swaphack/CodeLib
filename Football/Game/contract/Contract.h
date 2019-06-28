#pragma once

#include <cstdint>

namespace game
{
	class PropertySheet;

	/**
	*	��ͬ
	*/
	class Contract
	{
	public:
		Contract();
		virtual ~Contract();
	public:
		/**
		*	���ֲ�
		*/
		uint64_t getClubID();
		/**
		*	Ա��
		*/
		uint64_t getPersonID();
		/**
		*	Э������
		*/
		const PropertySheet* getAgreement();
	};
}