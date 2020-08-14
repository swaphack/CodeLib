#pragma once

#include "PrimitiveNode.h"

namespace render
{
	class Texture2D;

	class PointSprite : public PrimitiveNode
	{
	public:
		PointSprite();
		virtual ~PointSprite();
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
	};
}
