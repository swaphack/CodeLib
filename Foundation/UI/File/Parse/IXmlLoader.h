#pragma once

#include "macros.h"

namespace ui
{	
	// �ڵ���ؽ����ӿ�
	class IXmlLoader
	{
	public:
		virtual ~IXmlLoader() = 0;
	public:
		// ���ؽڵ�
		virtual Widget* load(tinyxml2::XMLElement* pXmlNode, bool clean = true) = 0;
	protected:
		// ��������
		virtual void parseAttributes() = 0;
	};
}