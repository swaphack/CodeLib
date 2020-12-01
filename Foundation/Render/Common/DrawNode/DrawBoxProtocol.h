#pragma once

#include "physicslib.h"

namespace render
{
	class DrawBoxProtocol
	{
	public:
		DrawBoxProtocol();
		virtual ~DrawBoxProtocol();
	public:
		/**
		*	�Ƿ���ʾ���ο�
		*/
		void setBoxVisible(bool bVisible);
		/**
		*	�Ƿ���ʾ���ο�
		*/
		bool isBoxVisible() const;
		/**
		*	���þ��ο���ɫ
		*/
		void setBoxColor(const phy::Color4B& color);
		/**
		*	���ο���ɫ
		*/
		const phy::Color4B& getBoxColor() const;
		/**
		*	���ο���
		*/
		float getBoxWidth() const;
		/**
		*	���ο���
		*/
		void setBoxWidth(float width);
	protected:
		// �Ƿ���ʾ���ο�
		bool _bBoxVisible = false;
		// ���ο���ɫ
		phy::Color4B _boxColor = phy::Color4B(255, 255, 255, 255);
		// ���ο���
		float _boxWidth = 1;
	};
}