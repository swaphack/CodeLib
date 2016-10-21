#pragma once

#include "../Creater/IProtocolFile.h"

#include "../XML/tinyxml2.h"
#include <string>

using namespace std;
using namespace tinyxml2;

class CPlusProtocol : public IProtocolFile
{
public:
	CPlusProtocol();
	virtual ~CPlusProtocol();
public:
	// �����ļ������ļ�
	virtual const char* createFileName();
	// ���ذ�
	virtual bool loadPackets(XMLDocument* pDocument);
protected:
	// ������
	bool createPackets(XMLDocument* pDocument, string& text);
	// ����Э��
	bool createProtocol(XMLNode* pXmlNode, string& text);
	// �����ֶ�
	bool createField(XMLNode* pXmlNode, string& text);
protected:
private:
};