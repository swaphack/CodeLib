#include "IntervalAction.h"
#include "../Node/Node.h"

using namespace render;


IntervalAction::IntervalAction()
:_totalInterval(0)
, _currentInterval(0)
{

}

IntervalAction::~IntervalAction()
{

}

void IntervalAction::update(float duration)
{
	if (_currentInterval > 0)
	{
		this->updateInterval(duration);
	}
	else
	{
		this->stop();
	}
}

void IntervalAction::setInterval(float interval)
{
	_totalInterval = interval;
	_currentInterval = interval;
}

float IntervalAction::getInterval()
{
	return _totalInterval;
}

void IntervalAction::updateInterval(float duration)
{

}

//////////////////////////////////////////////////////////////////////////

MoveToAction::MoveToAction()
{

}

MoveToAction::~MoveToAction()
{
}

void MoveToAction::setDestination(float x, float y, float z)
{
	_destination.x = x;
	_destination.y = y;
	_destination.z = z;
}

sys::Vector MoveToAction::getDestination()
{
	return _destination;
}

void MoveToAction::updateInterval(float duration)
{
	Node* node = dynamic_cast<Node*>(_target);
	if (_currentInterval == _totalInterval)
	{
		_offset = _destination;
		_offset.sub(node->getPosition());
		_src = node->getPosition();
	}
	if (node)
	{
		const sys::Vector& current = node->getPosition();

		node->setPosition(
			current.x + _offset.x * duration / _totalInterval,
			current.y + _offset.y * duration / _totalInterval,
			current.z + _offset.z * duration / _totalInterval);
	}

	_currentInterval -= duration;
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
	_rotation.x = x;
	_rotation.y = y;
	_rotation.z = z;
}

sys::Vector RotateToAction::getRotation()
{
	return _rotation;
}

void RotateToAction::updateInterval(float duration)
{
	Node* node = dynamic_cast<Node*>(_target);
	if (_currentInterval == _totalInterval)
	{
		_offset = _rotation;
		_offset.sub(node->getRotation());
		_src = node->getRotation();
	}
	if (node)
	{
		const sys::Vector& current = node->getRotation();

		node->setRotation(
			current.x + _offset.x * duration / _totalInterval,
			current.y + _offset.y * duration / _totalInterval,
			current.z + _offset.z * duration / _totalInterval);
	}

	_currentInterval -= duration;
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
	_scale.x = x;
	_scale.y = y;
	_scale.z = z;
}

sys::Vector ScaleToAction::getScale()
{
	return _scale;
}

void ScaleToAction::updateInterval(float duration)
{
	Node* node = dynamic_cast<Node*>(_target);
	if (_currentInterval == _totalInterval)
	{
		_offset = _scale;
		_offset.sub(node->getScale());
		_src = node->getScale();
	}
	if (node)
	{
		const sys::Vector& current = node->getPosition();

		node->setScale(
			current.x + _offset.x * duration / _totalInterval,
			current.y + _offset.y * duration / _totalInterval,
			current.z + _offset.z * duration / _totalInterval);
	}

	_currentInterval -= duration;
}
