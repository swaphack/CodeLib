#include "NStatusProtocol.h"

using namespace nature;

NStatusProtocol::NStatusProtocol()
{

}

NStatusProtocol::~NStatusProtocol()
{
	this->removeAllStatus();
}

NStatus* NStatusProtocol::getAndCreateStatus(int nStatusID)
{
	std::map<int, NStatus*>::iterator iter = _statusDict.find(nStatusID);
	if (iter != _statusDict.end())
	{
		return iter->second;
	}

	NStatus* pStatus = new NStatus();
	pStatus->setID(nStatusID);
	pStatus->registerChangedHandler(this, static_cast<NStatusChanged>(&NStatusProtocol::onStatusChanged));

	_statusDict[nStatusID] = pStatus;
	return pStatus;
}

void NStatusProtocol::removeStatus(int nStatusID)
{
	std::map<int, NStatus*>::iterator iter = _statusDict.find(nStatusID);
	if (iter != _statusDict.end())
	{
		delete iter->second;
		_statusDict.erase(iter);
		return;
	}
}

void NStatusProtocol::removeAllStatus()
{
	std::map<int, NStatus*>::iterator iter = _statusDict.begin();
	while (iter != _statusDict.end())
	{
		delete iter->second;
		iter++;
	}

	_statusDict.clear();
}

void NStatusProtocol::onStatusChanged(NStatus* pStatus)
{
	if (nullptr == pStatus)
	{
		return;
	}

	onStatusChangedHandler(pStatus);
}

void NStatusProtocol::onStatusChangedHandler(NStatus* pStatus)
{

}