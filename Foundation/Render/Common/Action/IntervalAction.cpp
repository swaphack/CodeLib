#include "IntervalAction.h"
#include "../Node/Node.h"

using namespace render;


IntervalAction::IntervalAction()
:_totalTime(0)
, _currentTime(0)
{

}

IntervalAction::~IntervalAction()
{

}

void IntervalAction::update(float duration)
{
	if (_totalTime == 0)
	{
		this->stop();
		return;
	}
	if (!_bInitData)
	{
		initAction();
		_bInitData = true;
	}
	if (_currentTime < _totalTime)
	{
		float temp = duration;

		_currentTime += duration;
		if (_currentTime >= _totalTime)
		{
			temp = duration - (_currentTime - _totalTime);
			_currentTime = _totalTime;
		}
		{
			float percent = temp / _totalTime;
			this->updateInterval(percent);
		}

		{
			float percent = _currentTime / _totalTime;
			this->updatePercent(percent);
		}
	}
	else
	{
		this->stop();
		this->endAction();
	}
}

void IntervalAction::setDuration(float interval)
{
	_totalTime = interval;
}

float IntervalAction::getDuration() const
{
	return _totalTime;
}

float IntervalAction::getElapsed() const
{
	return _currentTime;
}

void IntervalAction::updateInterval(float percent)
{

}

void IntervalAction::reset()
{
	Action::reset();
	_currentTime = 0;
}

void IntervalAction::reverse()
{
	Action::reverse();
	_currentTime = _totalTime - _currentTime;
}

void render::IntervalAction::initAction()
{

}

void render::IntervalAction::endAction()
{

}

void render::IntervalAction::updatePercent(float curPercent)
{

}

//////////////////////////////////////////////////////////////////////////

MoveToAction::MoveToAction()
{

}

MoveToAction::~MoveToAction()
{
}

void MoveToAction::setDestPosition(float x, float y, float z)
{
	_desPosition.set(x, y, z);
}

void render::MoveToAction::setDestPosition(const math::Vector3& pos)
{
	_desPosition = pos;
}

void render::MoveToAction::initAction()
{
	ASSERT(_target != nullptr);

	_srcPosition = _target->getPosition();
	_differentPosition = _desPosition - _srcPosition;
}

const math::Vector3& MoveToAction::getDestPosition() const
{
	return _desPosition;
}

void MoveToAction::updatePercent(float percent)
{
	_target->setPosition(_srcPosition + percent * _differentPosition);
}

void MoveToAction::reverse()
{
	IntervalAction::reverse();
	auto value = _srcPosition + _desPosition;
	_desPosition = value - _srcPosition;
	_srcPosition = value - _desPosition;

	_differentPosition *= -1;
}

//////////////////////////////////////////////////////////////////////////
MoveByAction::MoveByAction()
{

}

MoveByAction::~MoveByAction()
{
}

void MoveByAction::setDifferentPosition(float x, float y, float z /*= 0*/)
{
	_differentPosition.set(x, y, z);
}

void render::MoveByAction::setDifferentPosition(const math::Vector3& pos)
{
	_differentPosition = pos;
}

const math::Vector3& render::MoveByAction::getDifferentPosition() const
{
	return _differentPosition;
}

void render::MoveByAction::initAction()
{
	ASSERT(_target != nullptr);

	_srcPosition = _target->getPosition();
	_desPosition = _srcPosition + _differentPosition;
}

void render::MoveByAction::endAction()
{
	_srcPosition = _desPosition;
	_desPosition = _srcPosition + _differentPosition;
}

void render::MoveByAction::updatePercent(float percent)
{
	_target->setPosition(_srcPosition + percent * _differentPosition);
}

void MoveByAction::reverse()
{
	IntervalAction::reverse();
	auto value = _srcPosition + _desPosition;
	_desPosition = value - _srcPosition;
	_srcPosition = value - _desPosition;

	_differentPosition *= -1;
}

//////////////////////////////////////////////////////////////////////////
RotateToAction::RotateToAction()
{

}

RotateToAction::~RotateToAction()
{
}

void RotateToAction::setDestRotation(float x, float y, float z /*= 0*/)
{
	_destRotation.set(x, y, z);
}

void render::RotateToAction::setDestRotation(const math::Vector3& rotation)
{
	_destRotation = rotation;
}

const math::Vector3& render::RotateToAction::getDestRotation() const
{
	return _destRotation;
}

void RotateToAction::updatePercent(float percent)
{
	_target->setRotation(_srcRotation + percent * _differentRotation);
}

void RotateToAction::reverse()
{
	IntervalAction::reverse();

	auto value = _srcRotation + _destRotation;
	_destRotation = value - _srcRotation;
	_srcRotation = value - _destRotation;

	_differentRotation *= -1;
}

void render::RotateToAction::initAction()
{
	ASSERT(_target != nullptr);

	_srcRotation = _target->getRotation();
	_differentRotation = _destRotation - _srcRotation;
}

//////////////////////////////////////////////////////////////////////////
RotateByAction::RotateByAction()
{

}

RotateByAction::~RotateByAction()
{
}

void RotateByAction::setDifferentRotation(float x, float y, float z /*= 0*/)
{
	_differentRotation.set(x, y, z);
}

void render::RotateByAction::setDifferentRotation(const math::Vector3& rotation)
{
	_differentRotation = rotation;
}

void render::RotateByAction::initAction()
{
	ASSERT(_target != nullptr);

	_srcRotation = _target->getPosition();
	_destRotation = _srcRotation + _differentRotation;
}

void render::RotateByAction::endAction()
{
	_srcRotation = _destRotation;
	_destRotation = _srcRotation + _differentRotation;
}

const math::Vector3& RotateByAction::getDifferentRotation() const
{
	return _differentRotation;
}

void RotateByAction::updatePercent(float percent)
{
	_target->setRotation(_srcRotation + percent * _differentRotation);
}

void RotateByAction::reverse()
{
	IntervalAction::reverse();

	auto value = _srcRotation + _destRotation;
	_destRotation = value - _srcRotation;
	_srcRotation = value - _destRotation;

	_differentRotation *= -1;
}

//////////////////////////////////////////////////////////////////////////
ScaleToAction::ScaleToAction()
{

}

ScaleToAction::~ScaleToAction()
{
}

void ScaleToAction::setDestScale(float x, float y, float z /*= 0*/)
{
	_destScale.set(x, y, z);
}

void render::ScaleToAction::setDestScale(const math::Vector3& scale)
{
	_destScale = scale;
}

void render::ScaleToAction::initAction()
{
	ASSERT(_target != nullptr);
	
	_srcScale = _target->getScale();
	_differentScale = _destScale - _srcScale;
}

const math::Vector3& ScaleToAction::getDestScale() const
{
	return _destScale;
}

void ScaleToAction::updatePercent(float percent)
{
	_target->setScale(_srcScale + percent * _differentScale);
}

void ScaleToAction::reverse()
{
	IntervalAction::reverse();

	auto value = _srcScale + _destScale;
	_destScale = value - _srcScale;
	_srcScale = value - _destScale;

	_differentScale *= -1;
}

//////////////////////////////////////////////////////////////////////////
ScaleByAction::ScaleByAction()
{

}

ScaleByAction::~ScaleByAction()
{
}

void ScaleByAction::setDifferentScale(float x, float y, float z /*= 0*/)
{
	_differentScale.set(x, y, z);
}

void ScaleByAction::setDifferentScale(const math::Vector3& scale)
{
	_differentScale = scale;
}

const math::Vector3& render::ScaleByAction::getDifferentScale() const
{
	return _differentScale;
}

void render::ScaleByAction::initAction()
{
	ASSERT(_target != nullptr);

	_srcScale = _target->getScale();
	_destScale = _srcScale + _differentScale;
}

void render::ScaleByAction::endAction()
{
	_srcScale = _destScale;
	_destScale = _srcScale + _differentScale;
}

void ScaleByAction::updatePercent(float percent)
{
	_target->setScale(_srcScale + percent * _differentScale);
}

void ScaleByAction::reverse()
{
	IntervalAction::reverse();

	auto value = _srcScale + _destScale;
	_destScale = value - _srcScale;
	_srcScale = value - _destScale;

	_differentScale *= -1;
}
