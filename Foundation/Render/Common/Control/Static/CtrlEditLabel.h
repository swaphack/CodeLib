#pragma once

#include "CtrlEditBox.h"
#include "CtrlText.h"

namespace render
{
	// �ɱ༭�ı�
	class CtrlEditLabel : public CtrlEditBox, public TextProtocol
	{
	public:
		CtrlEditLabel();
		virtual ~CtrlEditLabel();
	public:
		// �����ı�
		virtual void setString(const char* text);
		// ��ȡ��ʾ�ı��ؼ�
		CtrlText* getCtrlText();
		// �����������
		virtual void onInputHand(sys::BoardKey key, sys::ButtonStatus type);
	protected:
	private:
		CtrlText* _ctrlText;
	};
}