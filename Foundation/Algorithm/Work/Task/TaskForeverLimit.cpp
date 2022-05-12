#include "TaskForeverLimit.h"
#include "Task.h"

alg::work::TaskForeverLimit::TaskForeverLimit()
{

}

alg::work::TaskForeverLimit::~TaskForeverLimit()
{

}

void alg::work::TaskForeverLimit::onUpdate(float dt)
{
	if (_task != nullptr)
	{
		if (_task->isOver())
		{// ÈÎÎñ½áÊø
			_task->reset();
		}
	}
}
