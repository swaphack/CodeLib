#include "CPlusProtocol.h"
#include "Common.h"
#include <cstdio>

CPlusProtocol::CPlusProtocol()
{

}

CPlusProtocol::~CPlusProtocol()
{

}

const char* CPlusProtocol::createFileName()
{
	return "Packets.h";
}

bool CPlusProtocol::loadPackets(XMLDocument* pDocument)
{
	string text;
	if (!createPackets(pDocument, text))
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

bool CPlusProtocol::createPackets(XMLDocument* pDocument, string& text)
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
	XMLNode* pNode = pRoot->FirstChild();
	if (pNode == nullptr)
	{
		return false;
	}
	text = "";
	text.append("#pragma once\n\n");
	text.append("#include \"web.h\"\n");
	text.append("using namespace web;\n");

	while (pNode != nullptr)
	{
		string protocol;
		if (createProtocol(pNode, protocol))
		{
			text.append("\n");
			text.append(protocol);
		}
		pNode = pNode->NextSibling();
	}

	return true;
}

bool CPlusProtocol::createProtocol(XMLNode* pXmlNode, string& text)
{
	if (pXmlNode == nullptr)
	{
		return false;
	}
	XMLElement* pElement = (XMLElement*)pXmlNode;
	RETURE_FALSE_IF(pElement->Attribute(PROTOCOL_NAME) == NULL, "Lost Protocol Field %s", PROTOCOL_NAME);
	RETURE_FALSE_IF(pElement->Attribute(PROTOCOL_PROTOCOLID) == NULL, "Lost Protocol Field %s", PROTOCOL_PROTOCOLID);
	RETURE_FALSE_IF(pElement->Attribute(PROTOCOL_DESCRIBE) == NULL, "Lost Protocol Field %s", PROTOCOL_DESCRIBE);

	text = "";
	text.append("// ");
	text.append(pElement->Attribute(PROTOCOL_DESCRIBE));
	text.append("\n");
	text.append("struct ");
	text.append(pElement->Attribute(PROTOCOL_NAME));
	text.append(": public PacketHeader\n");
	text.append("{\n");

	XMLNode* pParamNode = pXmlNode->FirstChild();

	while (pParamNode != NULL)
	{
		string field;
		if (createField(pParamNode, field))
		{
			text.append(field);
		}
		pParamNode = pParamNode->NextSibling();
	}

	text.append("\n\t");
	text.append(pElement->Attribute(PROTOCOL_NAME));
	text.append("()\n\t");
	text.append("{\n");
	text.append("\t\t");
	text.append("PacketID=");
	text.append(pElement->Attribute(PROTOCOL_PROTOCOLID));
	text.append(";\n");
	text.append("\t\tLength = sizeof(*this);\n");
	text.append("\t}\n");
	text.append("};\n");

	return true;
}

bool CPlusProtocol::createField(XMLNode* pXmlNode, string& text)
{
	if (pXmlNode == nullptr)
	{
		return false;
	}
	XMLElement* pElement = (XMLElement*)pXmlNode;
	RETURE_FALSE_IF(pElement->Attribute(PARAM_NAME) == NULL, "Lost Protocol Param Field %s", PARAM_NAME);
	RETURE_FALSE_IF(pElement->Attribute(PARAM_TYPE) == NULL, "Lost Protocol Param Field %s", PARAM_TYPE);
	RETURE_FALSE_IF(pElement->Attribute(PARAM_DESCRIBE) == NULL, "Lost Protocol Param Field %s", PARAM_DESCRIBE);


	text = "";
	text.append("\t// ");
	text.append(pElement->Attribute(PROTOCOL_DESCRIBE));
	text.append("\n");

	if (strcmp(pElement->Attribute(PARAM_TYPE), "String") == 0)
	{
		text.append("\t");
		text.append("char ");
		text.append(pElement->Attribute(PARAM_NAME));
		text.append("[");
		text.append(pElement->Attribute(PARAM_LENGTH));
		text.append("];\n");
	}
	else
	{
		text.append("\t");
		text.append(pElement->Attribute(PARAM_TYPE));
		text.append(" ");
		text.append(pElement->Attribute(PARAM_NAME));
		text.append(";\n");
	}

	return true;
}
