#pragma once

#include "../base/Identity.h"
#include "../base/Component.h"

namespace game
{
	/**
	*	����
	*/
	class Country : public Component
	{
	public:
		virtual ~Country() {}
	public:
		/**
		*	����
		*/
		CREATE_COMPONENT_PROPERTY(std::string, Name);
		/**
		*	��������
		*/
		League* generateLeague() const;
		/**
		*	�Ƴ�����
		*/
		bool purgeLeague(League* pLeague) const;
		/**
		*	��������
		*/
		League* findLeague(uint64_t nLeagueID) const;
		/**
		*	���ɾ��ֲ�
		*/
		Club* generateClub() const;
		/**
		*	�Ƴ����ֲ�
		*/
		bool purgeClub(Club* pClub) const;
		/**
		*	���Ҿ��ֲ�
		*/
		Club* findClub(uint64_t nClubID) const;
	};
}