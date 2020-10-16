#pragma once

#include "CtrlWidget.h"
#include "Common/Input/TouchDelegate.h"
#include "TextProtocol.h"

namespace render
{
	class CtrlText;
	class CtrlImage;

	// ��ť
	class CtrlButton : 
		public CtrlWidget,
		public TextProtocol
	{
	public:
		CtrlButton();
		virtual ~CtrlButton();
	public:
		virtual bool init();
	public:
		/**
		*	�����ı�
		*/
		virtual void setString(const std::string& text);
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
		void setTextColor(const sys::Color3B& color);
		/**
		*	��ɫ
		*/
		const sys::Color3B& getTextColor() const;
		/**
		*	��ȡ�ı��ؼ�
		*/
		CtrlText* getTextControl() const;
	public:
		/**
		*	��Ч
		*/
		void setEnableImage(bool bEnabled);
		/**
		*	ѡ��
		*/
		void setSelectImage(bool bSelected);
	public:
		/**
		*	��������״̬�µ�ͼƬ
		*/
		void setNormalImage(const std::string& filepath);
		/**
		*	����״̬�µ�ͼƬ
		*/
		const std::string& getNormalImage() const;
		/**
		*	����ѡ��״̬�µ�ͼƬ
		*/
		void setSelectedImage(const std::string& filepath);
		/**
		*	ѡ��״̬�µ�ͼƬ
		*/
		const std::string& getSelectedImage() const;
		/**
		*	���ò�����״̬�µ�ͼƬ
		*/
		void setDisabledImage(const std::string& filepath);
		/**
		*	������״̬�µ�ͼƬ
		*/
		const std::string& getDisabledImage() const;
		/**
		*	��ȡͼƬ�ؼ�
		*/
		CtrlImage* getImageControl() const;
	public:
		/**
		*	�������
		*/
		void setTouchScale(float scale);
		/**
		*	�������
		*/
		float getTouchScale() const;
	protected:
		// ��������
		virtual bool onTouchBegan(float x, float y, bool include);
		virtual bool onTouchMoved(float x, float y, bool include);
		virtual bool onTouchEnded(float x, float y, bool include);
	private:
		struct ButtonImage
		{
			std::string normal;
			std::string selected;
			std::string disabled;
		};

		ButtonImage _btnImagePath;
		// �ı�
		CtrlText* _btnText = nullptr;
		// ͼƬ
		CtrlImage* _btnImage = nullptr;
		// �������
		float _touchScale = 1.1f;
	};
}