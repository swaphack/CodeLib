#pragma once

#include "CtrlEditBox.h"
#include "TextProtocol.h"
#include "physicslib.h"

namespace ui
{
	class CtrlText;
	class CtrlImage;

	// �ɱ༭�ı�
	class CtrlEditText : public CtrlEditBox, public TextProtocol
	{
	public:
		CtrlEditText();
		virtual ~CtrlEditText();
	public:
		virtual bool init();
	public:
		/**
		*	�����ı�
		*/ 
		virtual void setString(const std::string& text);
		/**
		*	��ȡ��ʾ�ı��ؼ�
		*/ 
		CtrlText* getTextControl() const;
		/**
		*	�����ֿ�·��
		*/
		void setFontPath(const std::string& fonturl);
		/**
		*	��ȡ�ֿ�·��
		*/
		const std::string& getFontPath()  const;
		/**
		*	���������С
		*/
		void setFontSize(float size);
		/**
		*	��ȡ�����С
		*/
		float getFontSize()  const;
		/**
		*	������ɫ
		*/
		void setTextColor(const phy::Color3B& color);
		/**
		*	��ɫ
		*/
		const phy::Color3B& getTextColor() const;
		/**
		*	�Ƿ������ʾ
		*/
		void setMultiLine(bool bMulti);
		/**
		*	�Ƿ������ʾ
		*/
		bool isMultiLine() const;
		/**
		*	�����ı�ˮƽ���뷽ʽ
		*/
		void setTextHorizontalAlignment(sys::HorizontalAlignment alignment);
		/**
		*	��ȡ�ı�ˮƽ���뷽ʽ
		*/
		sys::HorizontalAlignment getTextHorizontalAlignment() const;
		/**
		*	�����ı���ֱ���뷽ʽ
		*/
		void setTextVerticalAlignment(sys::VerticalAlignment alignment);
		/**
		*	��ȡ�ı���ֱ���뷽ʽ
		*/
		sys::VerticalAlignment getTextVerticalAlignment() const;
	public:
		/**
		*	������ʾ�ı�
		*/
		void setPlaceholderString(const std::string& text);
		/**
		*	��ʾ�ı�
		*/
		const std::string& getPlaceholderString() const;
		/**
		*	����ռλ��ɫ
		*/
		void setPlaceholderTextColor(const phy::Color3B& color);
		/**
		*	ռλ��ɫ
		*/
		const phy::Color3B& getPlaceholderTextColor() const;
	public:
		/**
		*	�����˸���
		*/
		float getCursorFlashTime() const;
		/**
		*	�����˸���
		*/
		void setCursorFlashTime(float value);
		/**
		*	���yanse
		*/
		void setCursorColor(const phy::Color4B& color);
	public:
		// �����������
		virtual void onInputHand(sys::BoardKey key, sys::ButtonStatus type);
	protected:
		// ���˰�ť�¼�
		virtual void onInputKeyBackHandler();
		// �س���ť�¼�
		virtual void onInputKeyReturnHandler();
		// �����ַ��¼�
		virtual void onInputKeyCharHandler(char value);
	protected:
		/**
		*	��ʾ���
		*/
		void showCursor();
		/**
		*	���ع��
		*/
		void hideCursor();
	private:
		// �ı��ؼ�
		CtrlText* _ctrlText = nullptr;
		// ��ʾ�ı��ؼ�
		CtrlText* _ctrlTextPlaceholder = nullptr;
		// ���
		CtrlImage* _ctrlCursor = nullptr;
		// �Ƿ����
		bool _multiLine = false;
		// �����˸���
		float _cursorFlashTime = 0.25f;
	};
}