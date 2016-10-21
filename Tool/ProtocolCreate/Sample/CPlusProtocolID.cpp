#include "CPlusProtocolID.h"
#include "Common.h"

CPlusProtocolID::CPlusProtocolID()
{

}

CPlusProtocolID::~CPlusProtocolID()
{

}

const char* CPlusProtocolID::createFileName()
{
	return "PacketID.h";
}

bool CPlusProtocolID::loadPackets(XMLDocument* pDocument)
{
	string text;
	if (!createProtocolID(pDocument, text))
	{
		return false;
	}

	FILE* fptr = fopen(createFileName(), "wb+");
	if (fptr == NULL)
	{
		return false;
	}

	fwrite(text.c_str(), text.size(), 1, fptr);

	fclose(fptr);

	return true;
}

bool CPlusProtocolID::createProtocolID(XMLDocument* pDocument, string& text)
{
	if (pDocument == nullptr)
	{
		return false;
	}
	XMLNode* pRoot = pDocument->FirstChildElement("root");
	if (pRoot == nullptr)
	{
		return false;
	}

	XMLElement* pElement = (XMLElement*)pRoot;
	RETURE_FALSE_IF(pElement->Attribute(PROTOCOL_NAME) == NULL, "Lost Protocol Param Field %s", PROTOCOL_NAME);
	RETURE_FALSE_IF(pElement->Attribute(PROTOCOL_DESCRIBE) == NULL, "Lost Protocol Param Field %s", PROTOCOL_DESCRIBE);

	text = "";
	text.append("#pragma once\n\n");
	text.append("// ");
	text.append(pElement->Attribute(PROTOCOL_DESCRIBE));
	text.append("\n");
	text.append("enum ");
	text.append(pElement->Attribute(PROTOCOL_NAME));
	text.append("\n");
	text.append("{\n");

	XMLNode* pNode = pRoot->FirstChild();
	if (pNode)
	{
		while (pNode != NULL)
		{
			string field;
			if (createField(pNode, field))
			{
				text.append(field);
			}
			pNode = pNode->NextSibling();
		}
	}

	text.append("};\n");

	return true;
}

bool CPlusProtocolID::createField(XMLNode* pXmlNode, string& text)
{
	if (pXmlNode == nullptr)
	{
		return false;
	}

	XMLElement* pElement = (XMLElement*)pXmlNode;
	RETURE_FALSE_IF(pElement->Attribute(PARAM_PROTOCOLID) == NULL, "Lost Protocol Param Field %s", PARAM_PROTOCOLID);
	RETURE_FALSE_IF(pElement->Attribute(PARAM_NAME) == NULL, "Lost Protocol Param Field %s", PARAM_NAME);
	RETURE_FALSE_IF(pElement->Attribute(PARAM_DESCRIBE) == NULL, "Lost Protocol Param Field %s", PARAM_DESCRIBE);

	text = "";
	text.append("\t// ");
	text.append(pElement->Attribute(PARAM_DESCRIBE));
	text.append("\n");
	text.append("\t");
	text.append(pElement->Attribute(PARAM_NAME));
	text.append(" = ");
	text.append(pElement->Attribute(PARAM_PROTOCOLID));
	text.append(",\n");

	return true;
}