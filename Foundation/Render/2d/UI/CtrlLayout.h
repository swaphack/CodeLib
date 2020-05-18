#pragma once

#include "CtrlWidget.h"

namespace render
{
	class CtrlImage;
	class CtrlMask;

	class CtrlLayout : public CtrlWidget
	{
	public:
		CtrlLayout();
		virtual ~CtrlLayout();
	public:
		virtual bool init();
	public:
		/**
		*	���ñ�����ɫ
		*/
		void setBackgroundColor(const sys::Color4B& color);
		/**
		*	���ñ���ͼƬ
		*/
		void setBackgroundImage(const std::string& filepath);
	private:
		/**
		*	����ͼƬ
		*/
		CtrlImage* _backgroundImage = nullptr;
		/**
		*	������ɫ
		*/
		CtrlMask* _backgroundMask = nullptr;
		
	};
}