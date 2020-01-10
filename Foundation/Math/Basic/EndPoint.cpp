#include "EndPoint.h"

using namespace math;

EndPoint::EndPoint(EndPointType type, float value)
	:_type(type), _value(value)
{

}

EndPoint::EndPoint()
{

}

EndPoint::EndPoint(const EndPoint& endPoint)
{
	_type = endPoint.getType();
	_value = endPoint.getValue();
}

void EndPoint::setType(EndPointType type)
{
	_type = type;
}

EndPointType EndPoint::getType() const
{
	return _type;
}

void EndPoint::setValue(float value)
{
	_value = value;
}

float EndPoint::getValue() const
{
	return _value;
}