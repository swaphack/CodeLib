#include "Task.h"
#include "Work/Workflow/WorkFlow.h"
alg::work::Task::Task()
{

}

alg::work::Task::~Task()
{
	this->removeAllLimits();
}

void alg::work::Task::setWorkFlow(WorkFlow* workflow)
{
	_workflow = workflow;
}

alg::work::WorkFlow* alg::work::Task::getWorkFlow() const
{
	return _workflow;
}

void alg::work::Task::setWorkFlowData(const std::string& name, void* data)
{
	if (_workflow == nullptr) return;
	_workflow->getSharedData()->setData(name, data);
}

void* alg::work::Task::getWorkFlowData(const std::string& name) const
{
	if (_workflow == nullptr) return nullptr;
	return _workflow->getSharedData()->getData(name);
}

void alg::work::Task::addLimit(TaskLimit* limit)
{
	if (limit == nullptr) return;
	if (_limits.find(limit) != _limits.end())
		return;
	SAFE_RETAIN(limit);
	limit->setTask(this);
	_limits.insert(limit);
}

void alg::work::Task::removeLimit(TaskLimit* limit)
{
	if (limit == nullptr) return;
	if (_limits.find(limit) == _limits.end())
		return;
	SAFE_RELEASE(limit);
	limit->setTask(nullptr);
	_limits.erase(limit);
}

void alg::work::Task::removeAllLimits()
{
	for (auto item : _limits)
	{
		item->setTask(nullptr);
		SAFE_RELEASE(item);
	}
	_limits.clear();
}

void alg::work::Task::onUpdate(float dt)
{
	if (_func) _func(dt);
	if (_event) _event->doEvent(dt);

	if (!this->isOver())
	{// ÏÞÖÆÅÐ¶Ï
		for (auto item : _limits)
		{
			item->update(dt);
			if (item->isTrigger())
			{
				this->finish();
				break;
			}
		}
	}
	
}

void alg::work::Task::setTaskFunc(const TaskFunc& func)
{
	_func = func;
}

void alg::work::Task::setTaskEvent(const ITaskEvent* pEvt)
{
	_event = (ITaskEvent*)pEvt;
}
