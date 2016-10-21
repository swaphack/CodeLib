#pragma once

#include "../XML/tinyxml2.h"

using namespace tinyxml2;

class IProtocolFile
{
public:
	virtual ~IProtocolFile() {}
public:
	// ���ذ�
	virtual bool loadPackets(XMLDocument* pDocument) = 0;
	// �����ļ������ļ�
	virtual const char* createFileName() = 0;
};