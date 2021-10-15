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
		*	����ͼƬ
		*/
		void loadImage(const std::string& path);
		/**
		*	��������
		*/
		void loadTexture(const render::Texture* texture);
		/**
		*	����������Ƭ
		*/
		void loadTextureChip(const std::string& chipName);
		/**
		*	��ȡͼƬ·��
		*/
		const std::string& getImagePath();
		/**
		*	���ó������С
		*/
		void setNativeSize();
	public:
		// ����ˮƽ��ת
		void setFlipX(bool status);
		// �Ƿ�ˮƽ��ת
		bool isFlipX();
		// ���ô�ֱ��ת
		void setFlipY(bool status);
		// �Ƿ�ֱ��ת
		bool isFlipY();
	public:
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
		*	���������
		*/
		virtual void setCamera(const render::Camera* camera);
		/**
		*	ʹ���������ͷ
		*/
		virtual void setUseDesignCamera(bool bUsed);
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
