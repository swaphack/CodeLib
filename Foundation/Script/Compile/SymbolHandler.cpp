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

	const SymbolInformation* pInfo = pDelegate->getSymbolInformation();

	m_mSymbolDelegates[pInfo->name] = pDelegate;
	if (pInfo->embed)
	{
		m_mEmbedBeginSymbolDelegates[pInfo->begin] = pDelegate;
		m_mEmbedEndSymbolDelegates[pInfo->end] = pDelegate;
	}
}

void SymbolHandler::removeSymbolDelegate(SymbolDelegate* pDelegate)
{
	if (pDelegate == nullptr)
	{
		return;
	}

	const SymbolInformation* pInfo = pDelegate->getSymbolInformation();

	// 内联开始
	SymbolDelegates::iterator iter = m_mEmbedBeginSymbolDelegates.find(pInfo->begin);
	if (iter != m_mEmbedBeginSymbolDelegates.end())
	{
		m_mEmbedBeginSymbolDelegates.erase(iter);
	}

	// 内联结束
	iter = m_mEmbedEndSymbolDelegates.find(pInfo->end);
	if (iter != m_mEmbedEndSymbolDelegates.end())
	{
		m_mEmbedEndSymbolDelegates.erase(iter);
	}

	// 符号
	iter = m_mSymbolDelegates.find(pInfo->name);
	if (iter == m_mSymbolDelegates.end())
	{
		return;
	}

	delete iter->second;
	m_mSymbolDelegates.erase(iter);
}

void SymbolHandler::removeAllSymbolDelegates()
{
	m_mEmbedBeginSymbolDelegates.clear();
	m_mEmbedEndSymbolDelegates.clear();

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
	if (iter != m_mSymbolDelegates.end())
	{
		return iter->second;
	}

	iter = m_mEmbedBeginSymbolDelegates.find(name);
	if (iter != m_mEmbedBeginSymbolDelegates.end())
	{
		return iter->second;
	}

	iter = m_mEmbedEndSymbolDelegates.find(name);
	if (iter != m_mEmbedEndSymbolDelegates.end())
	{
		return iter->second;
	}

	return nullptr;
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
		SymbolInformation info;
		info.name = pElement->Attribute("name");
		info.expression = pElement->GetText();
		info.priorityLevel = pElement->IntAttribute("level");
		if (pElement->Attribute("embed")) 
		{
			info.embed = pElement->IntAttribute("embed") == 1;
		}
		if (pElement->Attribute("begin")) 
		{
			info.begin = pElement->Attribute("begin");
		}
		if (pElement->Attribute("end")) 
		{
			info.end = pElement->Attribute("end");
		}

		SymbolDelegate* pDelegate = new SymbolDelegate();
		pDelegate->setSymbolInformation(info);
		this->addSymbolDelegate(pDelegate);

		pElement = pElement->NextSiblingElement();
	}

	return true;
}
