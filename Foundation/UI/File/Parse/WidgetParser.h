#pragma once

#include "helper.h"
#include "IElement.h"

namespace ui
{
	// �ڵ������
	class WidgetParser : public IElement
	{
	public:
		WidgetParser();
		virtual ~WidgetParser();
	protected:
		// ��������
		virtual void parseAttributes() = 0;
		// ��������
		virtual void saveAttributes() = 0;
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