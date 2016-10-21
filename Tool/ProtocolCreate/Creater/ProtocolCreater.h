#pragma once

#include "../XML/tinyxml2.h"

#include <vector>

using namespace tinyxml2;
using namespace std;

class IProtocolFile;

class ProtocolCreater
{
public:
	ProtocolCreater();
	virtual ~ProtocolCreater();
public:
	// ���Э��
	void addProtocol(IProtocolFile* pProtocol);
	// �Ƴ�Э��
	void removeProtocol(IProtocolFile* pProtocol);
	// �Ƿ����Э��
	bool existsProtocol(IProtocolFile* pProtocol);
	// �������Э��
	void clearProtocols();
	// ʵ����
	void Flush(XMLDocument* pDocument);
private:
	std::vector<IProtocolFile*> m_vecProtocols;
};