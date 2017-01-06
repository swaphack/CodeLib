#pragma once

#include "helper.h"
#include "IElement.h"

namespace ui
{
	// ���ֽ�����
	class LayoutItemParser : public IElement
	{
	public:
		LayoutItemParser();
		virtual ~LayoutItemParser();
	public:
		// ����ui�ڵ�
		void setLayoutItem(LayoutItem* item);

		// ��ȡui�ڵ�
		virtual LayoutItem* getLayoutItem() = 0;
	protected:
		// ��������
		virtual void parseAttributes() = 0;
		// ��������
		virtual void saveAttributes() = 0;
	protected:
		LayoutItem* m_pLayoutItem;
	};
}