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
		*	������
		*/
		void setSpriteCount(int count);
		/**
		*	������
		*/
		int getSpriteCount() const;
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
	};
}
