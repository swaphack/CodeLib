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
		/**
		*	����ͼƬ
		*/
		void setImagePath(const std::string& filepath);
		/**
		*	��������
		*/
		void setTexture(const Texture2D* texture);
	protected:
		void updatePointSprite();

		virtual void beforeDraw();

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
