#pragma once

#include "LayoutItemLoader.h"

namespace ui
{
	// ���ֽڵ�
	class LayoutLoader : public LayoutItemLoader
	{
	public:
		LayoutLoader();
		virtual ~LayoutLoader();
	protected:
		// ��������
		virtual void parseAttributes();
		// ��������
		virtual void saveAttributes();
	private:
		INIT_LOADER_WIDGET(Layout, Layout);
	};
}