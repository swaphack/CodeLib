#include "LivingProtocol.h"

using namespace slg;


LivingProtocol::LivingProtocol()
:_birthday(0)
, _bDead(false)
{

}

LivingProtocol::~LivingProtocol()
{

}

time_t LivingProtocol::getBirthDay()
{
	return _birthday;
}

bool LivingProtocol::isDead()
{
	return _bDead;
}

void LivingProtocol::setDead(bool isDead)
{
	_bDead = isDead;
}

void LivingProtocol::setBirthDay(time_t tt)
{
	_birthday = tt;
}
