#include "XmlHelper.h"
#include "system.h"
#include <vector>
#include "XmlHelper.h"
using namespace tool;

XmlHelper::XmlHelper()
{
	m_pDocument = new tinyxml2::XMLDocument();
}

XmlHelper::~XmlHelper()
{
	if (m_pDocument != nullptr)
	{
		delete m_pDocument;
	}
}

tinyxml2::XMLDocument* tool::XmlHelper::getDocument()
{
	if (m_pDocument == nullptr || m_pDocument->Error())
	{
		return nullptr;
	}
	return m_pDocument;
}

tinyxml2::XMLElement* tool::XmlHelper::getRoot()
{
	auto doc = getDocument();
	if (doc == nullptr) return nullptr;

	auto root = doc->RootElement();
	if (root == nullptr)
	{
		root = doc->NewElement("root");
		doc->InsertFirstChild(root);
	}
	return root;
}

bool XmlHelper::loadFile(const std::string& filepath)
{
	if (filepath.empty())
	{
		return false;
	}

	auto doc = getDocument();
	if (doc == nullptr) return nullptr;

	tinyxml2::XMLError error = doc->LoadFile(filepath.c_str());
	if (error != tinyxml2::XML_SUCCESS)
	{
		PRINT("Load XML File Error %d", error);
		return false;
	}

	return true;
}

void tool::XmlHelper::saveTo(const std::string& filepath)
{
	auto doc = getDocument();
	if (doc == nullptr) return;

	tinyxml2::XMLError error = doc->SaveFile(filepath.c_str());
	if (error != tinyxml2::XML_SUCCESS)
	{
		PRINT("Save XML File Error %d", error);
		return;
	}
}

void tool::XmlHelper::getRootAttributes(std::map<std::string, std::string>& value)
{
	auto root = getRoot();
	if (root == nullptr) return;

	auto attribute = root->FirstAttribute();
	while (attribute)
	{
		value[attribute->Name()] = attribute->Value();
		attribute = attribute->Next();
	}	
}

void tool::XmlHelper::setRootAttributes(const std::map<std::string, std::string>& value)
{
	auto root = getRoot();
	if (root == nullptr) return;
	for (const auto& item : value)
	{
		root->SetAttribute(item.first.c_str(), item.second.c_str());
	}
}

void tool::XmlHelper::appendElementWithAttributes(const std::string& nodeName, const std::map<std::string, std::string>& value)
{
	auto doc = getDocument();
	if (doc == nullptr) return;

	tinyxml2::XMLElement* pElement = doc->NewElement(nodeName.c_str());
	for (const auto& item : value)
	{
		pElement->SetAttribute(item.first.c_str(), item.second.c_str());
	}
	doc->RootElement()->InsertEndChild(pElement);
}

void tool::XmlHelper::appendElementWithChildren(const std::string& nodeName, const std::map<std::string, std::string>& value)
{
	auto doc = getDocument();
	if (doc == nullptr) return;

	tinyxml2::XMLElement* pElement = doc->NewElement(nodeName.c_str());
	for (const auto& item : value)
	{
		tinyxml2::XMLElement* pChild = doc->NewElement(item.first.c_str());
		pChild->SetText(item.second.c_str());
		pElement->InsertEndChild(pChild);
	}
	doc->RootElement()->InsertEndChild(pElement);
}

void tool::XmlHelper::appendElementWithChildren(const std::string& nodeName, const std::vector<std::pair<std::string, std::string>>& value)
{
	auto doc = getDocument();
	if (doc == nullptr) return;

	tinyxml2::XMLElement* pElement = doc->NewElement(nodeName.c_str());
	for (const auto& item : value)
	{
		tinyxml2::XMLElement* pChild = doc->NewElement(item.first.c_str());
		pChild->SetText(item.second.c_str());
		pElement->InsertEndChild(pChild);
	}
	doc->RootElement()->InsertEndChild(pElement);
}

tinyxml2::XMLElement* XmlHelper::getElement(const std::string& nodePath, const std::string& spot)
{
	auto doc = getDocument();
	if (doc == nullptr) return nullptr;

	if (nodePath.empty())
	{
		return nullptr;
	}

	tinyxml2::XMLElement* pRoot = doc->RootElement();
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
	auto doc = getDocument();
	if (doc == nullptr) return;

	tinyxml2::XMLElement* pRoot = doc->RootElement();
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
