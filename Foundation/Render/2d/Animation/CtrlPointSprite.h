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
		/**
		*	设置图片
		*/
		void setImagePath(const std::string& filepath);
		/**
		*	设置纹理
		*/
		void setTexture(const Texture2D* texture);
	protected:
		void updatePointSprite();

		virtual void beforeDraw();

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
