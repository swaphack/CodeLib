#pragma once

#include "CtrlEditBox.h"
#include "TextProtocol.h"
#include "physicslib.h"

namespace render
{
	class CtrlText;
	class CtrlFrame;

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
		*	������ʾ�ı�
		*/ 
		void setPlaceholder(const std::string& text);
		/**
		*	��ʾ�ı�
		*/
		const std::string& getPlaceholder() const;
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
		*	����ռλ��ɫ
		*/
		void setPlaceholderTextColor(const phy::Color3B& color);
		/**
		*	ռλ��ɫ
		*/
		const phy::Color3B& getPlaceholderTextColor() const;
		/**
		*	�Ƿ������ʾ
		*/
		void setMultiLine(bool bMulti);
		/**
		*	�Ƿ������ʾ
		*/
		bool isMultiLine() const;
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
		CtrlFrame* _ctrlCursor = nullptr;
		// �Ƿ����
		bool _multiLine = false;
	};
}