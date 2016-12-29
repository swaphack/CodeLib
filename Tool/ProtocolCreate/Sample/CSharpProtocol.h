#pragma once

#include "../Creater/IProtocolFile.h"

#include "../XML/tinyxml2.h"
#include <string>

using namespace std;
using namespace tinyxml2;

class CSharpProtocol : public IProtocolFile
{
public:
	CSharpProtocol();
	virtual ~CSharpProtocol();
public:
	// 生成文件名称文件
	virtual const char* createFileName();
	// 加载包
	virtual bool loadPackets(XMLDocument* pDocument);
protected:
	// 创建包
	bool createPackets(XMLDocument* pDocument, string& text);
	// 创建协议
	bool createProtocol(XMLNode* pXmlNode, string& text);
	// 创建字段
	bool createField(XMLNode* pXmlNode, string& text);
	// 创建初始化函数
	bool createFunction(XMLNode* pXmlNode, string& text);
private:
};