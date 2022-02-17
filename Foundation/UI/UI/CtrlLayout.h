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
		*	设置着色器
		*/
		virtual void setTexShaderProgram(render::ShaderProgram* shaderProgram);
		/**
		*	设置着色器
		*/
		virtual void setColorShaderProgram(render::ShaderProgram* shaderProgram);
		/**
		*	设置摄像机
		*/
		virtual void setCamera(const render::Camera* camera);
		/**
		*	使用设计摄像头
		*/
		virtual void setUseDesignCamera(bool bUsed);
	public:
		/**
		*	设置背景颜色
		*/
		void setBackgroundMaskColor(const phy::Color4B& color);
		/**
		*	背景颜色
		*/
		phy::Color4B getBackgroundMaskColor() const;
		/**
		*	设置背景图片
		*/
		void setBackgroundImagePath(const std::string& filepath);
		/**
		*	背景图片
		*/
		const std::string& getBackgroundImagePath() const;
		/**
		*	背景图片
		*/
		CtrlImage* getBackgroundImage() const;
		/**
		*	背景颜色
		*/
		CtrlMask* getBackgroundMask() const;
		/**
		*	设置背景图片是否可见
		*/
		void setBackgroudImageVisible(bool bVisible);
		/**
		*	背景图片是否可见
		*/
		bool isBackgroudImageVisible() const;
		/**
		*	设置背景颜色是否可见
		*/
		void setBackgroudMaskVisible(bool bVisible);
		/**
		*	背景颜色是否可见
		*/
		bool isBackgroudMaskVisible() const;
	private:
		/**
		*	背景图片
		*/
		CtrlImage* _backgroundImage = nullptr;
		/**
		*	背景颜色
		*/
		CtrlMask* _backgroundMask = nullptr;
		
	};
}