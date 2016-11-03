#include "ActionWithOutBall.h"

using namespace game;


ActionWithOutBall::ActionWithOutBall()
:m_bFinish(false)
, m_pPerson(nullptr)
{

}

ActionWithOutBall::~ActionWithOutBall()
{

}

IPerson* ActionWithOutBall::getInitiator()
{
	return m_pPerson;
}

void ActionWithOutBall::setInitiator(IPerson* pPerson)
{
	m_pPerson = pPerson;
}

bool ActionWithOutBall::run()
{
	return false;
}

void ActionWithOutBall::update(float dt)
{

}

bool ActionWithOutBall::isFinish()
{
	return m_bFinish;
}
