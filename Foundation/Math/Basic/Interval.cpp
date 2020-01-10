#include "Interval.h"

using namespace math;

Interval::Interval()
{
}

Interval::Interval(float minValue, float maxValue)
{
	this->_minEndPoint = EndPoint(EndPointType::Include, minValue);
	this->_maxEndPoint = EndPoint(EndPointType::Include, maxValue);
}

Interval::Interval(const EndPoint& minEndPoint, const EndPoint& maxEndPoint)
{
	this->_minEndPoint = minEndPoint;
	this->_maxEndPoint = maxEndPoint;
}

const EndPoint& Interval::getMinEndPoint()
{
	return this->_minEndPoint;
}

void Interval::setMinEndPoint(const EndPoint& endPoint)
{
	this->_minEndPoint = endPoint;
}

const EndPoint& Interval::getMaxEndPoint()
{
	return _maxEndPoint;
}

void Interval::setMaxEndPoint(const EndPoint& endPoint)
{
	this->_maxEndPoint = endPoint;
}

EndPointType Interval::getMinType() const
{
	return this->_minEndPoint.getType();
}

void Interval::setMinType(EndPointType type)
{
	this->_minEndPoint.setType(type);
}

EndPointType Interval::getMaxType() const
{
	return this->_maxEndPoint.getType();
}

void Interval::setMaxType(EndPointType type)
{
	this->_maxEndPoint.setType(type);
}

float Interval::getMinValue() const
{
	return this->_minEndPoint.getValue();
}

void Interval::setMinValue(float value)
{
	this->_minEndPoint.setValue(value);
}

float Interval::getMaxValue() const
{
	return this->_maxEndPoint.getValue();
}

void Interval::setMaxValue(float value)
{
	this->_maxEndPoint.setValue(value);
}

bool Interval::contains(float value)
{
	if (value < this->getMinValue() || value > this->getMaxValue())
	{
		return false;
	}

	if (this->getMinType() != EndPointType::Include)
	{
		if (value == this->getMinValue())
		{
			return false;
		}
	}

	if (this->getMaxType() != EndPointType::Include)
	{
		if (value == this->getMaxValue())
		{
			return false;
		}
	}

	return true;
}


