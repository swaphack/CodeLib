#pragma once

#include "CtrlWidget.h"

namespace render
{
	class Texture;
}

namespace ui
{
	// 图片
	class CtrlImage : public CtrlWidget
	{
	public:
		CtrlImage();
		virtual ~CtrlImage();
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

		// 设置水平翻转
		void setFlipX(bool status);
		// 是否水平翻转
		bool isFlipX();
		// 设置垂直翻转
		void setFlipY(bool status);
		// 是否垂直翻转
		bool isFlipY();
		// 获取渲染节点
		virtual render::DrawNode2D* getRenderNode();
	protected:
		// 图片结构
		sys::ImageDefine _imageDefine;
		// 2d纹理
		render::DrawTexture2D* _texture2D = nullptr;
	};
}