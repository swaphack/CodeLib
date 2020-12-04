#pragma once

#include "CtrlImage.h"

namespace render
{
	/**
	*	¾Å¹¬¸ñÍ¼Æ¬
	*/
	class CtrlScale9Image : public CtrlImage
	{
	public:
		CtrlScale9Image();
		virtual ~CtrlScale9Image();
	public:
		virtual bool init();
	public:
		/**
		*	×ó°×±ß
		*/
		void setMarginLeft(float value);
		/**
		*	ÓÒ°×±ß
		*/
		void setMarginRight(float value);
		/**
		*	¶¥°×±ß
		*/
		void setMarginTop(float value);
		/**
		*	µ×°×±ß
		*/
		void setMarginBottom(float value);
		/**
		*	°×±ß
		*/
		void setMargin(float top, float right, float bottom, float left);
		/**
		*	°×±ß
		*/
		void setMargin(const sys::CSSMargin& margin);
		/**
		*	°×±ß
		*/
		const sys::CSSMargin& getMargin() const;
	protected:
		void onScale9BodyChange();
		void onScale9ImageChange();
		virtual void updateScale9ImageMeshData();
	private:
		/**
		*	°×±ß²ÎÊý
		*/
		sys::CSSMargin _scale9Margin;
		/**
		*	¶¥µãÐÅÏ¢
		*/
		SimpleScale9Vertex _scale9Vertex;
	};
}
