#include "ActionWithBall.h"

using namespace game;


ActionWithBall::ActionWithBall()
:m_bFinish(false)
, m_pBall(nullptr)
, m_pPerson(nullptr)
{

}

ActionWithBall::~ActionWithBall()
{

}

Ball* ActionWithBall::getBall()
{
	return m_pBall;
}

void ActionWithBall::setBall(Ball* pBall)
{
	m_pBall = pBall;
}

Player* ActionWithBall::getInitiator()
{
	return m_pPerson;
}

void ActionWithBall::setInitiator(Player* pPerson)
{
	m_pPerson = pPerson;
}

bool ActionWithBall::run()
{
	return false;
}

void ActionWithBall::update(float dt)
{

}

bool ActionWithBall::isFinish()
{
	return m_bFinish;
}

//////////////////////////////////////////////////////////////////////////