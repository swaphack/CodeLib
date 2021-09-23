#pragma once

#include "CtrlWidget.h"
#include "render.h"
#include "TextProtocol.h"
#include "physicslib.h"

namespace ui
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
		/**
		*	������ɫ��
		*/
		virtual void setTexShaderProgram(render::ShaderProgram* shaderProgram);
		/**
		*	���������
		*/
		virtual void setCamera(const render::Camera* camera);
		/**
		*	ʹ���������ͷ
		*/
		virtual void setUseDesignCamera(bool bUsed);
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
		void setTextColor(const phy::Color3B& color);
		/**
		*	��ɫ
		*/
		const phy::Color3B& getTextColor() const;
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
		/**
		*	��ȡ�ı��ؼ�
		*/
		CtrlText* getTextControl() const;
	public:
		/**
		*	��Ч
		*/
		void setEnableState(bool bEnabled);
		/**
		*	�Ƿ���Ч
		*/
		bool isEnabled() const;
		/**
		*	ѡ��
		*/
		void setSelectState(bool bSelected);
		/**
		*	�Ƿ�ѡ��
		*/
		bool isSelected() const;
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
		// ѡ��
		bool _selected = false;
		// ��Ч
		bool _enableButton = false;
	};
}