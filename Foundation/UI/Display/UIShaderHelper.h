#pragma once

#include "render.h"

namespace render
{
	class DrawNode;
}

namespace ui
{
	class CtrlWidget;

	// ui������ɫ��·��
	struct UIShaderPath
	{
		// ������ɫ��
		std::string vertex;
		// ƬԪ��ɫ��
		std::string fragment;
	};

	class UIShaderHelper
	{
	public:
		static void loadShader(CtrlWidget* node);
		/**
		*	��ɫ��ɫ��
		*/
		static void loadColorShader(render::DrawNode* node);
		/**
		*	������ɫ��
		*/
		static void loadTexShader(render::DrawNode* node);
	public:
		/**
		*	����������ɫ��·��
		*/
		static void setTexShader(const std::string& vertexShader, const std::string& fragmentShader);
		/**
		*	������ɫ��ɫ��·��
		*/
		static void setColorShader(const std::string& vertexShader, const std::string& fragmentShader);
	private:
		// ������ɫ��·��
		static UIShaderPath _texShader;
		// ��ɫ��ɫ��·��
		static UIShaderPath _colorShader;
	};
}