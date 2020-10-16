#pragma once

#include "CtrlWidget.h"
#include "Common/Input/TouchDelegate.h"
#include "TextProtocol.h"

namespace render
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
		void setTextColor(const sys::Color3B& color);
		/**
		*	颜色
		*/
		const sys::Color3B& getTextColor() const;
		/**
		*	获取文本控件
		*/
		CtrlText* getTextControl() const;
	public:
		/**
		*	有效
		*/
		void setEnableImage(bool bEnabled);
		/**
		*	选中
		*/
		void setSelectImage(bool bSelected);
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
	protected:
		// 触摸处理
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
		// 文本
		CtrlText* _btnText = nullptr;
		// 图片
		CtrlImage* _btnImage = nullptr;
		// 点击缩放
		float _touchScale = 1.1f;
	};
}