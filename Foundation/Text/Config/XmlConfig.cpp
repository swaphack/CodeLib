#include "XmlConfig.h"
#include "system.h"
#include <vector>
using namespace text;

XmlConfig::XmlConfig()
{
	m_pDocument = new tinyxml2::XMLDocument();
}

XmlConfig::~XmlConfig()
{
	delete m_pDocument;
}

bool XmlConfig::loadFile(const char* filepath)
{
	if (filepath == nullptr)
	{
		return false;
	}

	tinyxml2::XMLError error = m_pDocument->LoadFile(filepath);
	if (error != tinyxml2::XML_SUCCESS)
	{
		return false;
	}

	return true;
}

tinyxml2::XMLElement* XmlConfig::getElement(const char* nodePath)
{
	if (nodePath == nullptr)
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
	str.split(".", dest);

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

const char* XmlConfig::getValue(const char* nodepath, const char* attributeName)
{
	if (nodepath == nullptr || attributeName == nullptr)
	{
		return "";
	}

	tinyxml2::XMLElement* element = getElement(nodepath);
	if (element == nullptr)
	{
		return "";
	}

	const char* result = element->Attribute(attributeName);
	if (result)
	{
		return result;
	}

	return "";
}