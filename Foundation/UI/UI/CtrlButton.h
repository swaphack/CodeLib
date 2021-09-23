#pragma once

#include "CtrlWidget.h"
#include "render.h"
#include "TextProtocol.h"
#include "physicslib.h"

namespace ui
{
	class CtrlText;
	class CtrlImage;

	// 按钮
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
		*	设置着色器
		*/
		virtual void setTexShaderProgram(render::ShaderProgram* shaderProgram);
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
		*	设置文本
		*/
		virtual void setString(const std::string& text);
		/**
		*	设置字库路径
		*/
		void setFontPath(const std::string& fonturl);
		/**
		*	获取字库路径
		*/
		const std::string& getFontPath()  const;
		/**
		*	设置字体大小
		*/
		void setFontSize(float size);
		/**
		*	获取字体大小
		*/
		float getFontSize()  const;
		/**
		*	设置颜色
		*/
		void setTextColor(const phy::Color3B& color);
		/**
		*	颜色
		*/
		const phy::Color3B& getTextColor() const;
		/**
		*	设置文本水平对齐方式
		*/
		void setTextHorizontalAlignment(sys::HorizontalAlignment alignment);
		/**
		*	获取文本水平对齐方式
		*/
		sys::HorizontalAlignment getTextHorizontalAlignment() const;
		/**
		*	设置文本垂直对齐方式
		*/
		void setTextVerticalAlignment(sys::VerticalAlignment alignment);
		/**
		*	获取文本垂直对齐方式
		*/
		sys::VerticalAlignment getTextVerticalAlignment() const;
		/**
		*	获取文本控件
		*/
		CtrlText* getTextControl() const;
	public:
		/**
		*	有效
		*/
		void setEnableState(bool bEnabled);
		/**
		*	是否有效
		*/
		bool isEnabled() const;
		/**
		*	选中
		*/
		void setSelectState(bool bSelected);
		/**
		*	是否选中
		*/
		bool isSelected() const;
	public:
		/**
		*	设置正常状态下的图片
		*/
		void setNormalImage(const std::string& filepath);
		/**
		*	正常状态下的图片
		*/
		const std::string& getNormalImage() const;
		/**
		*	设置选中状态下的图片
		*/
		void setSelectedImage(const std::string& filepath);
		/**
		*	选中状态下的图片
		*/
		const std::string& getSelectedImage() const;
		/**
		*	设置不可用状态下的图片
		*/
		void setDisabledImage(const std::string& filepath);
		/**
		*	不可用状态下的图片
		*/
		const std::string& getDisabledImage() const;
		/**
		*	获取图片控件
		*/
		CtrlImage* getImageControl() const;
	public:
		/**
		*	点击缩放
		*/
		void setTouchScale(float scale);
		/**
		*	点击缩放
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
		// 文本
		CtrlText* _btnText = nullptr;
		// 图片
		CtrlImage* _btnImage = nullptr;
		// 点击缩放
		float _touchScale = 1.1f;
		// 选中
		bool _selected = false;
		// 生效
		bool _enableButton = false;
	};
}