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
		CtrlMask* getBackgroundMask() const;
	private:
		/**
		*	±≥æ∞Õº∆¨
		*/
		CtrlImage* _backgroundImage = nullptr;
		/**
		*	±≥æ∞—’…´
		*/
		CtrlMask* _backgroundMask = nullptr;
		
	};
}