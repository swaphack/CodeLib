#include "NPropertyProtocol.h"

using namespace nature;

NPropertyProtocol::NPropertyProtocol()
{

}

NPropertyProtocol::~NPropertyProtocol()
{
	this->removeAllProperties();
}

NProperty* NPropertyProtocol::getAndCreateProperty(int nPropertyID)
{
	std::map<int, NProperty*>::iterator iter = _propertyDict.find(nPropertyID);
	if (iter != _propertyDict.end())
	{
		return iter->second;
	}

	NProperty* pProperty = new NProperty();
	pProperty->setID(nPropertyID);
	pProperty->registerChangedHandler(this, static_cast<NPropertyChanged>(&NPropertyProtocol::onPropertyChanged));

	_propertyDict[nPropertyID] = pProperty;
	return pProperty;
}

void NPropertyProtocol::removeProperty(int nPropertyID)
{
	std::map<int, NProperty*>::iterator iter = _propertyDict.find(nPropertyID);
	if (iter != _propertyDict.end())
	{
		delete iter->second;
		_propertyDict.erase(iter);
		return;
	}
}

void NPropertyProtocol::removeAllProperties()
{
	std::map<int, NProperty*>::iterator iter = _propertyDict.begin();
	while (iter != _propertyDict.end())
	{
		delete iter->second;
		iter++;
	}

	_propertyDict.clear();
}

void NPropertyProtocol::onPropertyChanged(NProperty* pProperty)
{
	if (nullptr == pProperty)
	{
		return;
	}

	onPropertyChangedHandler(pProperty);
}

void NPropertyProtocol::onPropertyChangedHandler(NProperty* pProperty)
{

}