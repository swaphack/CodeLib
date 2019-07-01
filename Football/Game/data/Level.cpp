#include "Level.h"

using namespace game;

Level::Level()
{

}

Level::~Level()
{

}

bool Level::canUpgrade()
{
	return getExperience() >= getLevelExperience();
}

uint64_t Level::getRemainUpgradeExp()
{
	return getLevelExperience() - getExperience();
}

bool Level::upgrade()
{
	if (!canUpgrade())
	{
		return false;
	}

	return true;
}

bool Level::addExperience(uint64_t value)
{
	uint64_t exp = getExperience() + value;
	
	setExperience(exp);

	return true;
}
