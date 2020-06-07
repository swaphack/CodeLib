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
	if (_currentTime < _totalTime)
	{
		if (_currentTime + duration >= _totalTime)
		{
			duration = _totalTime - _currentTime;
		}
		float percent = duration / _totalTime;
		this->updateInterval(percent);
		_currentTime += duration;
	}
	else
	{
		this->stop();
	}
}

void IntervalAction::setDuration(float interval)
{
	_totalTime = interval;
}

float IntervalAction::getDuration()
{
	return _totalTime;
}

float IntervalAction::getElapsed()
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

//////////////////////////////////////////////////////////////////////////

MoveToAction::MoveToAction()
{

}

MoveToAction::~MoveToAction()
{
}

void MoveToAction::setPosition(float x, float y, float z)
{
	_destination.set(x, y, z);
}

math::Vector3 MoveToAction::getPosition()
{
	return _destination;
}

void MoveToAction::updateInterval(float percent)
{
	Node* node = _target;
	if (node && _currentTime == 0)
	{
		_offset = _destination;
		_offset-=node->getPosition();
	}
	if (node)
	{
		const math::Vector3& current = node->getPosition();
		node->setPosition(
			current.getX() + _offset.getX() * percent,
			current.getY() + _offset.getY() * percent,
			current.getZ() + _offset.getZ() * percent);
	}
}

void MoveToAction::reverse()
{
	IntervalAction::reverse();
	_offset *= -1;
}

//////////////////////////////////////////////////////////////////////////
MoveByAction::MoveByAction()
{

}

MoveByAction::~MoveByAction()
{
}

void MoveByAction::setPosition(float x, float y, float z /*= 0*/)
{
	_offset.set(x, y, z);
}

math::Vector3 MoveByAction::getPosition()
{
	return _offset;
}

void MoveByAction::updateInterval(float percent)
{
	Node* node =_target;
	if (node)
	{
		const math::Vector3& current = node->getPosition();
		node->setPosition(
			current.getX() + _offset.getX() * percent,
			current.getY() + _offset.getY() * percent,
			current.getZ() + _offset.getZ() * percent);
	}
}

void MoveByAction::reverse()
{
	IntervalAction::reverse();
	_offset *= -1;
}

//////////////////////////////////////////////////////////////////////////
RotateToAction::RotateToAction()
{

}

RotateToAction::~RotateToAction()
{
}

void RotateToAction::setRotation(float x, float y, float z /*= 0*/)
{
	_rotation.set(x, y, z);
}

math::Vector3 RotateToAction::getRotation()
{
	return _rotation;
}

void RotateToAction::updateInterval(float percent)
{
	Node* node =_target;
	if (node && _currentTime == _totalTime)
	{
		_offset = _rotation;
		_offset-=node->getRotation();
	}
	if (node)
	{
		const math::Vector3& current = node->getRotation();
		node->setRotation(
			current.getX() + _offset.getX() * percent,
			current.getY() + _offset.getY() * percent,
			current.getZ() + _offset.getZ() * percent);
	}
}

void RotateToAction::reverse()
{
	IntervalAction::reverse();
	_offset *= -1;
}

//////////////////////////////////////////////////////////////////////////
RotateByAction::RotateByAction()
{

}

RotateByAction::~RotateByAction()
{
}

void RotateByAction::setRotation(float x, float y, float z /*= 0*/)
{
	_offset.set(x, y, z);
}

math::Vector3 RotateByAction::getRotation()
{
	return _offset;
}

void RotateByAction::updateInterval(float percent)
{
	Node* node =_target;
	if (node)
	{
		const math::Vector3& current = node->getRotation();
		node->setRotation(
			current.getX() + _offset.getX() * percent,
			current.getY() + _offset.getY() * percent,
			current.getZ() + _offset.getZ() * percent);
	}
}

void RotateByAction::reverse()
{
	IntervalAction::reverse();
	_offset *= -1;
}

//////////////////////////////////////////////////////////////////////////
ScaleToAction::ScaleToAction()
{

}

ScaleToAction::~ScaleToAction()
{
}

void ScaleToAction::setScale(float x, float y, float z /*= 0*/)
{
	_scale.set(x, y, z);
}

math::Vector3 ScaleToAction::getScale()
{
	return _scale;
}

void ScaleToAction::updateInterval(float percent)
{
	Node* node =_target;
	if (node && _currentTime == _totalTime)
	{
		_offset = _scale;
		_offset-=node->getScale();
		_src = node->getScale();
	}
	if (node)
	{
		const math::Vector3& current = node->getScale();
		node->setScale(
			current.getX() + _offset.getX() * percent,
			current.getY() + _offset.getY() * percent,
			current.getZ() + _offset.getZ() * percent);
	}
}

void ScaleToAction::reverse()
{
	IntervalAction::reverse();
	_offset *= -1;
}

//////////////////////////////////////////////////////////////////////////
ScaleByAction::ScaleByAction()
{

}

ScaleByAction::~ScaleByAction()
{
}

void ScaleByAction::setScale(float x, float y, float z /*= 0*/)
{
	_offset.set(x, y, z);
}

math::Vector3 ScaleByAction::getScale()
{
	return _offset;
}

void ScaleByAction::updateInterval(float percent)
{
	Node* node =_target;
	if (node)
	{
		const math::Vector3& current = node->getScale();
		node->setScale(
			current.getX() + _offset.getX() * percent,
			current.getY() + _offset.getY() * percent,
			current.getZ() + _offset.getZ() * percent);
	}
}

void ScaleByAction::reverse()
{
	IntervalAction::reverse();
	_offset *= -1;
}
