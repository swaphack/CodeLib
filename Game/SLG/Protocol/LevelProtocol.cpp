#include "LevelProtocol.h"

using namespace slg;


LevelProtocol::LevelProtocol()
:_level(0)
, _exp(0)
, _maxLevel(0)
, _maxExp(0)
{

}

LevelProtocol::~LevelProtocol()
{

}

void LevelProtocol::setLevel(int level)
{
	_level = level;
}

int LevelProtocol::getLevel()
{
	return _level;
}

void LevelProtocol::setMaxLevel(int maxLevel)
{
	_maxLevel = maxLevel;
}

int LevelProtocol::getMaxLevel()
{
	return _maxLevel;
}

void LevelProtocol::setExp(int exp)
{
	_exp = exp;
}

int LevelProtocol::getExp()
{
	return _exp;
}

void LevelProtocol::setMaxExp(int maxExp)
{
	_maxExp = maxExp;
}

int LevelProtocol::getMaxExp()
{
	return _maxExp;
}
