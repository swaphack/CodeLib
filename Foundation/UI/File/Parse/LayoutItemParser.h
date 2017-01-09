#pragma once

#include "IElement.h"

namespace ui
{
	class LayoutItem;

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

		// �����ڵ������
		virtual const char* getName() = 0;
	protected:
		// ��������
		virtual void parseAttributes() = 0;
		// ��������
		virtual void saveAttributes() = 0;
	protected:
		LayoutItem* m_pLayoutItem;
	};
}