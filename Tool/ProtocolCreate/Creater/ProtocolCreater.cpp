#include "ProtocolCreater.h"

#include "IProtocolFile.h"


ProtocolCreater::ProtocolCreater()
{

}

ProtocolCreater::~ProtocolCreater()
{
	this->clearProtocols();
}

void ProtocolCreater::addProtocol(IProtocolFile* pProtocol)
{
	if (pProtocol == nullptr)
	{
		return;
	}

	m_vecProtocols.push_back(pProtocol);
}

void ProtocolCreater::removeProtocol(IProtocolFile* pProtocol)
{
	if (pProtocol == nullptr)
	{
		return;
	}

	std::vector<IProtocolFile*>::iterator itr = m_vecProtocols.begin();

	while (itr != m_vecProtocols.end())
	{
		if (*itr == pProtocol)
		{
			delete *itr;
			m_vecProtocols.erase(itr);
			break;
		}
		itr++;
	}
}

bool ProtocolCreater::existsProtocol(IProtocolFile* pProtocol)
{
	if (pProtocol == nullptr)
	{
		return false;
	}

	std::vector<IProtocolFile*>::const_iterator itr = m_vecProtocols.begin();

	while (itr != m_vecProtocols.end())
	{
		if (*itr == pProtocol)
		{
			return true;
		}
		itr++;
	}

	return false;
}

void ProtocolCreater::clearProtocols()
{
	std::vector<IProtocolFile*>::iterator itr = m_vecProtocols.begin();

	while (itr != m_vecProtocols.end())
	{
		delete *itr;
		itr++;
	}

	m_vecProtocols.clear();
}

void ProtocolCreater::Flush(XMLDocument* pDocument)
{
	std::vector<IProtocolFile*>::iterator itr = m_vecProtocols.begin();

	while (itr != m_vecProtocols.end())
	{
		if (!(*itr)->loadPackets(pDocument))
		{
			printf("Create File %s Failure\n", (*itr)->createFileName());
		}
		itr++;
	}
}
