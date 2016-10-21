#pragma once

#include "../Creater/IProtocolFile.h"

#include "../XML/tinyxml2.h"
#include <string>

using namespace std;
using namespace tinyxml2;

class CSharpProtocolID : public IProtocolFile
{
public:
	CSharpProtocolID();
	virtual ~CSharpProtocolID();
public:
	// 生成文件名称文件
	virtual const char* createFileName();
	// 加载包
	virtual bool loadPackets(XMLDocument* pDocument);
protected:
	// 创建包
	bool createProtocolID(XMLDocument* pDocument, string& text);
	// 创建字段
	bool createField(XMLNode* pXmlNode, string& text);
};