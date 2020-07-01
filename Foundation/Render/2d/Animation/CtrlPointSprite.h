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
		*	精灵数
		*/
		void setSpriteCount(int count);
		/**
		*	精灵数
		*/
		int getSpriteCount() const;
		/**
		*	大小
		*/
		void setPointSize(int size);
		/**
		*	大小
		*/
		int getPointSize() const;
	protected:
		/**
		*	更新点精灵
		*/
		void updatePointSprite();
		/**
		*	绘制前处理
		*/
		virtual void beforeDraw();
		/**
		*	绘制后处理
		*/
		virtual void afterDraw();
	private:
		/**
		*	精灵数
		*/
		int _spriteCount = 1;
		/**
		*	大小
		*/
		int _pointSize = 1;
	};
}
