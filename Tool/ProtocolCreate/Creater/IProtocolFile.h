#pragma once

#include "../XML/tinyxml2.h"

using namespace tinyxml2;

class IProtocolFile
{
public:
	virtual ~IProtocolFile() {}
public:
	// 加载包
	virtual bool loadPackets(XMLDocument* pDocument) = 0;
	// 生成文件名称文件
	virtual const char* createFileName() = 0;
};