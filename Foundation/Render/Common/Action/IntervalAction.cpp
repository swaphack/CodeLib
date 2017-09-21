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
	if (_currentTime <= _totalTime)
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
	_totalTime = interval;
}

float IntervalAction::getInterval()
{
	return _totalTime;
}

void IntervalAction::updateInterval(float duration)
{

}

void IntervalAction::reset()
{
	_currentTime = 0;
}

void IntervalAction::reverse()
{
	_currentTime = _totalTime - _currentTime;
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

sys::Vector3 MoveToAction::getDestination()
{
	return _destination;
}

void MoveToAction::updateInterval(float duration)
{
	Node* node = dynamic_cast<Node*>(_target);
	if (node && _currentTime == 0)
	{
		_offset = _destination;
		_offset.sub(node->getPosition());
	}
	if (node)
	{
		const sys::Vector3& current = node->getPosition();
		float ratio = duration / _totalTime;
		node->setPosition(
			current.x + _offset.x * ratio,
			current.y + _offset.y * ratio,
			current.z + _offset.z * ratio);
	}

	_currentTime += duration;
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

void MoveByAction::setOffset(float x, float y, float z /*= 0*/)
{
	_offset.x = x;
	_offset.y = y;
	_offset.z = z;
}

sys::Vector3 MoveByAction::getOffset()
{
	return _offset;
}

void MoveByAction::updateInterval(float duration)
{
	Node* node = dynamic_cast<Node*>(_target);
	if (node)
	{
		const sys::Vector3& current = node->getPosition();
		float ratio = duration / _totalTime;
		node->setPosition(
			current.x + _offset.x * ratio,
			current.y + _offset.y * ratio,
			current.z + _offset.z * ratio);
	}

	_currentTime += duration;
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
	_rotation.x = x;
	_rotation.y = y;
	_rotation.z = z;
}

sys::Vector3 RotateToAction::getRotation()
{
	return _rotation;
}

void RotateToAction::updateInterval(float duration)
{
	Node* node = dynamic_cast<Node*>(_target);
	if (node && _currentTime == _totalTime)
	{
		_offset = _rotation;
		_offset.sub(node->getRotation());
	}
	if (node)
	{
		const sys::Vector3& current = node->getRotation();
		float ratio = duration / _totalTime;
		node->setRotation(
			current.x + _offset.x * ratio,
			current.y + _offset.y * ratio,
			current.z + _offset.z * ratio);
	}

	_currentTime += duration;
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

void RotateByAction::setOffset(float x, float y, float z /*= 0*/)
{
	_offset.x = x;
	_offset.y = y;
	_offset.z = z;
}

sys::Vector3 RotateByAction::getOffset()
{
	return _offset;
}

void RotateByAction::updateInterval(float duration)
{
	Node* node = dynamic_cast<Node*>(_target);
	if (node)
	{
		const sys::Vector3& current = node->getRotation();
		float ratio = duration / _totalTime;
		node->setRotation(
			current.x + _offset.x * ratio,
			current.y + _offset.y * ratio,
			current.z + _offset.z * ratio);
	}

	_currentTime += duration;
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
	_scale.x = x;
	_scale.y = y;
	_scale.z = z;
}

sys::Vector3 ScaleToAction::getScale()
{
	return _scale;
}

void ScaleToAction::updateInterval(float duration)
{
	Node* node = dynamic_cast<Node*>(_target);
	if (node && _currentTime == _totalTime)
	{
		_offset = _scale;
		_offset.sub(node->getScale());
		_src = node->getScale();
	}
	if (node)
	{
		const sys::Vector3& current = node->getScale();
		float ratio = duration / _totalTime;
		node->setScale(
			current.x + _offset.x * ratio,
			current.y + _offset.y * ratio,
			current.z + _offset.z * ratio);
	}

	_currentTime += duration;
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

void ScaleByAction::setOffset(float x, float y, float z /*= 0*/)
{
	_offset.x = x;
	_offset.y = y;
	_offset.z = z;
}

sys::Vector3 ScaleByAction::getOffset()
{
	return _offset;
}

void ScaleByAction::updateInterval(float duration)
{
	Node* node = dynamic_cast<Node*>(_target);
	if (node)
	{
		const sys::Vector3& current = node->getScale();
		float ratio = duration / _totalTime;
		node->setScale(
			current.x + _offset.x * ratio,
			current.y + _offset.y * ratio,
			current.z + _offset.z * ratio);
	}

	_currentTime += duration;
}

void ScaleByAction::reverse()
{
	IntervalAction::reverse();
	_offset *= -1;
}
