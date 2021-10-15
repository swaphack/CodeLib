#pragma once

#include "CtrlWidget.h"

namespace render
{
	class Texture;
}

namespace ui
{
	// 图片
	class CtrlImage : 
		public CtrlWidget
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
		void loadImage(const std::string& path);
		/**
		*	加载纹理
		*/
		void loadTexture(const render::Texture* texture);
		/**
		*	加载纹理碎片
		*/
		void loadTextureChip(const std::string& chipName);
		/**
		*	获取图片路径
		*/ 
		const std::string& getImagePath();
		/**
		*	设置成纹理大小
		*/  
		void setNativeSize();
	public:
		// 设置水平翻转
		void setFlipX(bool status);
		// 是否水平翻转
		bool isFlipX();
		// 设置垂直翻转
		void setFlipY(bool status);
		// 是否垂直翻转
		bool isFlipY();
	public:
		// 图片颜色
		void setImageColor(const phy::Color4B& color);
		// 图片颜色
		phy::Color4B getImageColor() const;
		// 图片混合方式
		void setImageBlend(const render::BlendParam& blend);
		// 图片混合方式
		const render::BlendParam& getImageBlend() const;
	public:
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
		/**
		*	渲染节点
		*/
		render::DrawTexture2D* getRenderNode() const;
	protected:
		// 图片结构
		sys::ImageDefine _imageDefine;
		// 2d纹理
		render::DrawTexture2D* _texture2D = nullptr;
	};
}