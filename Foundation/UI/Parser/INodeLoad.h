#pragma once

#include "macros.h"

namespace ui
{	
	// �ڵ���ؽ����ӿ�
	class INodeLoad
	{
	public:
		virtual ~INodeLoad() = 0;
	public:
		// ���ؽڵ�
		virtual render::Node* load(tinyxml2::XMLElement* pXmlNode, bool clean = true) = 0;
	protected:
		// ��������
		virtual void parseAttributes() = 0;
	};
}