#pragma once


#include "macros.h"

namespace ui
{
	// �ڵ���ؽ����ӿ�
	class IXmlSaver
	{
	public:
		virtual ~IXmlSaver() = 0;
	public:
		// ����ڵ�
		virtual void save(tinyxml2::XMLElement* pXmlNode, bool clean = true) = 0;
	protected:
		// ��������
		virtual void saveAttributes() = 0;
	};
}