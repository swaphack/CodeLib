#pragma once

#include "CtrlListView.h"

namespace ui
{
	// �����б�
	class CtrlGridView : public CtrlListView
	{
	public:
		CtrlGridView();
		virtual ~CtrlGridView();
	public:
		virtual bool init();
	protected:
		// ��ʼ��������
		virtual void initItems();
	};
}
