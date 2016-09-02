#include "World.h"

using namespace game;

static World* s_world = nullptr;


World::World()
{
	m_humanSheet = new HumanSheet();
	m_countrySheet = new CountrySheet();
	m_leagueSheet = new LeagueSheet();
	m_clubSheet = new ClubSheet();
	m_teamSheet = new TeamSheet();
	m_transferMarket = new TransferMarket();
}

World::~World()
{
	delete m_humanSheet;
	delete m_countrySheet;
	delete m_leagueSheet;
	delete m_clubSheet;
	delete m_teamSheet;
	delete m_transferMarket;
}

World* World::getInstance()
{
	if (s_world == nullptr)
	{
		s_world = new World();
	}

	return s_world;
}

const HumanSheet* World::getHumanSheet() const
{
	return m_humanSheet;
}

const CountrySheet* World::getCountrySheet() const
{
	return m_countrySheet;
}

const LeagueSheet* World::getLeagueSheet() const
{
	return m_leagueSheet;
}

const ClubSheet* World::getClubSheet() const
{
	return m_clubSheet;
}

const TeamSheet* World::getTeamSheet() const
{
	return m_teamSheet;
}

const TransferMarket* World::getTransferMarket() const
{
	return m_transferMarket;
}

void :World::update()
{

}
