#pragma once

#include "../interface/IWorld.h"
#include "../interface/ISystem.h"

namespace game
{
	/**
	*	世界
	*/
	class World : public  IWorld
	{
	private:
		World();
	public:
		virtual ~World();
	public:
		static World* getInstance();
		/**
		*	人类
		*/
		virtual const HumanSheet* getHumanSheet() const;
		/**
		*	国家
		*/
		virtual const CountrySheet* getCountrySheet() const;
		/**
		*	联赛
		*/
		virtual const LeagueSheet* getLeagueSheet() const;
		/**
		*	俱乐部
		*/
		virtual const ClubSheet* getClubSheet() const;
		/**
		*	队伍
		*/
		virtual const TeamSheet* getTeamSheet() const;
		/**
		*	交易市场
		*/
		virtual const TransferMarket* getTransferMarket() const;

		virtual void update();
	private:
		HumanSheet* m_humanSheet;
		CountrySheet* m_countrySheet;
		LeagueSheet* m_leagueSheet;
		ClubSheet* m_clubSheet;
		TeamSheet* m_teamSheet;
		TransferMarket* m_transferMarket;
	};
}