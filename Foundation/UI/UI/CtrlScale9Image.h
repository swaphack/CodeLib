#pragma once

#include "CtrlImage.h"
#include <3d/Environment/Environment.h>

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
	public:
		/**
		*	设置着色器
		*/
		virtual void setTexShaderProgram(render::ShaderProgram* shaderProgram);
		/**
		*	渲染节点
		*/
		render::DrawScale9Texture2D* getRenderNode() const;
	public:
		// 图片颜色
		void setImageColor(const phy::Color4B& color);
		// 图片颜色
		phy::Color4B getImageColor() const;
		// 图片混合方式
		void setImageBlend(const render::BlendParam& blend);
		// 图片混合方式
		const render::BlendParam& getImageBlend() const;
	private:
		// 图片结构
		sys::ImageDefine _imageDefine;
		// 2d纹理
		render::DrawScale9Texture2D* _texture2D = nullptr;
	};
}
