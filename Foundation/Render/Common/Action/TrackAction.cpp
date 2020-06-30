#include "TrackAction.h"
#include "Common/Node/Node.h"

render::TrackAction::TrackAction()
{

}

render::TrackAction::~TrackAction()
{

}

void render::TrackAction::updatePercent(float curPercent)
{
	if (getTarget() == nullptr)
	{
		return;
	}

	math::Vector3 pos = getPosition(curPercent);

	_target->setPosition(pos);
}

math::Vector3 render::TrackAction::getPosition(float curPercent)
{
	return math::Vector3();
}

