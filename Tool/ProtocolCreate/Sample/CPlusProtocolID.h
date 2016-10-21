#pragma once

#include "../Creater/IProtocolFile.h"

#include "../XML/tinyxml2.h"
#include <string>

using namespace std;
using namespace tinyxml2;

class CPlusProtocolID : public IProtocolFile
{
public:
	CPlusProtocolID();
	virtual ~CPlusProtocolID();
public:
	// �����ļ������ļ�
	virtual const char* createFileName();
	// ���ذ�
	virtual bool loadPackets(XMLDocument* pDocument);
protected:
	// ������
	bool createProtocolID(XMLDocument* pDocument, string& text);
	// �����ֶ�
	bool createField(XMLNode* pXmlNode, string& text);
};