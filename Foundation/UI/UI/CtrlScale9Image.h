#pragma once

#include "CtrlImage.h"

namespace ui
{
	/**
	*	九宫格图片
	*/
	class CtrlScale9Image : public CtrlWidget
	{
	public:
		CtrlScale9Image();
		virtual ~CtrlScale9Image();
	public:
		virtual bool init();
	public:
		/**
		*	设置图片路径
		*/
		void setImagePath(const std::string& path);
		/**
		*	加载图片
		*/
		void loadImage(const std::string& path);
		/**
		*	加载纹理
		*/
		void loadTexture(const render::Texture* texture);
		/**
		*	获取图片路径
		*/
		const std::string& getImagePath();
		/**
		*	白边
		*/
		void setMargin(float top, float right, float bottom, float left);
		/**
		*	白边
		*/
		void setMargin(const sys::CSSMargin& margin);
		/**
		*	白边
		*/
		const sys::CSSMargin& getMargin() const;

	private:
		// 图片结构
		sys::ImageDefine _imageDefine;
		// 2d纹理
		render::DrawScale9Texture2D* _texture2D = nullptr;
	};
}
