#pragma once

#include "CtrlListView.h"

namespace render
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
