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
	*	世界
	*/
	class IWorld
	{
	public:
		virtual ~IWorld() {}
	public:
		/**
		*	人类
		*/
		virtual const HumanSheet* getHumanSheet() const = 0;
		/**
		*	国家
		*/
		virtual const CountrySheet* getCountrySheet() const = 0;
		/**
		*	联赛
		*/
		virtual const LeagueSheet* getLeagueSheet() const = 0;
		/**
		*	俱乐部
		*/
		virtual const ClubSheet* getClubSheet() const = 0;
		/**
		*	队伍
		*/
		virtual const TeamSheet* getTeamSheet() const = 0;
		/**
		*	交易市场
		*/
		virtual const TransferMarket* getTransferMarket() const = 0;
	};
}