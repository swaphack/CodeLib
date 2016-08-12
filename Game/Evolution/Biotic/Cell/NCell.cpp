#include "NCell.h"

using namespace nature;

NCell::NCell()
{
}

NCell::~NCell()
{

}

NCell* NCell::division()
{
	return nullptr;
}

void NCell::update(float dt)
{
	if (!_inputTargets.empty())
	{
		return;
	}

	TargetHandler* pTargetHandler = _inputTargets.front();
	if (!pTargetHandler->Finish)
	{
		NObject* result = handInputTarget(pTargetHandler);
		if (result)
		{
			onOuputHandler(result);
		}
		if (pTargetHandler->Finish)
		{
			_inputTargets.pop();
			delete pTargetHandler;
		}
	}
}

bool NCell::canAddInputTarget(NObject* pObject)
{
	if (!NOrganism::canAddInputTarget(pObject))
	{
		return false;
	} 

	return true;
}

NObject* NCell::handInputTarget(TargetHandler* handler)
{
	if (handler == nullptr)
	{
		return nullptr;
	}

	return nullptr;
}
