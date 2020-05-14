#pragma once

#include "CtrlEditBox.h"
#include "TextProtocol.h"

namespace render
{
	class CtrlText;

	// �ɱ༭�ı�
	class CtrlEditLabel : public CtrlEditBox, public TextProtocol
	{
	public:
		CtrlEditLabel();
		virtual ~CtrlEditLabel();
	public:
		// �����ı�
		void setString(const std::string& text);
		// ��ȡ��ʾ�ı��ؼ�
		CtrlText* getCtrlText();
		// �����������
		virtual void onInputHand(sys::BoardKey key, sys::ButtonStatus type);
	protected:
		// ���˰�ť�¼�
		virtual void onInputKeyBackHandler();
		// �س���ť�¼�
		virtual void onInputKeyReturnHandler();
		// �����ַ��¼�
		virtual void onInputKeyCharHandler(char value);
	private:
		CtrlText* _ctrlText = nullptr;
	};
}