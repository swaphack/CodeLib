#include "CSharpProtocol.h"
#include "Common.h"
#include <cstdio>

CSharpProtocol::CSharpProtocol()
{

}

CSharpProtocol::~CSharpProtocol()
{

}


const char* CSharpProtocol::createFileName()
{
	return "Packets.cs";
}

bool CSharpProtocol::loadPackets(XMLDocument* pDocument)
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

bool CSharpProtocol::createPackets(XMLDocument* pDocument, string& text)
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
	text.append("using System;\n");
	text.append("using System.Text;\n");
	text.append("using Foundation.Net;\n");
	text.append("using System.Runtime.InteropServices;\n");

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

bool CSharpProtocol::createProtocol(XMLNode* pXmlNode, string& text)
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
	text.append("/// <summary>\n");
	text.append("/// ");
	text.append(pElement->Attribute(PROTOCOL_DESCRIBE));
	text.append("\n");
	text.append("/// ");
	text.append(pElement->Attribute(PROTOCOL_PROTOCOLID));
	text.append("\n");
	text.append("/// </summary>\n");
	text.append("[StructLayout(LayoutKind.Sequential, CharSet=CharSet.Unicode)]\n");
	text.append("public struct ");
	text.append(pElement->Attribute(PROTOCOL_NAME));
	text.append(": IPacket\n");
	text.append("{\n");

	text.append("\t/// <summary>\n");
	text.append("\t/// Packet Header\n");
	text.append("\t/// </summary>\n");
	text.append("\tpublic PacketHeader Header { get { return PacketHeader; } set { PacketHeader = value; } }\n");
	text.append("\t/// <summary>\n");
	text.append("\t/// Packet Header\n");
	text.append("\t/// </summary>\n");
	text.append("\tpublic PacketHeader PacketHeader;\n");

	XMLNode* pParamNode = pXmlNode->FirstChild();

	string field;
	while (pParamNode != NULL)
	{
		if (createField(pParamNode, field))
		{
			text.append(field);
		}
		pParamNode = pParamNode->NextSibling();
	}

	if (createFunction(pXmlNode, field))
	{
		text.append(field);
	}

	text.append("}\n");

	return true;
}

bool CSharpProtocol::createField(XMLNode* pXmlNode, string& text)
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
	text.append("\t/// <summary>\n");
	text.append("\t/// ");
	text.append(pElement->Attribute(PROTOCOL_DESCRIBE));
	text.append("\n");
	text.append("\t/// </summary>\n");

	if (strcmp(pElement->Attribute(PARAM_TYPE), "String") == 0)
	{
		text.append("\t[MarshalAs(UnmanagedType.ByValArray, SizeConst=");
		text.append(pElement->Attribute(PARAM_LENGTH));
		text.append(")]\n");
		text.append("\tpublic byte[] ");
		text.append(pElement->Attribute(PARAM_NAME));
		text.append(";\n");
	}
	else
	{
		text.append("\tpublic");
		text.append(" ");
		text.append(pElement->Attribute(PARAM_TYPE));
		text.append(" ");
		text.append(pElement->Attribute(PARAM_NAME));
		text.append(";\n");
	}

	return true;
}

bool CSharpProtocol::createFunction(XMLNode* pXmlNode, string& text)
{
	if (pXmlNode == nullptr)
	{
		return false;
	}
	XMLElement* pElement = (XMLElement*)pXmlNode;
	text = "";
	text.append("\n\tpublic void Init()\n");
	text.append("\t{\n");
	text.append("\t\tPacketHeader.PacketID=");
	text.append(pElement->Attribute(PROTOCOL_PROTOCOLID));
	text.append(";\n");
	text.append("\t}\n");

	return true;
}
