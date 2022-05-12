#include "TaskLimit.h"

alg::work::TaskLimit::TaskLimit()
{
}

alg::work::TaskLimit::~TaskLimit()
{
}

void alg::work::TaskLimit::update(float dt)
{
	if (_bTrigger) return;

	onUpdate(dt);
}

bool alg::work::TaskLimit::isTrigger() const
{
	return _bTrigger;
}

void alg::work::TaskLimit::setTrigger(bool bTrigger)
{
	_bTrigger = bTrigger;
}

void alg::work::TaskLimit::reset()
{
	_bTrigger = false;
	onReset();
}

void alg::work::TaskLimit::setTask(Task* task)
{
	_task = task;
}

alg::work::Task* alg::work::TaskLimit::getTask() const
{
	return _task;
}

void alg::work::TaskLimit::onUpdate(float dt)
{
}

void alg::work::TaskLimit::onReset()
{
}
