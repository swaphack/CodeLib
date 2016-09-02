#pragma once

#include "../interface/IWorld.h"

namespace game
{
	class World : public IWorld
	{
	private:
		World();
	public:
		virtual ~World();
	public:
		static World* getInstance();

		virtual const HumanSheet* getHumanSheet() const;

		virtual const CountrySheet* getCountrySheet() const;

		virtual const LeagueSheet* getLeagueSheet() const;

		virtual const ClubSheet* getClubSheet() const;

		virtual const TeamSheet* getTeamSheet() const;

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