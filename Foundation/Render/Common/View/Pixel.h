#pragma once

#include "system.h"

namespace render
{
	/**
	*	���ش���
	*/
	class Pixel
	{
	public:
		Pixel();
		virtual ~Pixel();
	public:
		/**
		*	��ȡ���ػ�������
		*/
		const sys::MemoryData& getPixelData() const;
	public:
		/**
		*	����ָ��λ�õ�����
		*/ 
		void loadPointPixel(float x, float y);
		/**
		*	����ָ�����ε�����
		*/
		void loadRectPixel(float x, float y, float width, float height);
	public:
		/**
		*	��ȡָ��λ�õ�����
		*/
		static sys::Color4B readPixelColor(float x, float y);
	private:
		// ���ػ�������
		sys::MemoryData _blockData;
	};
}