#include "XmlConfig.h"
#include "system.h"
#include <vector>
using namespace tool;

XmlHelper::XmlHelper()
{
	m_pDocument = new tinyxml2::XMLDocument();
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

tinyxml2::XMLElement* XmlHelper::getElement(const std::string& nodePath)
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