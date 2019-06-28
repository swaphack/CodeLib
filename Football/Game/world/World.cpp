#include "World.h"

using namespace game;

static World* s_world = nullptr;


World::World()
{
	m_humanSheet = new HumanSheet();
	m_countrySheet = new CountrySheet();
}

World::~World()
{
	delete m_humanSheet;
	delete m_countrySheet;
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

void World::update()
{

}
