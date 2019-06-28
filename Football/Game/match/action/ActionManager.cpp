#include "ActionManager.h"

#include "ActionWithBall.h"
#include "ActionWithOutBall.h"

using namespace game;

ActionManager::ActionManager()
{

}

ActionManager::~ActionManager()
{
	this->removeAllActions();
}

void ActionManager::addAction(ITimer* action)
{
	if (action == nullptr)
	{
		return;
	}

	m_sActions.insert(action);
}

void ActionManager::removeAction(ITimer* action)
{
	if (action == nullptr)
	{
		return;
	}

	m_sActions.erase(action);
}

void ActionManager::removeAllActions()
{
	std::set<ITimer*>::iterator iter = m_sActions.begin();
	while (iter != m_sActions.end())
	{
		delete *iter;
		iter++;
	}

	m_sActions.clear();
}

void ActionManager::update(float dt)
{
	std::set<ITimer*>::iterator iter = m_sActions.begin();
	while (iter != m_sActions.end())
	{
		(*iter)->update(dt);
		iter++;
	}
}