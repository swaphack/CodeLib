#pragma once

#include "tinyxml2.h"

namespace sys
{
	// xml ����
	class XmlConfig
	{
	public:
		XmlConfig();
		~XmlConfig();
	public:
		// ����xml�ļ�
		bool loadFile(const char* filepath);
		// ��ȡ�ڵ�
		tinyxml2::XMLElement* getElement(const char* nodePath);
		// ��ȡ�ڵ������ֵ
		const char* getValue(const char* nodepath, const char* attributeName);
	private:
		tinyxml2::XMLDocument* m_pDocument;
	};
}