#pragma once

#include "CtrlWidget.h"

namespace ui
{
	class CtrlImage;
	class CtrlMask;

	class CtrlLayout : public CtrlWidget
	{
	public:
		CtrlLayout();
		virtual ~CtrlLayout();
	public:
		virtual bool init();
		/**
		*	������ɫ��
		*/
		virtual void setTexShaderProgram(render::ShaderProgram* shaderProgram);
		/**
		*	������ɫ��
		*/
		virtual void setColorShaderProgram(render::ShaderProgram* shaderProgram);
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
		*	���ñ�����ɫ
		*/
		void setBackgroundMaskColor(const phy::Color4B& color);
		/**
		*	������ɫ
		*/
		phy::Color4B getBackgroundMaskColor() const;
		/**
		*	���ñ���ͼƬ
		*/
		void setBackgroundImagePath(const std::string& filepath);
		/**
		*	����ͼƬ
		*/
		const std::string& getBackgroundImagePath() const;
		/**
		*	����ͼƬ
		*/
		CtrlImage* getBackgroundImage() const;
		/**
		*	������ɫ
		*/
		CtrlMask* getBackgroundMask() const;
		/**
		*	���ñ���ͼƬ�Ƿ�ɼ�
		*/
		void setBackgroudImageVisible(bool bVisible);
		/**
		*	����ͼƬ�Ƿ�ɼ�
		*/
		bool isBackgroudImageVisible() const;
		/**
		*	���ñ�����ɫ�Ƿ�ɼ�
		*/
		void setBackgroudMaskVisible(bool bVisible);
		/**
		*	������ɫ�Ƿ�ɼ�
		*/
		bool isBackgroudMaskVisible() const;
	private:
		/**
		*	����ͼƬ
		*/
		CtrlImage* _backgroundImage = nullptr;
		/**
		*	������ɫ
		*/
		CtrlMask* _backgroundMask = nullptr;
		
	};
}