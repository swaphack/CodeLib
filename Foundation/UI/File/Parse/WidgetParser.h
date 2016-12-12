#pragma once

#include "macros.h"
#include "helper.h"
#include "WidgetProperty.h"
#include "IXmlLoader.h"
#include "IXmlSaver.h"

namespace ui
{
	// �ڵ������
	class WidgetParser : 
		public IXmlLoader, 
		public IXmlSaver
	{
	public:
		WidgetParser();
		virtual ~WidgetParser();
	public:
		// ���ؽڵ�
		virtual Widget* load(tinyxml2::XMLElement* pXmlNode, bool clean = true);
		// ����ڵ�
		virtual void save(tinyxml2::XMLElement* pXmlNode, bool clean = true);
	protected:
		// ����
		WidgetProperty* getNodeProperty();
		// ��������
		virtual void parseAttributes();
		// ��������
		virtual void saveAttributes();
		// ��ȡui�ڵ�
		virtual Widget* getWidget() = 0;
		// ע�����
		virtual void registerNodeParser() = 0;
	private:
		// �ڵ�����
		WidgetProperty* _nodeProperty;
		// ���Է����ı�ʱ�Ĵ���
		std::map<std::string, std::function<void>(std::string, std::string) > _onChangedHandler;
	};
}