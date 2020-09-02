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
		*	…Ë÷√±≥æ∞—’…´
		*/
		void setBackgroundColor(const sys::Color4B& color);
		/**
		*	…Ë÷√±≥æ∞Õº∆¨
		*/
		void setBackgroundImage(const std::string& filepath);
		/**
		*	±≥æ∞Õº∆¨
		*/
		CtrlImage* getBackgroundImage() const;
		/**
		*	±≥æ∞—’…´
		*/
		Mask* getBackgroundMask() const;
	private:
		/**
		*	±≥æ∞Õº∆¨
		*/
		CtrlImage* _backgroundImage = nullptr;
		/**
		*	±≥æ∞—’…´
		*/
		Mask* _backgroundMask = nullptr;
		
	};
}