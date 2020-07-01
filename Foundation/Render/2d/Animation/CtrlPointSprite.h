#pragma once

#include "CtrlAnimation.h"

namespace render
{
	class Texture2D;

	class CtrlPointSprite : public CtrlAnimation
	{
	public:
		CtrlPointSprite();
		virtual ~CtrlPointSprite();
	public:
		virtual bool init();
	public:
		/**
		*	������
		*/
		void setSpriteCount(int count);
		/**
		*	������
		*/
		int getSpriteCount() const;
		/**
		*	��С
		*/
		void setPointSize(int size);
		/**
		*	��С
		*/
		int getPointSize() const;
	protected:
		/**
		*	���µ㾫��
		*/
		void updatePointSprite();
		/**
		*	����ǰ����
		*/
		virtual void beforeDraw();
		/**
		*	���ƺ���
		*/
		virtual void afterDraw();
	private:
		/**
		*	������
		*/
		int _spriteCount = 1;
		/**
		*	��С
		*/
		int _pointSize = 1;
	};
}
