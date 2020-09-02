#pragma once

#include "CtrlWidget.h"

namespace render
{
	class CtrlImage;
	class Mask;

	class CtrlLayout : public CtrlWidget
	{
	public:
		CtrlLayout();
		virtual ~CtrlLayout();
	public:
		virtual bool init();

		virtual void draw();
	public:
		/**
		*	���ñ�����ɫ
		*/
		void setBackgroundColor(const sys::Color4B& color);
		/**
		*	���ñ���ͼƬ
		*/
		void setBackgroundImage(const std::string& filepath);
		/**
		*	����ͼƬ
		*/
		CtrlImage* getBackgroundImage() const;
		/**
		*	������ɫ
		*/
		Mask* getBackgroundMask() const;
	private:
		/**
		*	����ͼƬ
		*/
		CtrlImage* _backgroundImage = nullptr;
		/**
		*	������ɫ
		*/
		Mask* _backgroundMask = nullptr;
		
	};
}