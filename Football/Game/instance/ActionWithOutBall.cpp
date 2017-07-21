#include "ActionWithOutBall.h"

using namespace game;


ActionWithoutBall::ActionWithoutBall()
:m_bFinish(false)
, m_pPerson(nullptr)
{

}

ActionWithoutBall::~ActionWithoutBall()
{

}

IPerson* ActionWithoutBall::getInitiator()
{
	return m_pPerson;
}

void ActionWithoutBall::setInitiator(IPerson* pPerson)
{
	m_pPerson = pPerson;
}

bool ActionWithoutBall::run()
{
	return false;
}

void ActionWithoutBall::update(float dt)
{

}

bool ActionWithoutBall::isFinish()
{
	return m_bFinish;
}
