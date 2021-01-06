#include "ComputeQueue.h"
#include "Common/Action/import.h"

render::ComputeQueue::ComputeQueue()
{
	auto pAction = RepeateForeverAction::create(
		SequenceAction::create(DelayAction::create(0), CallFunc::create([this]() {
			this->process();
		}))
	);
	this->getActionProxy()->runAction(pAction);
}

render::ComputeQueue::~ComputeQueue()
{

}

void render::ComputeQueue::pushBack(Node* target, const ComputeFunction& func)
{
	if (target == nullptr || func == nullptr)
	{
		return;
	}

	_funcs.push_back(std::make_pair(target, func));
}

void render::ComputeQueue::remove(Node* target)
{
	if (target == nullptr)
	{
		return;
	}

	int size = _funcs.size();
	for (int i = size - 1; i >= 0; i--)
	{
		if (_funcs[i].first == target)
		{
			_funcs.erase(_funcs.begin() + i);
		}
	}
}

void render::ComputeQueue::process()
{
	if (_funcs.empty())
	{
		return;
	}

	auto head = _funcs.front();
	_funcs.erase(_funcs.begin());

	if (head.second)
		head.second();
}
