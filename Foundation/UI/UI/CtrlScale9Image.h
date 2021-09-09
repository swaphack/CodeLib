#pragma once

#include "CtrlImage.h"
#include <3d/Environment/Environment.h>

namespace ui
{
	/**
	*	�Ź���ͼƬ
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
		*	����ͼƬ·��
		*/
		void setImagePath(const std::string& path);
		/**
		*	����ͼƬ
		*/
		void loadImage(const std::string& path);
		/**
		*	��������
		*/
		void loadTexture(const render::Texture* texture);
		/**
		*	��ȡͼƬ·��
		*/
		const std::string& getImagePath();
		/**
		*	�ױ�
		*/
		void setMargin(float top, float right, float bottom, float left);
		/**
		*	�ױ�
		*/
		void setMargin(const sys::CSSMargin& margin);
		/**
		*	�ױ�
		*/
		const sys::CSSMargin& getMargin() const;
	public:
		/**
		*	������ɫ��
		*/
		virtual void setTexShaderProgram(render::ShaderProgram* shaderProgram);
		/**
		*	��Ⱦ�ڵ�
		*/
		render::DrawScale9Texture2D* getRenderNode() const;
	public:
		// ͼƬ��ɫ
		void setImageColor(const phy::Color4B& color);
		// ͼƬ��ɫ
		phy::Color4B getImageColor() const;
		// ͼƬ��Ϸ�ʽ
		void setImageBlend(const render::BlendParam& blend);
		// ͼƬ��Ϸ�ʽ
		const render::BlendParam& getImageBlend() const;
	private:
		// ͼƬ�ṹ
		sys::ImageDefine _imageDefine;
		// 2d����
		render::DrawScale9Texture2D* _texture2D = nullptr;
	};
}
