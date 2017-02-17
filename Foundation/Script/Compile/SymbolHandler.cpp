#include "SymbolHandler.h"

#include "text.h"

using namespace script;


SymbolHandler::SymbolHandler()
{

}

SymbolHandler::~SymbolHandler()
{
	this->removeAllSymbolDelegates();
}

SymbolHandler* SymbolHandler::getInstance()
{
	static SymbolHandler* s_OperatorHandler = nullptr;
	if (s_OperatorHandler == nullptr)
	{
		s_OperatorHandler = new SymbolHandler();
	}

	return s_OperatorHandler;
}

void SymbolHandler::addSymbolDelegate(SymbolDelegate* pDelegate)
{
	if (pDelegate == nullptr)
	{
		return;
	}

	removeSymbolDelegate(pDelegate);

	m_mSymbolDelegates[pDelegate->getSymbolInformation().name] = pDelegate;
}

void SymbolHandler::removeSymbolDelegate(SymbolDelegate* pDelegate)
{
	if (pDelegate == nullptr)
	{
		return;
	}

	SymbolDelegates::iterator iter = m_mSymbolDelegates.find(pDelegate->getSymbolInformation().name);
	if (iter == m_mSymbolDelegates.end())
	{
		return;
	}

	delete iter->second;
	m_mSymbolDelegates.erase(iter);
}

void SymbolHandler::removeAllSymbolDelegates()
{
	SymbolDelegates::iterator iter = m_mSymbolDelegates.begin();
	while (iter != m_mSymbolDelegates.end())
	{
		delete iter->second;
		iter++;
	}
	m_mSymbolDelegates.clear();
}

SymbolDelegate* SymbolHandler::getSymbolDelegate(const char* name)
{
	if (name == nullptr)
	{
		return nullptr;
	}

	SymbolDelegates::iterator iter = m_mSymbolDelegates.find(name);
	if (iter == m_mSymbolDelegates.end())
	{
		return nullptr;
	}

	return iter->second;
}

bool SymbolHandler::load(const char* filepath)
{
	if (filepath == nullptr)
	{
		return false;
	}

	tinyxml2::XMLDocument document;
	tinyxml2::XMLError error = document.LoadFile(filepath);
	if (error != tinyxml2::XML_SUCCESS)
	{
		return false;
	}

	tinyxml2::XMLElement* pRoot = document.RootElement();

	tinyxml2::XMLElement* pElement = pRoot->FirstChildElement();

	while (pElement)
	{
		SymbolDelegate* pDelegate = new SymbolDelegate();
		pDelegate->getSymbolInformation().name = pElement->Attribute("name");
		pDelegate->getSymbolInformation().expression = pElement->GetText();
		pDelegate->getSymbolInformation().priorityLevel = pElement->IntAttribute("level");
		pDelegate->getSymbolInformation().embed = pElement->IntAttribute("embed") == 1;
		pDelegate->makeASTNode();

		this->addSymbolDelegate(pDelegate);

		pElement = pElement->NextSiblingElement();
	}

	return true;
}
