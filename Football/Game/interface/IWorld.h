#pragma once

#include "ISet.h"

namespace game
{
	class Person;
	class Country;
	class Club;
	class Team;
	class League;
	class TransferMarket;

	typedef ISet<Person> HumanSheet;
	typedef ISet<Country> CountrySheet;
	typedef ISet<Club> ClubSheet;
	typedef ISet<Team> TeamSheet;
	typedef ISet<League> LeagueSheet;

	/**
	*	����
	*/
	class IWorld
	{
	public:
		virtual ~IWorld() {}
	public:
		/**
		*	����
		*/
		virtual const HumanSheet* getHumanSheet() const = 0;
		/**
		*	����
		*/
		virtual const CountrySheet* getCountrySheet() const = 0;
		/**
		*	����
		*/
		virtual const LeagueSheet* getLeagueSheet() const = 0;
		/**
		*	���ֲ�
		*/
		virtual const ClubSheet* getClubSheet() const = 0;
		/**
		*	����
		*/
		virtual const TeamSheet* getTeamSheet() const = 0;
		/**
		*	�����г�
		*/
		virtual const TransferMarket* getTransferMarket() const = 0;
	};
}