#pragma once

#include "macros.h"
#include "WidgetProperty.h"

namespace ui
{
	// �ڵ������
	class IElement
	{
	public:
		IElement();
		virtual ~IElement();
	public:
		// ���ؽڵ�
		bool load(tinyxml2::XMLElement* pXmlNode, bool clean = true);
		// ����ڵ�
		bool save(tinyxml2::XMLElement* pXmlNode, bool clean = true);
	protected:
		// ����
		WidgetProperty* getNodeProperty();
		// ��������
		virtual void parseAttributes() = 0;
		// ��������
		virtual void saveAttributes() = 0;
	private:
		// �ڵ�����
		WidgetProperty* _nodeProperty;
	};
}