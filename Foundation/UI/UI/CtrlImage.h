#pragma once

#include "CtrlWidget.h"

namespace render
{
	class Texture;
}

namespace ui
{
	// ͼƬ
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
		*	����ͼƬ·��
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
		// ͼƬ��ɫ
		void setImageColor(const phy::Color4B& color);
		// ͼƬ��ɫ
		phy::Color4B getImageColor() const;
		// ͼƬ��Ϸ�ʽ
		void setImageBlend(const render::BlendParam& blend);
		// ͼƬ��Ϸ�ʽ
		const render::BlendParam& getImageBlend() const;
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
		render::DrawTexture2D* getRenderNode() const;
	protected:
		// ͼƬ�ṹ
		sys::ImageDefine _imageDefine;
		// 2d����
		render::DrawTexture2D* _texture2D = nullptr;
	};
}