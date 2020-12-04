#pragma once

#include "CtrlImage.h"

namespace render
{
	/**
	*	�Ź���ͼƬ
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
		*	��ױ�
		*/
		void setMarginLeft(float value);
		/**
		*	�Ұױ�
		*/
		void setMarginRight(float value);
		/**
		*	���ױ�
		*/
		void setMarginTop(float value);
		/**
		*	�װױ�
		*/
		void setMarginBottom(float value);
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
	protected:
		void onScale9BodyChange();
		void onScale9ImageChange();
		virtual void updateScale9ImageMeshData();
	private:
		/**
		*	�ױ߲���
		*/
		sys::CSSMargin _scale9Margin;
		/**
		*	������Ϣ
		*/
		SimpleScale9Vertex _scale9Vertex;
	};
}
