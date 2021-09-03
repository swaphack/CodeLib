#pragma once

#include "CtrlWidget.h"

namespace render
{
	class Texture;
}

namespace ui
{
	// ͼƬ
	class CtrlImage : public CtrlWidget
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

		// ����ˮƽ��ת
		void setFlipX(bool status);
		// �Ƿ�ˮƽ��ת
		bool isFlipX();
		// ���ô�ֱ��ת
		void setFlipY(bool status);
		// �Ƿ�ֱ��ת
		bool isFlipY();
		// ��ȡ��Ⱦ�ڵ�
		virtual render::DrawNode2D* getRenderNode();
	protected:
		// ͼƬ�ṹ
		sys::ImageDefine _imageDefine;
		// 2d����
		render::DrawTexture2D* _texture2D = nullptr;
	};
}