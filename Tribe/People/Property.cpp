#include "Property.h"

using namespace tribe;


Property::Property()
{

}

Property::~Property()
{

}

void Property::addProperty(int propType, int val /*= 0*/)
{
	_propValues[propType] = val;
}

void Property::removeProperty(int propType)
{
	_propValues.erase(propType);
}

int Property::getValue(int propType)
{
	if (_propValues.find(propType) == _propValues.end())
	{
		return 0;
	}

	return _propValues[propType];
}
