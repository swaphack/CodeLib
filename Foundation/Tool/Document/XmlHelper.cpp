#include "XmlHelper.h"
#include "system.h"
#include <vector>
#include "XmlHelper.h"
using namespace tool;

XmlHelper::XmlHelper()
{
	m_pDocument = new tinyxml2::XMLDocument();

	auto pRoot = m_pDocument->NewElement("root");
	m_pDocument->InsertFirstChild(pRoot);
}

XmlHelper::~XmlHelper()
{
	delete m_pDocument;
}

bool XmlHelper::loadFile(const std::string& filepath)
{
	if (filepath.empty())
	{
		return false;
	}

	tinyxml2::XMLError error = m_pDocument->LoadFile(filepath.c_str());
	if (error != tinyxml2::XML_SUCCESS)
	{
		return false;
	}

	return true;
}

void tool::XmlHelper::saveTo(const std::string& filepath)
{
	tinyxml2::XMLError error = m_pDocument->SaveFile(filepath.c_str());
	if (error != tinyxml2::XML_SUCCESS)
	{
	}
}

void tool::XmlHelper::appendElementWithAttributes(const std::string& nodeName, const std::map<std::string, std::string>& value)
{
	tinyxml2::XMLElement* pElement = m_pDocument->NewElement(nodeName.c_str());
	for (const auto& item : value)
	{
		pElement->SetAttribute(item.first.c_str(), item.second.c_str());
	}
	m_pDocument->RootElement()->InsertEndChild(pElement);
}

void tool::XmlHelper::appendElementWithChildren(const std::string& nodeName, const std::map<std::string, std::string>& value)
{
	tinyxml2::XMLElement* pElement = m_pDocument->NewElement(nodeName.c_str());
	for (const auto& item : value)
	{
		tinyxml2::XMLElement* pChild = m_pDocument->NewElement(item.first.c_str());
		pChild->SetText(item.second.c_str());
		pElement->InsertEndChild(pChild);
	}
	m_pDocument->RootElement()->InsertEndChild(pElement);
}

tinyxml2::XMLElement* XmlHelper::getElement(const std::string& nodePath, const std::string& spot)
{
	if (nodePath.empty())
	{
		return nullptr;
	}

	tinyxml2::XMLElement* pRoot = m_pDocument->RootElement();
	if (pRoot == nullptr)
	{
		return nullptr;
	}
	
	sys::String str = nodePath;
	std::vector<sys::String> dest;
	str.split(spot, dest);

	tinyxml2::XMLElement* pChild = nullptr;

	int index = 0;
	int destSize = dest.size();
	while (index < destSize)
	{
		pChild = pRoot->FirstChildElement(dest[index++].getString());
		if (pChild == nullptr)
		{
			return nullptr;
		}

		pRoot = pChild;
	}

	if (index == dest.size())
	{
		return pChild;
	}

	return nullptr;
}

std::string XmlHelper::getAttribute(const std::string& nodepath, const std::string& name)
{
	if (nodepath.empty() || name.empty())
	{
		return "";
	}

	tinyxml2::XMLElement* element = getElement(nodepath);
	if (element == nullptr)
	{
		return "";
	}

	const char* result = element->Attribute(name.c_str());
	if (result)
	{
		return result;
	}

	return "";
}

void tool::XmlHelper::foreach(const std::function<void(tinyxml2::XMLElement*)>& func)
{
	if (func == nullptr)
	{
		return;
	}
	tinyxml2::XMLElement* pRoot = m_pDocument->RootElement();
	if (pRoot == nullptr)
	{
		return;
	}

	tinyxml2::XMLElement* pChild = pRoot->FirstChildElement();
	if (pChild == nullptr)
	{
		return;
	}

	while (pChild != nullptr)
	{
		func(pChild);
		pChild = pChild->NextSiblingElement();
	}
}
