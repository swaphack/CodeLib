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
	// 添加协议
	void addProtocol(IProtocolFile* pProtocol);
	// 移除协议
	void removeProtocol(IProtocolFile* pProtocol);
	// 是否存在协议
	bool existsProtocol(IProtocolFile* pProtocol);
	// 清空所有协议
	void clearProtocols();
	// 实例化
	void Flush(XMLDocument* pDocument);
private:
	std::vector<IProtocolFile*> m_vecProtocols;
};