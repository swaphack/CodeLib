#pragma once

#include "render.h"

namespace render
{
	class DrawNode;
}

namespace ui
{
	class CtrlWidget;

	// ui纹理着色器路径
	struct UIShaderPath
	{
		// 顶点着色器
		std::string vertex;
		// 片元着色器
		std::string fragment;
	};

	class UIShaderHelper
	{
	public:
		static void loadShader(CtrlWidget* node);
		/**
		*	颜色着色器
		*/
		static void loadColorShader(render::DrawNode* node);
		/**
		*	纹理着色器
		*/
		static void loadTexShader(render::DrawNode* node);
	public:
		/**
		*	设置纹理着色器路径
		*/
		static void setTexShader(const std::string& vertexShader, const std::string& fragmentShader);
		/**
		*	设置颜色着色器路径
		*/
		static void setColorShader(const std::string& vertexShader, const std::string& fragmentShader);
	private:
		// 纹理着色器路径
		static UIShaderPath _texShader;
		// 颜色着色器路径
		static UIShaderPath _colorShader;
	};
}