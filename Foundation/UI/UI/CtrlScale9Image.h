#pragma once

#include "CtrlImage.h"

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

	private:
		// ͼƬ�ṹ
		sys::ImageDefine _imageDefine;
		// 2d����
		render::DrawScale9Texture2D* _texture2D = nullptr;
	};
}
